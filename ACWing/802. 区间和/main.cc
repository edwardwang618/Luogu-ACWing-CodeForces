#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int m = l + (r - l >> 1);
        if (alls[m] >= x) r = m;
        else l = m + 1;
    }

    return l;
}

int unique(vector<int>& A) {
    int idx = 0;
    for (int i = 0; i < A.size(); i++) {
        if (idx == 0 || A[i] != A[idx - 1]) A[idx++] = A[i];
    }
    
    return idx;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(alls.begin() + unique(alls), alls.end());

    for (auto item : add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 0; i < alls.size(); i++) s[i + 1] = s[i] + a[i];

    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r + 1] - s[l] << endl;
    }

    return 0;
}