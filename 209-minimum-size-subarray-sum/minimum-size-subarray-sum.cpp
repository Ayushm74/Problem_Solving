class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum  = 0;
        int ans = INT_MAX;
        while(r<n){
            sum += nums[r];
            while(sum>=t){
                sum -= nums[l];
                ans = min(ans,r-l+1);
                l++;
            }
            r++;
        }
        return ans == INT_MAX ? 0 : ans;

    }
};