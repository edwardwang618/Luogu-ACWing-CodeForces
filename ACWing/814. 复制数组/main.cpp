#include <iostream>
using namespace std;

const int N = 110;
int a[N], b[N];

void copy(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) b[i] = a[i];
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    copy(a, b, s);
    for (int i = 0; i < m; i++) printf("%d ", b[i]);
    puts("");
    
    return 0;
}