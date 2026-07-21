class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;

        long long resources = k;
        long long operations = 0;

        for (int x : nums) {
            if (resources < x) {
                long long need = (x - resources + k - 1LL) / k;
                operations += need;
                resources += need * 1LL * k;
            }
            resources -= x;
        }

        long long ans = (operations % MOD) * ((operations + 1) % MOD) % MOD;
        ans = ans * ((MOD + 1) / 2) % MOD;   // modular inverse of 2

        return (int)ans;
    }
};