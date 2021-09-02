#include <iostream>
using namespace std;

char s[110];

void print(char str[]) {
    for (int i = 0; str[i]; i++) printf("%c", str[i]);
}

int main() {
    cin.getline(s, 110);
    print(s);

    return 0;
}