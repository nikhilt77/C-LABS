#include <iostream>
using namespace std;

void numberCrown(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        int space = 2 * (n - i);
        for(int j = 0; j < space; j++) {
            cout << "  ";
        }
        for(int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    numberCrown(n);
    return 0;
}
