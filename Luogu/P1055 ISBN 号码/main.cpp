#include <iostream>
using namespace std;

string s;

int main() {
    cin >> s;
    int res = 0;
    int j = s.size() - 1;
    while (s[j] != '-') j--;

    for (int i = 0, p = 1; i < 12; i++) 
        if (isdigit(s[i])) res += (s[i] - '0') * p++;

    res %= 11;
    if (res == 10 && s[12] == 'X' || res == s[12] - '0') puts("Right");
    else {
        if (res == 10) s[12] = 'X';
        else s[12] = '0' + res;
        cout << s << endl;
    }

    return 0;
}