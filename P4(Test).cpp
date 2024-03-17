#include <iostream>
using namespace std;

int length(const char *str)
{
    const char *ptr = str;
    while (*ptr != '\0')
    {
        ptr++;
    }
    return ptr - str;
}

void showaddress(char *str)
{
    char *ptr = str;
    cout << "Address of each character in the string : " << endl;
    while (*ptr != '\0')
    {
        cout << "Character : " << *ptr << " -  Address : " << static_cast<const void *>(ptr) << endl;
        ptr++;
    }
}

bool compare(char *str1, char *str2)
{
    int l1 = 0, l2 = 0;
    while (str1[l1] != '\0')
        l1++;
    while (str2[l2] != '\0')
        l2++;
    if (l1 != l2)
        return false;
    for (int i = 0; i < l1; i++)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

void converttoupper(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void concatenate(char r[], const char str1[], const char str2[])
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        r[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
    {
        r[i + j] = str2[j];
        j++;
    }
}

void reverse(char rev[], const char str[])
{
    int l = length(str);
    int i, j = 0;
    for (i = l - 1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }
    rev[j] = '\0';
}

void insertstring(char str[], char str_insert[], int pos)
{
    int l = 0;
    while (str[l] != '\0')
        l++;
    int l1 = 0;
    while (str_insert[l1] != '\0')
        l1++;
    for (int i = l; i >= pos; i--)
    {
        str[i + l1] = str[i];
    }
    for (int i = 0; i < l1; i++)
    {
        str[i + pos] = str_insert[i];
    }
}

int main()
{
    char str[100];
    char str2[100];
    char r[100];
    char rev[100];
    cout << "Enter a string : ";
    cin.getline(str, 100);
    int l = length(str);
    cout << "The length of entered string is : " << l << endl;
    showaddress(str);
    cout << "Reversing the entered string..." << endl;
    reverse(rev, str);
    cout << "The reversed string is : " << rev << endl;
    cout << "Enter second string : ";
    cin.getline(str2, 100);
    cout << "Concatenating the entered strings..." << endl;
    concatenate(r, str, str2);
    cout << "After concatenating.... - " << r << endl;
    cout << "Comparing strings...." << endl;
    if (compare(str, str2))
        cout << "The strings are equal." << endl;
    else
        cout << "The strings are not equal." << endl;
    cout << "Inserting string in first string..." << endl;
    char str_insert[100];
    int pos;
    cout << "Enter the string to insert: " << endl;
    cin.getline(str_insert, 100);
    cout << "Enter the position to insert the string (0 - " << length(str) << ") : " << endl;
    cin >> pos;
    insertstring(str, str_insert, pos);
    cout << "String after insertion : " << str << endl;
    cout << "Original string: " << str << endl;
    converttoupper(str);
    cout << "String after converting to uppercase : " << str << endl;
    return 0;
}