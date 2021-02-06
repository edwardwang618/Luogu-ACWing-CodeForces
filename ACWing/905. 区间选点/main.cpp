#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    bool operator<(const Range &W) const {
        return r < W.r;
    }
}range[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n);

    int res = 0, end = -2e9;
    for (int i = 0; i < n; i ++ )
        if (end < range[i].l) {
            res ++ ;
            end = range[i].r;
        }

    printf("%d\n", res);

    return 0;
}