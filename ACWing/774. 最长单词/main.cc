#include <iostream>
using namespace std;

int main() {
    char ch;
    int len = 0, m_len = 0;
    string s, res;
    while (scanf("%c", &ch), ch != '.') {
        if (ch == ' ') {
            if (len > m_len) res = s, m_len = len;
            s = "", len = 0;
        } else {
            s += ch;
            len++;
        }
    }

    if (len > m_len) res = s;
    puts(res.c_str());

    return 0;
}