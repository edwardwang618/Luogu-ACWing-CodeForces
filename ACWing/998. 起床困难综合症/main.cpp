#include <iostream>
#include <bitset>
using namespace std;

int n, m;

int main() {
    bitset<30> zero, one;
    zero.reset();
    one.set();
    scanf("%d%d", &n, &m);
    while (n--) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "AND") zero &= x, one &= x;
        else if (s == "OR") zero |= x, one |= x;
        else zero ^= x, one ^= x;
    }
    
    int res = 0;
    for (int i = 30; i >= 0; i--)
        if (zero[i] || (one[i] && m >= 1 << i)) res |= 1 << i;
    
    printf("%d\n", res);

    return 0;
}