class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size()-1;
      //  int ans = 0;
        while(l<=r){
            int mini = min(height[l],height[r]);
           int  val = (r-l)*mini;
            ans = max(ans,val);
            if(height[l]<=height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
        
        
    }
};