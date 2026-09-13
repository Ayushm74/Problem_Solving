class Solution {
public:
    int minDays(int n) {

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            long long sum = 0;

            for (int k = 1; k <= i; k++) {

                sum += k;

                if (sum > i) break;

                int remaining = i - sum;

                if (remaining == 0)
                    dp[i] = min(dp[i], k);

                else if (dp[remaining] != INT_MAX)
                    dp[i] = min(dp[i], dp[remaining] + k + 1);
            }
        }

        return dp[n];
    }
};