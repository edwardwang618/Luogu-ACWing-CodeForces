class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b = 1, c = 0;
        for (int i = 0; i < n - 1; i++) {
            c = a + b;
            a = b, b = c;
        }

        if (n == 0) return a;
        else if (n == 1) return b;
        else return c;
    } 
};