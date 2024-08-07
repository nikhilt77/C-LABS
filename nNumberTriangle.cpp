#include<iostream>
using namespace std;
void nNumberTriangle(int n) {
    // Write your code here.
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}
int main(){
  int n;
  cout << "Enter n:";
  cin >> n;
  nNumberTriangle(n);
}
