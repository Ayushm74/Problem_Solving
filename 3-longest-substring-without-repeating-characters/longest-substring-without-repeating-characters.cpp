class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int l  = 0;
        int r = 0;
        int ans = INT_MIN;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
    return ans == INT_MIN? 0: ans;
    }
};