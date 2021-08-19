#include <iostream>
using namespace std;

int main() {
    int n, res = 0x3f3f3f3f;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        int num, p;
        cin >> num >> p;
        res = min(res, ((n - 1) / num + 1) * p);
    }

    cout << res << endl;

    return 0;
}