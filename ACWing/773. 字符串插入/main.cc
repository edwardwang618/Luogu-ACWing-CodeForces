#include <iostream>
using namespace std;

int main() {
    string s, p;
    while (cin >> s >> p) {
        char ch = 0;
        int idx = 0;
        for (int i = 0; i < s.size(); i++) 
            if (s[i] > ch) ch = s[i], idx = i;
        
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
            if (i == idx) cout << p;
        }

        puts("");
    }

    return 0;
}