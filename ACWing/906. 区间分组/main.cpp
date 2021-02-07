#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    bool operator<(const Range &W) const {
        return l < W.l;
    }
} range[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n);
    priority_queue<int, vector<int>, greater<int> > min_heap;

    for (int i = 0; i < n; i ++ ) {
        if (!min_heap.empty() && range[i].l > min_heap.top()) 
            min_heap.pop();
            
        min_heap.push(range[i].r);
    }

    printf("%d\n", min_heap.size());

    return 0;
}