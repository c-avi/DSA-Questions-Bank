#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){

    // Creating an empty set
    set <int> s1;

    // 1. Creating a set of integers from an initializer list
    set<int> s2 = {5, 1, 3, 2, 4};

    // 2. Inserting elements one by one
    set<int> s;
    s.insert(11); // Inserting single element
    s.insert(9);
    s.insert(7);
    s.insert(45);

    // 3. Initialize a set using another set
    set<int> s3 = {11, 9, 7, 45};
    set<int> s4 = s3;

    // 4. Intialising a set from array
    int arr[] = {11, 9, 7, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    set<int>s5(arr, arr + n); // set<type> s(first, last) 

    // INSERTION

    // Insert element near the given position
    // st.insert(pos, val)
    set<int> st = {34, 67, 12};

    auto it = st.begin();

    // Insert element 1 at starting position
    st.insert(it, 1);

    // Insert multiple elements
    // st.insert({val1, val2,...})
    set<int> st1;
    st1.insert({12, 45, 11, 78, 9});

    // Insert multiple elements from a range
    // st.insert(first, last), last points to pos just after last element
    vector<int> vec = {12, 45, 11, 67, 9};

    // Define the range as whole vector
    auto first = vec.begin();
    auto last = vec.end();

    // Insert elements of defined range
    set<int> st2(first, last);

    for (auto i : st2)
        cout << i << " ";

    return 0;
}