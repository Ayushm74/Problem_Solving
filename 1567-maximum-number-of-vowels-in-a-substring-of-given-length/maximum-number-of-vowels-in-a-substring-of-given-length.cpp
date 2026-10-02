class Solution {

public:

    bool vv(char c){
        return c == 'a' || c == 'e' || c == 'i' || 
               c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {

        int count = 0;

        for(int i = 0;i<k;i++){
            if(vv(s[i])){
                count++;
            }
        }

        int mc = count;

        for(int i = k;i<s.size();i++){
            if(vv(s[i])) count++;
            if(vv(s[i-k])) count--;

            mc = max(mc,count);
        }

        return mc;
    }
};