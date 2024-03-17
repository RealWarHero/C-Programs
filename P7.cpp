#include <iostream>
using namespace std;

int main(){
    int n1 , n2;
    cout<<"Enter the first number : ";
    cin>>n1;
    cout<<"Enter the second number : ";
    cin>>n2;
    while(n2!=0){
        int t = n2;
        n2 = n1%n2;
        n1 = t;
    }
    cout<<"The GCD of the entered numbers is: "<<n1<<endl;
    return 0;
}