#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (10 <= x && x <= 20) cnt++;
    }

    printf("%d in\n%d out\n", cnt, n - cnt);

    return 0;
}