#include<iostream>
using namespace std;
void fun(string &s){
    s[0]='A';
    cout << s << endl;
}
int main()
{   
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int arr[5];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    fun(s);
    cout << s << endl;
}
