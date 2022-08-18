#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1010;
int n;
unordered_map<int, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int res = 0x3f3f3f3f, count = 0;
    for (auto t : mp)
        if (t.second > count) {
            count = t.second;
            res = t.first;
        } else if (t.second == count)
            res = min(res, t.first);
        
    cout << res << endl;

    return 0;
}