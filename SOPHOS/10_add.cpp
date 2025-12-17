#include <bits/stdc++.h>
using namespace std;

template<typename T>
string to_string_custom(T val) {
    if constexpr (is_same_v<T, string>) {
        return val;
    } else if constexpr(is_same_v<T, const char*>) {
        return string(val);
    } else {
        return to_string(val);
    }
}

template<typename T1, typename T2>
string universalAdd(T1 a, T2 b) {
    try {
        return to_string_custom(a) + to_string_custom(b);
    } catch(...) {
        return "Error: Incompatible types";
    }
}

template <typename T>
T add(T a, T b) {
    return a + b;
}

string add(string a, string b) {
    return a + b;
}

int main() {
    cout << "Int: " << add(10, 20) << "\n";
    
    cout << "Float: " << add(10.5f, 2.5f) << "\n";
    
    cout << "String: " << add(string("Hello "), string("World")) << "\n";
    
    cout << "Mixed: " << universalAdd("Result is : ", 100) << "\n";
    cout << "Mixed Float: " << universalAdd(50.5, " is the score") << "\n";
    
    return 0;
}