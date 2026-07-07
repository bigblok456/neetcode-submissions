class Solution {
public:
//this uses union find here
//here for every succesful merging of different sets i need to reduce the no.of components

    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool union_find(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb) return false;//a cycle has been detected and the no.of connected components stays the same
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
        //after successful merging of components i can return true

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,1);
        int components=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto & edge: edges){
            if(union_find(edge[0],edge[1])){
                //when i get true then i reduce the no. of connected components by one
                components--;
            }
        }
        return components;

    }
};
