#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s, a, b;
    getline(cin, s);
    cin >> a >> b;

    stringstream ssin(s);

    while (ssin >> s)
        if (s == a) cout << b << ' ';
        else cout << s << ' ';

    return 0;
}