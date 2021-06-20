#include <iostream>
#include <cstring>
using namespace std;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) 
        if (s[i] == 'A') cnt++;
        else cnt--;
    
    if (cnt > 0) printf("A\n");
    else if (cnt < 0) printf("B\n");
    else printf("T\n");

    return 0;
}