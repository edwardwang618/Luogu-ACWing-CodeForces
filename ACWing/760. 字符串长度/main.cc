#include <iostream>
using namespace std;

char s[110];

int main() {
    cin.getline(s, 110);
    char *p = s;
    while (*p) p++;
    printf("%d", p - s);
    return 0;
}