#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, char> mp;
    mp['<'] = '>';
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';

    stack<char> stk;

    string s;
    cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) 
        if (mp.count(s[i])) stk.push(s[i]);
        else if (!stk.empty() && mp[stk.top()] == s[i]) stk.pop();
        else {
            flag = false;
            break;
        }

    if (flag) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}