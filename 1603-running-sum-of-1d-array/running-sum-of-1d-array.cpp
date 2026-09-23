class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         vector<int> prefix;
         prefix.push_back(nums[0]);
         int sum = nums[0];
         for(int i = 1;i<nums.size();i++){
            sum+= nums[i];
            prefix.push_back(sum);
         }
         return prefix;
    }
};