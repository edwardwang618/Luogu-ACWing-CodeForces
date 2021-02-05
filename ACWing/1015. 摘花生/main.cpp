#include <iostream>
using namespace std;

const int N = 105;

int n, m;
int w[N][N], dp[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= m; j++) 
                scanf("%d", &w[i][j]);
        
        for (int i = 1; i<= n; i++) 
            for (int j = 1; j <= m; j++) 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + w[i][j];
       
        printf("%d\n", dp[n][m]);
    }
    
    return 0;
}