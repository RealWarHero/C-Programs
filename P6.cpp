#include <iostream>
using namespace std;

int main(){
    int arr[100];
    int n , elem , pos;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements for the array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: "<<endl;
    cin>>elem;
    bool r = false;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==elem){
            r = true;
            pos = i;
        }
    }
    if(r){
        cout<<elem<<" is found in the array at "<<pos+1<<"th position"<<endl;
    }
    else{
        cout<<elem<<" is not found in the array :( "<<endl;
    }
    return 0;
}