#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream f1("input.txt");
    ofstream f2("output.txt");
    char c;
    while (f1.get(c)) { 
        if (!isspace(c)) { 
            f2.put(c); 
        }
    }
    f1.close();
    f2.close();
    cout << "File copied successfully after removing spaces.";
    return 0;
}