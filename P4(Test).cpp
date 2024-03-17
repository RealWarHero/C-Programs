#include <iostream>
using namespace std;

void copystring(char s[], char dest[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        i++;
    }
}

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
    char s1[100];
    char s2[100];
    char str2[100];
    int ch;
    copystring(str, s1);
    copystring(str, s2);
    int l = length(str);
    cout << "Enter a string : ";
    cin.getline(str, 100);
    cout << "Enter second string : ";
    cin.getline(str2, 100);
    do
    {
        cout << "\n********Menu:********\n";
        cout << "1.Show address of each character of String\n";
        cout << "2.Concatenate\n";
        cout << "3.Compare\n";
        cout << "4.Length of string(using pointers)\n";
        cout << "5.Convert lowercase to upper\n";
        cout << "6.Reverse the string\n";
        cout << "7.Insert a string in another string at a user specified position\n";
        cout << "8.Exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nShowing memory address of each character of entered string....\n";
            showaddress(str);
            break;
        case 2:
            char r[100];
            cout << "\nConcatenating two strings....\n";
            concatenate(r, str, str2);
            cout << "After concatenating.... - " << r << endl;
            break;
        case 3:
            cout << "\nComparing strings...." << endl;
            if (compare(str, str2))
                cout << "The strings are equal." << endl;
            else
                cout << "The strings are not equal." << endl;
            break;
        case 4:
            cout << "\nThe length of first string(using pointers) is : " << length(str);
            break;
        case 5:
            cout << "\nConverting to uppercase...";
            cout << "\nOriginal string: \n"<< str;
            converttoupper(str);
            cout << "String after converting to uppercase : " << str << endl;
            break;
        case 6:
            char rev[100];
            cout << "\nReversing the entered string..." << endl;
            reverse(rev, s1);
            cout << "The reversed string is : " << rev << endl;
            break;
        case 7:
            cout << "\nInserting string in first string...\n";
            char str_insert[100];
            int pos;
            cout << "Enter the string to insert : \n";
            cin.ignore();
            cin.getline(str_insert, 100);
            cout << "Enter the position to insert the string (0 - " << length(str) << ") : \n";
            cin.ignore();
            cin >> pos;
            insertstring(str, str_insert, pos);
            cout << "String after insertion : " << str << endl;
            break;
        case 8:
            cout << "\nExiting program....\n";
            break;
        default:
            cout << "\nInvalid choice...Please enter a valid option.\n";
        }
    } while (ch != 3);
    return 0;
}