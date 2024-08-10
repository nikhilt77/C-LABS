#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    int n,sum=0;
    cout << "enter number:";
    cin >> n;
    int count=int(log10(n)+1);
    int temp=n;
    while(n>0){
        int rem=n%10;
        sum=sum+pow(rem,count);
        n=n/10;
    }
    if(sum==temp){
        cout << "armstrong number";
    }
    else{
        cout << "not armstrong number";
    }
}
