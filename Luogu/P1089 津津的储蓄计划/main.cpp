#include <iostream>
using namespace std;

int main() {
    int cur = 0, save = 0, res = 0;
    for (int i = 1; i <= 12; i++) {
        int x;
        cin >> x;
        cur += 300 - x;
        if (cur < 0) {
            res = -i;
            break;
        }

        save += cur / 100 * 100;
        cur -= cur / 100 * 100;
    }    

    if (!res) printf("%d\n", cur + save * 120 / 100);
    else printf("%d\n", res);

    return 0;
}