#include <iostream>
using namespace std;

int n, res, cnt, last;

int main() {
    cin >> n;
    last = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > last) cnt++;
        else cnt = 1;
        
        last = x;
        res = max(res, cnt);
    }

    printf("%d\n", res);

    return 0;
}