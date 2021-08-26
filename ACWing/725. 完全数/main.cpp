#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int sum = 0;
        for (int i = 1; i <= sqrt(x); i++) 
            if (x % i == 0) 
                if(x / i != i) sum += i + x / i;
                else sum += i;
        
        if (sum - x == x) printf("%d is perfect\n", x);
        else printf("%d is not perfect\n", x);
    }

    return 0;
}