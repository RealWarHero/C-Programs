#include <iostream>
using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
int main(){
    int n1 , n2;
    cout<<"Enter the first number : ";
    cin>>n1;
    cout<<"Enter the second number : ";
    cin>>n2;
    cout<<"The GCD of the entered numbers is: "<<gcd(n1,n2)<<endl;
    return 0;
}