#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i)
        printf("%c", s[i] + s[(i + 1) % s.size()]);
        
    return 0;
}