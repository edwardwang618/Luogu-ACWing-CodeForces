#include <iostream>
#include <cstring>
using namespace std;

char s[110];

int main() {
    cin.getline(s, 110);
    int n = strlen(s), cnt = 0;
    for (int i = 0; i < n; i++) if ('0' <= s[i] && s[i] <= '9') cnt++;
    cout << cnt << endl;

    return 0;
}