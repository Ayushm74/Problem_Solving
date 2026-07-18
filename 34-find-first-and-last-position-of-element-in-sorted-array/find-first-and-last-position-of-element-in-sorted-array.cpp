class Solution {
public:
    int lb(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
        int ub(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]> target){
                
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb1 = lb(nums,target);
        if(lb1 == nums.size() || nums[lb1] != target) return {-1,-1};
        return {lb1, ub(nums,target)-1};
    }
};