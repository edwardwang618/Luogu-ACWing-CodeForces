#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        bool is_prime = true;
        for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) {is_prime = false; break;}
        if (is_prime) printf("%d is prime\n", x);
        else printf("%d is not prime\n", x);
    }

    return 0;
}