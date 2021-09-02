#include <iostream>
using namespace std;

int sum(int l, int r) {
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    int l, r;
    cin >> l >> r;
    cout << sum(l, r) << endl;

    return 0;
}