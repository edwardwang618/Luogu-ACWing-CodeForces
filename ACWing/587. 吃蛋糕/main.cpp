#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;
int n;
int f[N];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (long i = 1; i * i <= n; i++)
            for (int j = i * i; j <= n; j++)
                if (f[j - i * i] != INF)
                    f[j] = min(f[j], f[j - i * i] + 1);
        
        printf("Case #%d: %ld\n", t, f[n]);
    }
    
    return 0;
}