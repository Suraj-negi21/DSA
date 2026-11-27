class Solution {
public:
    int fib(int n) {
        if (n <= 1)
        return n;
        int half=fib(n-1);
        int nexthalf=fib(n-2);
        int ans=half+nexthalf;
        return ans;    }
};