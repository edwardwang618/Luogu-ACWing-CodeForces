#include <iostream>
using namespace std;

int f[1010];

int main() {
    int n;
    cin >> n;
    int a[] = {0, 10, 20, 50, 100};

    f[0] = 1;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++) 
            if (j >= a[i]) f[j] += f[j - a[i]];

    cout << f[n] << endl;

    return 0;
}