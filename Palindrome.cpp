#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        long temp = x;
        long rev = 0;
        while (x != 0) {
            long n = x % 10;
            rev = rev * 10 + n;
            x /= 10;
        }
        
        return rev == temp;
    }
};

int main() {
    Solution solution;
    int x;

    cout << "Enter an integer: ";
    cin >> x;

    bool result = solution.isPalindrome(x);
    if (result) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }

    return 0;
}
