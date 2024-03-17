#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int elem)
{
    int l = 0, r = size - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (arr[m] == elem)
            return m;
        if (arr[m] < elem)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main()
{
    int arr[100];
    int size, elem;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements for the array...." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Enter the element to be searched: " << endl;
    cin >> elem;
    int result = binarysearch(arr, size, elem);
    if (result != -1)
        cout << "Element " << elem << " found at index " << result << endl;
    else
        cout << "Element " << elem << " not found in the array :( " << endl;
    return 0;
}