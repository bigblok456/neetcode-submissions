class Solution {
public:
//maintain an adj list and keep track of the nodes that u hav come from
    unordered_set <int> visit;
    bool dfs(unordered_map<int,vector<int>> &adj,int node,int prev){
        visit.insert(node);
        for(auto nei: adj[node]){
            if(nei==prev){
                continue;
            }
            if(visit.count(nei)){
                return false;
            }
            if(!dfs(adj,nei,node)){
                return false;
            }
        }
        return true;

    }
    bool validTree(int n, vector<vector<int>>& edges) {
          unordered_map<int,vector<int>> adj;
          for(auto &edge: edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
          }
          //after pushing elements into the adjacency list
          if(!dfs(adj,0,-1)) return false;
          return (n==visit.size());
        




    }
};
