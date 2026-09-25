class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1);
        pref[0] = nums[0];
        vector<int> s(n+1);
        s[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
        }
        
        for(int i = n-2;i>=0;i--){
            s[i] = s[i+1] + nums[i];
        }
        for(int i = 0;i<n;i++){
            if(pref[i] - s[i] == 0) return i; 
        }
        return -1;
        
        
        
    }
};