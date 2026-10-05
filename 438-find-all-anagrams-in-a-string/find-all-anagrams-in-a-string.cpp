class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if(m>n) return ans;
        unordered_map<char,int> mp;
        for(int i = 0;i<m;i++){
            mp[p[i]]++;
        }
        unordered_map<char,int> mp2;
        int l  = 0;
        int r  = 0;
        while(r<n){
            mp2[s[r]]++;
            if (r - l + 1 > m) {
                mp2[s[l]]--;

                if (mp2[s[l]] == 0) {
                    mp2.erase(s[l]);
                }

                l++;
            }
            
            if(mp == mp2) ans.push_back(l);
            r++;
        }


        return ans;
        
    }
};