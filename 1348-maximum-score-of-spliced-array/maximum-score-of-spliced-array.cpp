class Solution {
public:
    int kadane(vector<int>& a, vector<int>& b) {
        int cur = 0, maxi = 0;

        for (int i = 0; i < a.size(); i++) {
            cur += b[i] - a[i];
            cur = max(cur, 0);
            maxi = max(maxi, cur);
        }

        return maxi;
    }

    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        return max(sum1 + kadane(nums1, nums2),
                   sum2 + kadane(nums2, nums1));
    }
};