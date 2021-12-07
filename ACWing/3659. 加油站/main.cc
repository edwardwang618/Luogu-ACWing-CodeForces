#include <iostream>
using namespace std;

const int N = 5010;
int a[N];
int n, k;

int main() {
    while (scanf("%d%d", &n, &k) != -1) {
        for (int i = 1; i <= k + 1; i++) scanf("%d", &a[i]);
        int res = 0, oil = n;
        for (int i = 1; i <= k + 1; i++) {
            if (n < a[i]) {
                res = -1;
                break;
            }
            
            if (oil >= a[i]) oil -= a[i];
            else {
                res++;
                oil = n - a[i];
            }
        }

        if (~res) printf("%d\n", res);
        else puts("No Solution");
    }
    
    return 0;
}