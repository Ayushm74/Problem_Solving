class Solution {
public:
    int getScore(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1)
            return 0;

        vector<int> pre(n), suf(n);

        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = gcd(pre[i - 1], arr[i]);
        }

        suf[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = gcd(suf[i + 1], arr[i]);
        }

        int score = 0;

        for (int i = 0; i < n - 1; i++) {
            if (pre[i] == suf[i + 1])
                score++;
        }

        return score;
    }

    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = gcd(pre[i - 1], nums[i]);
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = gcd(suf[i + 1], nums[i]);
        }

        vector<int> candidates;

        for (int i = 1; i < n; i++) {
            if (pre[i] != pre[i - 1])
                candidates.push_back(i);
        }

        for (int i = 0; i < n - 1; i++) {
            if (suf[i] != suf[i + 1])
                candidates.push_back(i);
        }

        sort(candidates.begin(), candidates.end());
        candidates.erase(
            unique(candidates.begin(), candidates.end()),
            candidates.end()
        );

        int ans = getScore(nums);

        for (int del : candidates) {
            vector<int> arr;

            for (int i = 0; i < n; i++) {
                if (i != del)
                    arr.push_back(nums[i]);
            }

            ans = max(ans, getScore(arr));
        }

        return ans;
    }
};