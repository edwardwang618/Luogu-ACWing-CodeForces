#include <iostream>
#include <vector>
using namespace std;

vector<int> buildNe(string p) {
    int m = p.size();
    vector<int> ne = vector<int>(m + 1, 0);
    for (int i = 0, j = ne[0] = -1; i < m; )
        if (j == -1 || p[i] == p[j]) ne[++i] = ++j;
        else j = ne[j];

    return ne;
}

int main() {
    string s, p;
    cin >> s >> p;

    auto ne = buildNe(p);
    for (int i = 0, j = 0; i < s.size(); ) {
        if (j == -1 || s[i] == p[j]) i++, j++;
        else j = ne[j];

        if (j == p.size()) {
            printf("%d\n", i - j + 1);
            i--;
            j = ne[--j];
        }
    }

    for (int i = 1; i <= p.size(); i++) printf("%d ", ne[i]);

    return 0;
}