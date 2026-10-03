class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l  =0;
        int r = 0;
        int len = INT_MIN;
        int cz = 0;
        while(r<n){
            if(nums[r] == 0) cz++;
            while(cz>k){
                if(nums[l] == 0) cz--;
                l++;
            }
            len = max(len, r-l +1);
            r++;
        }
        return len;
        
    }
};