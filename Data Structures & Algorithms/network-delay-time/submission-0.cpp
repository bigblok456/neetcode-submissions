class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //make sure that u build an adjacency list where u map the src nodes to the destination and the weight
        //use djikstras algo to find the minimum time for the signal to reach all the other nodes
        //use a minheap
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t: times){
            int u=t[0];
            int v=t[1];
            int w=t[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        //minheap is said to have a pair ,first value is the cost and second value is the neighbor
        unordered_set <int> visit;
        //keep track of the nodes that  have visited
        pq.push({0,k});
        int t=0;
        while(!pq.empty()){
            auto [w1,n1]=pq.top();
            pq.pop();
            if(visit.count(n1)){
                continue;
            }//if we have already seen the node, no need to process it
            visit.insert(n1);
            t=w1;
            for(auto [n2,w2]: adj[n1]){
                if(!visit.count(n2)){
                    pq.push({w2+w1,n2});
                    //add the weights as well 
                    //only push into the heap if u have not seen the node
                    //and then process the cheapest edge
                }
            }
        }
        return (visit.size()==n) ? t: -1;


        
    }
};
