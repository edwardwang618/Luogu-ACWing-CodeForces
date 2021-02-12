#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int lowbit(int x) {
    return x & -x;
}

int count1(int x) {
    int res = 0;
    while (x) {
        x -= lowbit(x);
        res++;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) cout << count1(a[i]) << ' ';

    return 0;
}