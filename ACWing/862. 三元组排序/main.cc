#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int n;
struct st {
    int x;
    double y;
    string z;

    bool operator<(const st& e) {
        if (x != e.x) return x < e.x;
        else if (y != e.y) return y < e.y;
        else return z < e.z;
    }
} a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        double y;
        string z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
    }

    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        auto e = a[i];
        printf("%d %.2lf %s\n", e.x, e.y, e.z.c_str());
    }

    return 0;
}