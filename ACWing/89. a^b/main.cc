#include <iostream>
using namespace std;

int main() {
    long a, b, p;
    cin >> a >> b >> p;
    
    if (p == 1) puts("0");
    else {
        long res = 1;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        
        cout << res << endl;
    }
    
    return 0;
}