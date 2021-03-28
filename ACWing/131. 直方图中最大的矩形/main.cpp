#include <iostream>
#include <stack>
using namespace std;

int n, h;

int main() {
    while (1) {
        cin >> n;
        if (!n) break;

        stack<pair<int, long> > stk;
        long res = 0;
        for (int i = 0; i < n; i++) {
            long x;
            cin >> x;
            while (stk.size() && stk.top().second >= x) {
                long h = stk.top().second;
                stk.pop();
                int w = i - (stk.size() ? stk.top().first : -1) - 1;
                res = max(res, h * w);
            }

            stk.push({i, x});
        }
    
        while (stk.size()) {
            long h = stk.top().second;
            stk.pop();
            int w = n - (stk.size() ? stk.top().first : -1) - 1;
            res = max(res, h * w);
        }
    
        cout << res << endl;
    }

    return 0;
}