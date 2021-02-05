class Solution {
public:
    int lowbit(int x) {
        return x & -x;
    }

    int NumberOf1(int n) {
        int res = 0;
        while (n) {
            n -= lowbit(n);
            res++;
        }

        return res;
    }
};