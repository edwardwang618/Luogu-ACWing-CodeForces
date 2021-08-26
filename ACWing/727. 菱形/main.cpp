#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n - 1 >> 1; i++) {
        for (int j = 0; j < n - cnt >> 1; j++) printf(" ");
        for (int j = 0; j < cnt; j++) printf("*");
        for (int j = 0; j < n - cnt >> 1; j++) printf(" ");
        cnt += 2;
        puts("");
    }
    for (int i = 0; i < cnt; i++) printf("*");
    puts("");
    cnt -= 2;
    for (int i = 0; i < n - 1 >> 1; i++) {
        for (int j = 0; j < n - cnt >> 1; j++) printf(" ");
        for (int j = 0; j < cnt; j++) printf("*");
        for (int j = 0; j < n - cnt >> 1; j++) printf(" ");
        cnt -= 2;
        puts("");
    }

    return 0;
}