#include <iostream>
using namespace std;

void alphaHill(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        char ch = 'A';
        int bp = (2 * i + 1) / 2;
        for(int j = 0; j < 2 * i + 1; j++) {
            cout << ch;
            if(j < bp) {
                ch++;
            } else {
                ch--;
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    alphaHill(n);
    return 0;
}
