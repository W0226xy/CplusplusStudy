#include <iostream>
using namespace std;
#include "HashTable.h"
#include "my_unordered_map.h"
#include "my_unordered_set.h"

int main() {
    // open_address::TestHash1();
    // cout << "-----" << endl;
    // open_address::TestHash2();
    // hash_bucket::TestHash1();
    wxy::test_unordered_map();
    cout<<endl;
    wxy::test_unordered_set();
    return 0;
}