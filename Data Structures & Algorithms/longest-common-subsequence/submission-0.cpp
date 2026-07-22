class Solution {
public:
    // this uses a 2d dp
    //this uses a bottom up approach
    //say one of the strings is empty then the longest common subsequence would be 0
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        //as we are accounting for the empty strings as well
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                    //here the chars are matching so add 1 for the matched char and go diagonally
                }
                else{
                    //if the chars are not matching then there are 2 ways either include one substring and exclude
                    //the other and vice versa
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
