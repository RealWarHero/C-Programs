#include <iostream>
#include <cctype>
using namespace std;

int main() {
  char str[100];
  int count[26] = {0}; 
  cout<<"Enter a string : ";
  cin.getline(str,100);

  for (int i = 0; str[i] != '\0'; i++) {
    char ch = tolower(str[i]); 
    if (isalpha(ch)) {
      count[ch - 'a']++; 
    }
  }
  cout<<"Occurrences of each letter in the entered string:\n";
  for (int i = 0; i < 26; i++) {
    char ch = 'a' + i;
    if (count[i] > 0) {
      cout<<ch<<" : "<<count[i]<<"\n";
    }
  }
  return 0;
}