#include <iostream>
using namespace std;

const int N = 110;
string s;
int ne[N];

void build_next() {
    for (int i = 0, j = ne[0] = -1; i <= s.size(); ) {
        if (j == -1 || s[i] == s[j]) ne[++i] = ++j;
        else j = ne[j];
    }
}

int main() {
    while (cin >> s, s != ".") {
        build_next();
        int n = s.size(), len = ne[n];
        if (n % (n - len) == 0) printf("%d\n", n / (n - len));
        else puts("1");
    }

    return 0;
}