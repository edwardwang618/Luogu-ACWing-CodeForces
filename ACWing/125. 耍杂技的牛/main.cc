#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50010;
pair<int, int> a[N];

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first + p1.second < p2.first + p2.second;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a, a + n, compare);

    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, sum - a[i].second);
        sum += a[i].first;
    }

    cout << res << endl;

    return 0;
}