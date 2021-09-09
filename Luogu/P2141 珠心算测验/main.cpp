#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
int a[110];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 3; i <= n; i++) {
        int l = 1, r = i - 1;
        while (l < r) 
            if (a[l] + a[r] < a[i]) l++;
            else if (a[l] + a[r] > a[i]) r--;
            else {
                res++;
                break;
            }
    }

    printf("%d\n", res);
    return 0;
}