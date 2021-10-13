#include <iostream>
#include <vector>
using namespace std;

vector<int> buildNe(string p) {
    int m = p.size();
    vector<int> ne = vector<int>(m + 1, 0);
    for (int i = 0, j = ne[0] = -1; i < m; ) 
        if (j == -1 || p[i] == p[j]) ne[++i] = ++j;
        else j = ne[j];
    
    return ne;
}

int main() {
    int n, cs = 1;
    string s;
    while (cin >> n, n) {
        printf("Test case #%d\n", cs++);
        cin >> s;
        auto ne = buildNe(s);
        for (int i = 2; i <= s.size(); i++)
            if (ne[i] && i % (i - ne[i]) == 0)  
                printf("%d %d\n", i, i / (i - ne[i]));
                
        puts("");
    }

    return 0;
}