class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l=0;
        int r=matrix[0].size()-1;
        int t=0;
        int b=matrix.size()-1;
        vector<int> res;
        while(l<=r && t<=b){
            //traverse across the top boundary
            for(int i=l;i<=r;i++) 
                res.push_back(matrix[t][i]);
            t++;
            //go down
            for(int j=t;j<=b;j++)
                res.push_back(matrix[j][r]);
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){
                    res.push_back(matrix[b][i]);
                }
                b--;
            }
            if(l<=r){
                for(int j=b;j>=t;j--){
                    res.push_back(matrix[j][l]);
                }
                l++;
            }
        }
        return res;
    }
};
