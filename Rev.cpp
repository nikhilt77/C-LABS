#include <iostream>
#include <climits>  

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int n = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && n > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && n < -8)) {
                return 0;
            }
            rev = rev * 10 + n;
        }
        return rev;
    }
};

int main() {
    Solution solution;
    int x;

    cout << "Enter an integer: ";
    cin >> x;

    int reversed = solution.reverse(x);
    cout << "Reverse of " << x << " is " << reversed << endl;

    return 0;
}
