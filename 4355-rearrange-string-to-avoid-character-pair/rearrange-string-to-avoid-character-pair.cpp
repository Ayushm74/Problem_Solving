class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        map<char, int> mp;

        for (char c : s)
            mp[c]++;

        string ans;

        while (mp[y] > 0) {
            ans += y;
            mp[y]--;
        }
        while (mp[x] > 0) {
            ans += x;
            mp[x]--;
        }

        for (auto &it : mp) {
            if (it.first == x || it.first == y)
                continue;

            while (it.second > 0) {
                ans += it.first;
                it.second--;
            }
        }

        

        return ans;
    }
};