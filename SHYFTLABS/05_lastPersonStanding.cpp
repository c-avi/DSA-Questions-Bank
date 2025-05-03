#include <iostream>
#include <list>
using namespace std;

int lastPersonStanding(int n) {
    list<int> people;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }
    auto it = people.begin();
    while (people.size() > 1) {
        // Move to the person with the sword
        if (it == people.end()) it = people.begin();

        // Move to the next person to kill
        auto kill = next(it);
        if (kill == people.end()) kill = people.begin();

        // Eliminate the person
        kill = people.erase(kill);

        // Move sword to next person (after the killed one)
        if (kill == people.end()) it = people.begin();
        else it = kill;
    }
    return people.front();
}

int main() {
    int n = 5;
    cout << "Last person standing: " << lastPersonStanding(n) << "\n";
    return 0; 
}