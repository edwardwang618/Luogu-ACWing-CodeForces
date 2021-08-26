#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        int sum = 0;
        for (int i = x + 1; i < y; i++) if (i % 2) sum += i;
        cout << sum << endl;
    }
    return 0;
}