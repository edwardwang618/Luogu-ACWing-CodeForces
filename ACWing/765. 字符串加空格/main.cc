#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (char c : s) printf("%c", c);
    return 0;
}