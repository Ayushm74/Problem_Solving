class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int mn=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[n-1]){
                low=mid+1;
            }
            else{
                mn=mid;
                high=mid-1;
            }
        }
        if(target>nums[mn] && target>nums[n-1]){
            low=0;
            high=mn-1;
        }
        else{
            low=mn;
            high=n-1;
        }
        int idx=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else{
                idx=mid;
                low=mid+1;
            }
        }
        if(nums[idx]==target) return idx;
        else return -1;
    }
};