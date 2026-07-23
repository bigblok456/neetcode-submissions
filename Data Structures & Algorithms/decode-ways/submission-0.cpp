class Solution {
public:
    int dfs(string s,vector<int> &dp,int i){
        if(i==s.size()){
            return 1;
        }
        if (s[i]=='0') return 0;
        //we dont have a valid mapping for the char 0
        //so 
        if(dp[i]!=-1){
            return dp[i];
        }
        int res=dfs(s,dp,i+1);
        //here we have either one digit 
        //option 2 is we can choose 2 digits
        if(i+1<s.size()){
            int num=stoi(s.substr(i,2));
            if(num>=10 && num<=26){
                res+=dfs(s,dp,i+2);
            }
        }
        dp[i]=res;
        return res;

    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return dfs(s,dp,0);
    }
};
