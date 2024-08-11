
#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    long long sumOfDivisors(int n)
    {
        long  sum=0;
        // Write Your Code here
        for(int i=1;i<=n;i++){
            sum+=(n/i)*i;
        }
        return sum;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
