class Solution {
public:
    vector <vector<int>> dp;
    int dfs(vector<int>& prices,int i,bool canbuy){
        if(i>=prices.size()){
            return 0;//no profit
        }
        int profit;
        if(dp[i][canbuy]!=-1){
            return dp[i][canbuy];
        }
        if(canbuy){
            int buy=-prices[i]+dfs(prices,i+1,false);
            int skip=dfs(prices,i+1,true);
            profit=max(skip,buy); 
        }
        else{
            int sell=prices[i]+dfs(prices,i+2,true);
            int hold=dfs(prices,i+1,false);
            profit =max(sell,hold);
        }
        dp[i][canbuy]=profit;
        return dp[i][canbuy];
    }
    int maxProfit(vector<int>& prices) {
        //this is a dp problem
        dp=vector <vector<int>>(prices.size(),vector<int>(2,-1));
        //build a dfs function
        int answer=dfs(prices,0,true);
        //as initially i didnt buy anything
        return answer;

        
    }
};
