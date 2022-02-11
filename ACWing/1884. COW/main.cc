#include <iostream>
using namespace std;

long n, f[3];
string s;

int main() {
    scanf("%ld", &n);
    cin >> s;

    for (auto &ch : s) {
        if (ch == 'C') f[0]++;
        else if (ch == 'O') f[1] += f[0];
        else f[2] += f[1];
    }

    printf("%ld\n", f[2]);

    return 0;
}