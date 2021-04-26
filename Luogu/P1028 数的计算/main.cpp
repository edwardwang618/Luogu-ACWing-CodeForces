#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 表示以k结尾的数字能产生多少个结果
    int f[1001] = {0};

    for (int i = 1; i <= n; ++i) {
        f[i] = 1;
        for (int j = 1; j <= i / 2; ++j)
            f[i] += f[j];
    }

    cout << f[n] << endl;

    return 0;
}