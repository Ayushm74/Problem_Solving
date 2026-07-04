class Solution {
public:
    int k;
    long long dp[20][12][2][2];

    long long dfs(int i,int p,bool tg,bool st,string &s){

        if(i==s.size())
            return st; 
        if(dp[i][p+1][tg][st]!=-1)
            return dp[i][p+1][tg][st];

        int lim=tg?(s[i]-'0'):9;

        long long ans=0;

        for(int d=0;d<=lim;d++){

            if(p==-1 && d==0){

                ans+=dfs(i+1,-1,tg&&(d==lim),false,s);
            }
            else if(p==-1 || abs(p-d)<=k){

                ans+=dfs(i+1,d,tg&&(d==lim),true,s);
            }
        }

        return dp[i][p+1][tg][st]=ans;
    }

    long long solve(long long x){

        string s=to_string(x);

        memset(dp,-1,sizeof(dp));

        return dfs(0,-1,true,false,s);
    }

    long long goodIntegers(long long l,long long r,int kk) {

        k=kk;

        return solve(r)-solve(l-1);
    }
};