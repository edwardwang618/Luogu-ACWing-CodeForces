#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], hold[N], sell[N], cool[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    hold[0] = sell[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        hold[i] = max(hold[i - 1], cool[i - 1] - a[i]);
        sell[i] = hold[i - 1] + a[i];
        cool[i] = max(cool[i - 1], sell[i - 1]);
    }

    cout << max(sell[n], cool[n]) << endl;

    return 0;
}