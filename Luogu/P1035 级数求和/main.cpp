#include <iostream>
using namespace std;

double s;
int k;

int main() {    
    cin >> k;
    for (int i = 1; ; i++) {
        s += 1.0 / i;
        if (s > k) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}