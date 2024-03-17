#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of number of terms : "<<endl;
    cin>>n;
    double s = 1.0;
    for (int i = 2; i <= n; i++)
    {
        if(i%2!=0){
            s += (1/pow(i,i));
        }
        else{
            s -= (1/pow(i,i));
        }
    }
    cout<<"The sum of the "<<n<<" terms of the series is: "<<s<<endl;
    return 0;
}