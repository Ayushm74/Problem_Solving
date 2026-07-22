class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;

        long long ans = s + m;
        ans += 1LL * (m - 1) * ((n - 2) / 2);

        return ans;
    }
};