#include <iostream>
using namespace std;

void print(int a[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", a[i]);
}

int main() {
    int a[1010];
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    print(a, s);

    return 0;
}