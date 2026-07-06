class Solution {
public:
    vector<int> parent;
    vector <int> rank;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool union_find(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb){
            return false;
            //a cycle has been detected
            //a cycle is formed when i add an edge to a tree
            //so basically i should return the edge which when added gives me a cycle
        }
        if(rank[pa]>rank[pb]){
            parent[pb]=pa;
            rank[pa]++;
        }
        else if(rank[pa]<rank[pb]){
            parent[pa]=pb;
            rank[pb]++;
        }
        else{
            parent[pb]=pa;
            rank[pa]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //resize the vectors
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto& edge: edges){
            if(!union_find(edge[0],edge[1])){
                return edge;
                //if union find returns me false then they both have the same parents
                //indicating a cycle
                //i can just return the edge
            }
        }
        return {};

        
    }
};
