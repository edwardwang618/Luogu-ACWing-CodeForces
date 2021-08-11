#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> res;

bool cmp(string a, string b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = 0; i < a.size(); i++) if (a[i] < b[i]) return false;
    return true;
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    int sign = 0;
    if (!cmp(a, b)) {
        swap(a, b);
        sign = -1;
    }
        
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0, t = 0; i < a.size(); i++) {
        t = a[i] - '0' - t;
        if (i < b.size()) t -= b[i] - '0';
        res.push_back((t + 10) % 10);
        t = t < 0 ? 1 : 0;
    }

    while (res.size() > 1 && !res.back()) res.pop_back();

    if (sign == -1) printf("-");
    for (int i = res.size() - 1; i >= 0; i--) printf("%d", res[i]);
    puts("");

    return 0;
}