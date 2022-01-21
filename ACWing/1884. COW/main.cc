#include <iostream>
using namespace std;

long n, res, cc, co;
string s;

int main() {
    scanf("%ld", &n);
    cin >> s;

    for(auto &ch : s) {
        if(ch == 'C') cc++;
        else if(ch == 'O') co += cc;
        else res += co;
    }

    printf("%ld\n", res);

    return 0;
}