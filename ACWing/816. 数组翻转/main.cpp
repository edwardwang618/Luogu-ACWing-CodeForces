#include <iostream>
using namespace std;

int a[1010];

void reverse(int a[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) swap(a[i], a[j]);
}

int main() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];

    reverse(a, s);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}