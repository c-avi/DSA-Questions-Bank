/*🔺 Pyramid Pattern Example:
For n = 5, the output is:

markdown
Copy
Edit
    *    
   ***   
  *****  
 ******* 
********* 
endl
*/

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        // Print spaces
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }

        // Print stars
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "*";
        }

        // New line after each row
        cout <<"\n";
    }
    return 0;
}