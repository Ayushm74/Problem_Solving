class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int l = 0;
        int r = 0;

        while (r < m) {

            // Add current character
            freq2[s2[r] - 'a']++;

            // Keep window size <= s1.size()
            while (r - l + 1 > n) {
                freq2[s2[l] - 'a']--;
                l++;
            }

            // Check if current window is a permutation
            if (r - l + 1 == n && freq1 == freq2) {
                return true;
            }

            r++;
        }

        return false;
    }
};