#include<bits/stdc++.h> 
using namespace std;

class Solution{
public:
    int evenlyDivides(int N){
        int count = 0;
        int temp = N;
        while(N > 0){
            int x = N % 10;
            if(x != 0 && temp % x == 0){
                count++;
            }
            N = N / 10;
        }
        return count;
    }
};

int main() 
{ 
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
