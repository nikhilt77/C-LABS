#include <iostream>
using namespace std;

class Solution {
public:
    int minJumps(int arr[], int n) {
        if (n <= 1) {
            return 0;
        }
        if (arr[0] == 0) {
            return -1;
        }
        int farthest = 0;
        int end = 0;
        int jumps = 0;
        for (int i = 0; i < n; i++) {
            farthest = (i + arr[i] > farthest) ? i + arr[i] : farthest;
            if (i == end) {
                jumps++;
                end = farthest;
                if (end >= n - 1) {
                    return jumps;
                }
            }
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution ob;
    int result = ob.minJumps(arr, n);
    if (result != -1) {
        cout << "Minimum number of jumps to reach the end is " << result << endl;
    } else {
        cout << "Cannot reach the end of the array" << endl;
    }

    return 0;
}
