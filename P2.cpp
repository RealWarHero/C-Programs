#include <iostream>
using namespace std;

void removeduplicates(int arr[], int& size){
    int newsize = 0;
    for (int i = 0; i < size; i++)
    {
        bool check = false;
        for (int j = 0; j < newsize; j++)
        {
            if(arr[i]==arr[j]){
                check = true;
                break;
            }
        }
        if(!check){
            arr[newsize++] = arr[i];
        }
    }
    size = newsize;
}

void display(int arr[], int s){
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[100];
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    cout<<"Enter the elements of the array....."<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"Array before removing duplicates: ";
    display(arr,size);
    removeduplicates(arr,size);
    cout<<"Array after removing duplicates: ";
    display(arr,size);
    return 0;
 }
