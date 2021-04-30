#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

const int N = 10010;
const long mod = 131;
int n;

long hs(string s) {
    long h = 0;
    for (int i = 0; i < s.size(); i++)
        h = h * 10 + s[i];

    return h;
}

int main() {
    cin >> n;

    unordered_set<long> s;
    while (n--) {
        string str;
        cin >> str;
        s.insert(hs(str));
    }

    cout << s.size() << endl;

    return 0;
}