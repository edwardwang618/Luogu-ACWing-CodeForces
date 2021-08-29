#include <iostream>
#include <queue>
using namespace std;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (dq.size() && dq.front().first < i - m) dq.pop_front();
        
        if (dq.size()) printf("%d\n", dq.front().second);
        else puts("0");

        while (dq.size() && dq.back().second >= x) dq.pop_back();
        dq.push_back({i, x});
    }

    return 0;
}