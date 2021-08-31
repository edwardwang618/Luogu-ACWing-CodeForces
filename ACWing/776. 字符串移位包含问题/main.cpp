#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    if (s.size() < t.size()) swap(s, t);
    s += s;
    if (s.find(t) != -1) puts("true");
    else puts("false");
    return 0;
}