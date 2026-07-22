class Solution {
public:
    void dfs(vector<vector<int>> &heights  ,vector<vector<bool>> & visit,int r,int c){
        int m=heights.size();
        int n=heights[0].size();
        visit[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            //say we are out of bounds then we can continue
            if(nr<0 || nr>=m || nc<0 || nc>=n){
                continue;
            }
            if(visit[nr][nc]){
                continue;
                //if we have already visited then we can continue
            }
            if(heights[nr][nc]<heights[r][c]){
                continue;
            }
            dfs(heights,visit,nr,nc);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));
        //dfs along all the boundaries
        for(int i=0;i<m;i++){
            dfs(heights,pac,i,0);
        }
        for(int j=0;j<n;j++){
            dfs(heights,pac,0,j);
        }
        for(int i=0;i<m;i++){
            dfs(heights,atl,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(heights,atl,m-1,j);
        }
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }
};


