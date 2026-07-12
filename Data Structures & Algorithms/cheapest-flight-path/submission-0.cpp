class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //use the bell man ford algorithm
        //dont use djikstras here as these would give the cheapest path but it might include
        //more than k stops
        int stops=0;
        //u need to go k+1 levels deep
        //if k=2
        //then the  no. of edges would be 3 as there are two stops atmost between src and dst
        vector<int> prices(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> graph;
        for(auto f: flights){
            int from=f[0];
            int to=f[1];
            int price=f[2];
            graph[from].push_back({to,price});
        }
        queue<pair<int,int>> q;//pushing the city and the curr cost
        q.push({src,0});
        while(!q.empty() && stops<=k){
            int size=q.size();
            while(size--){
                auto [curr_node,curr_cost]=q.front();
                q.pop();
                for(auto nei: graph[curr_node]){
                    int next_node=nei.first;
                    int price=nei.second;
                    if(curr_cost+price<prices[next_node]){
                        prices[next_node]=curr_cost+price;
                        q.push({next_node,prices[next_node]});

                    }
                }
            }
            stops++;

        }
        if(prices[dst]==INT_MAX){
            return -1;
        }
        return prices[dst];


        
    }
};
