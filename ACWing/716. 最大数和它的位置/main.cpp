#include <iostream>
using namespace std;

int main() {
    int idx = -1, res = 0;
    for (int i = 1; i <= 100; i++) {
        int x;
        cin >> x;
        if (x > res) {
            res = x;
            idx = i;
        }
    }

    cout << res << endl << idx << endl;

    return 0;
}