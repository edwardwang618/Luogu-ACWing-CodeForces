#include <iostream>
using namespace std;

const int N = 110;

void print2D(int a[][N], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
}

int main() {
    int a[N][N];
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];

    print2D(a, r, c);
    return 0;
}