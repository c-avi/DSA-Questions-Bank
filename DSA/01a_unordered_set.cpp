// Include the header file
#include <unordered_set>
#include <iostream>
using namespace std;

// function prototype for display unordered_set
void display_unordered_set(const unordered_set<string>&);

int main() {

    // CREATE an unorderde set : unordered_set<data_type> ust
    unordered_set<int> ust_integers;
    unordered_set<string> countries;
    unordered_set<string> languages{"c++", "Python", "Java", "PHP"};
    unordered_set<int> primes{2, 3, 5, 7, 11, 13};
    unordered_set<int> numbers{1, 100, 10, 70, 100};

    // INTIALIZE an unordered_set
    // unordered_set<int> ust_integers = {1, 100, 2, 9}; // Initializer list with redeclaration
    // Uniform initialization
    unordered_set<int> ust_integers2 {1, 100, 2, 9};

    // INSERT 'Nepal' into countries
    countries.insert("Nepal");
    countries.insert({"India", "USA", "Korea"}); // insert multiple elements

    // loop across the unordered_set
    // DISPLAY the values
    // cout << "Integers = ";

    // cout << "Countries: ";
    // for (auto& country : countries) {
    //     cout << country << ", ";
    // }

    // for (auto& num : ust_integers2) {
    //     cout << num << ", ";
    // }

    // display initial unordered_set
    cout << "Initial unordered_set: ";
    display_unordered_set(languages);

       
    // REMOVE elements from an unordered_set
    languages.erase("Python");// remove element with value python
    cout << "\n\nFinal unorederd_set: ";
    display_unordered_set(languages);

    // Check if a value exsists in an unordered_set>
    // find() : returns the iterator to the element if the value is found, else returns the end iterator
    // count(): returns 1 if the value exsists else 0
    cout << "\nusing find(): ";
    cout << "\nDoes number " << 12 << " exist: ";
    if (primes.find(12) != primes.end()) {
        cout << "Yes";
    } else{
        cout << "No";
    }

    cout << "\nusing count: ";
    cout << "\nDoes number " << 7 << "exist: ";
    if (primes.count(7)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    // GET THE SIZE OF UNORDERED SET
    // This gives total of number of distinct elements
    cout << "\nsize of numbers: " << numbers.size();
    return 0;
}

// utility function to display unordered_set elements
void display_unordered_set(const unordered_set<string>& ust) {
    for (const auto& value : ust) {
        cout << value <<", ";
    }
}

