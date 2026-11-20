#pragma once

#include <atomic>
#include <cstddef>
#include <utility>

namespace wxy
{
    template<class T>
    class shared_ptr
    {
    public:
        // 构造：接管 ptr 指向的资源
        explicit shared_ptr(T* ptr = nullptr)
            : _ptr(ptr)
            , _pcount(nullptr)
        {
            if (_ptr != nullptr)
            {
                try
                {
                    _pcount = new std::atomic<std::size_t>(1);
                }
                catch (...)
                {
                    // 控制块申请失败时，不能泄漏已经传入的资源
                    delete _ptr;
                    _ptr = nullptr;
                    throw;
                }
            }
        }

        // 拷贝构造：共享资源，引用计数 +1
        shared_ptr(const shared_ptr& sp)
            : _ptr(sp._ptr)
            , _pcount(sp._pcount)
        {
            if (_pcount != nullptr)
            {
                _pcount->fetch_add(1);
            }
        }

        // 移动构造：直接转移管理权，不增加引用计数
        shared_ptr(shared_ptr&& sp) noexcept
            : _ptr(sp._ptr)
            , _pcount(sp._pcount)
        {
            sp._ptr = nullptr;
            sp._pcount = nullptr;
        }

        // 赋值：值传递，既兼容拷贝赋值，也兼容移动赋值
        shared_ptr& operator=(shared_ptr sp) noexcept
        {
            swap(sp);
            return *this;
        }

        // 析构：引用计数 -1；最后一个拥有者释放资源
        ~shared_ptr()
        {
            release();
        }

        void reset(T* ptr = nullptr)
        {
            shared_ptr temp(ptr);
            swap(temp);
        }

        void swap(shared_ptr& sp) noexcept
        {
            std::swap(_ptr, sp._ptr);
            std::swap(_pcount, sp._pcount);
        }

        std::size_t use_count() const noexcept
        {
            return _pcount == nullptr ? 0 : _pcount->load();
        }

        T* get() const noexcept
        {
            return _ptr;
        }

        explicit operator bool() const noexcept
        {
            return _ptr != nullptr;
        }

        T& operator*() const
        {
            return *_ptr;
        }

        T* operator->() const noexcept
        {
            return _ptr;
        }

    private:
        void release() noexcept
        {
            if (_pcount != nullptr)
            {
                // 减之前为 1，说明当前对象是最后一个拥有者
                if (_pcount->fetch_sub(1) == 1)
                {
                    delete _ptr;
                    delete _pcount;
                }

                _ptr = nullptr;
                _pcount = nullptr;
            }
        }

    private:
        T* _ptr;
        std::atomic<std::size_t>* _pcount;//将计数改成原子类型,是为了让多个线程同时修改引用计数时不发生竞争，避免“计数错误”或“双重释放”。
    };
}