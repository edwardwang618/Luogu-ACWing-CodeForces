#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
using PII = pair<int, int>;
int n;
priority_queue<PII, vector<PII>, greater<PII>> heap;
vector<pair<int, int>> a;

int main() {
    while (cin >> n) {
        heap = priority_queue<PII, vector<PII>, greater<PII>>();
        a.clear();

        for (int i = 0; i < n; i++) {
            int v, d;
            scanf("%d%d", &v, &d);
            a.push_back({d, v});
        }

        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            int d = a[i].first, v = a[i].second;
            if (d > heap.size()) heap.push({v, d});
            else if (v > heap.top().first) {
                heap.pop();
                heap.push({v, d});
            }
        }

        int res = 0;
        while (heap.size()) {
            res += heap.top().first;
            heap.pop();
        }

        printf("%d\n", res);
    }

    return 0;
}