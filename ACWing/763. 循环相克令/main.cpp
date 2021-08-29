#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        if (s == t) {
            cout << "Tie" << endl;
            continue;
        }

        bool win;
        if (s == "Hunter") win = t == "Gun";
        else if (s == "Gun") win = t == "Bear";
        else win = t == "Hunter";
        if (win) cout << "Player1" << endl;
        else cout << "Player2" << endl;
    }

    return 0;
}