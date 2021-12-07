#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    vector<int> res;

    int T;
    scanf("%d", &T);
    while (T--) {
        minheap = priority_queue<int, vector<int>, greater<int>>();
        maxheap = priority_queue<int>();
        res.clear();

        int ca, n;
        scanf("%d%d", &ca, &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            if (maxheap.empty() || x <= maxheap.top()) maxheap.push(x);
            else minheap.push(x);

            if (minheap.size() > maxheap.size()) {
                x = minheap.top(); minheap.pop();
                maxheap.push(x);
            } else if (minheap.size() + 2 <= maxheap.size()) {
                x = maxheap.top(); maxheap.pop();
                minheap.push(x);
            }

            if (i & 1) res.push_back(maxheap.top());
        }

        printf("%d %d\n", ca, res.size());
        for (int i = 0; i < res.size(); i++) {
            printf("%d ", res[i]);
            if (i % 10 == 9 && i + 1 < res.size()) puts("");
        }

        puts("");
    }
    
    return 0;
}