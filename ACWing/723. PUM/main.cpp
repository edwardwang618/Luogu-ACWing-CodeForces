#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        if (i % m == 0) puts("PUM");
        else printf("%d ", i);
    }

    return 0;
}