class Solution {
public:
    int dfs(vector<int> &nums,int i,int target,int currsum){
        if(i==nums.size()){
            return currsum==target ? 1: 0;
        }
        int num=currsum+nums[i];
        int add=dfs(nums,i+1,target,num);
        int num1=currsum-nums[i];
        int sub=dfs(nums,i+1,target,num1);
        return add+sub;



    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ways=dfs(nums,0,target,0);
        return ways;
        
    }
};
