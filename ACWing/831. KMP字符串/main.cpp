#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, p;
int n, m;
vector<int> res;

int* buildNext(string p) {
    int* N = new int[p.size()];
    int t = N[0] = -1;
    for (int j = 0; j < p.size() - 1;) 
        if (t < 0 || p[j] == p[t]) N[++j] = ++t;
        else t = N[t];
    return N;
}

void kmp(string s, string p) {
    int* next = buildNext(p);
    for (int i = 0, j = 0; i < s.size() && j < p.size(); ) {
        if (j == -1 || s[i] == p[j]) i++, j++;
        else j = next[j];

        if (j == p.size()) {
            res.push_back(j);
            j = -1;
        }
    }
}

int main() {
    cin >> n;
    cin >> p;
    cin >> m;
    cin >> s;

    kmp(s, p);

    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';

    return 0;
}