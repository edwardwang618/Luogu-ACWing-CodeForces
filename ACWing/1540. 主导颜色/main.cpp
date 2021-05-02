#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
unordered_map<int, int> mp;

int main() {
    cin >> n >> m;

    int res = 0;
    for (int i = 1; i <= m * n; i++) {
        int a;
        cin >> a;
        mp[a]++;
        if (mp[a] > n * m / 2) {
            res = a;
            break;
        }
    }

    cout << res << endl;

    return 0;
}