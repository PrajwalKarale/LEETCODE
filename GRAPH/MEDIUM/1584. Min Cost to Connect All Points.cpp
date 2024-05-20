auto speedUp = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#pragma GCC optimize("Ofast")
#pragma GCC target("tune=native")

class Solution {
public:
    typedef pair<int,int>P;
    int primsAlgorithm(vector<vector<P>> &adjList){
        int sum = 0;
        int V = adjList.size();
        vector<bool>visited(V, false);
        priority_queue<P, vector<P>, greater<P>>minHeap;
        
        //{weight, destinationNode}
        minHeap.push({0,0});
        
        while(!minHeap.empty()){
            auto p = minHeap.top();
            minHeap.pop();
            
            int weight = p.first;
            int destinationNode = p.second;
            
            if(visited[destinationNode] == true){
                continue;
            }
            
            visited[destinationNode] = true;
            sum += weight;
            
            for(auto &neigh: adjList[destinationNode]){
                int neighNode = neigh.first;
                int neighWeight = neigh.second;
                if(visited[neighNode] == false){
                    minHeap.push({neighWeight, neighNode});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<P>>adjList(V);
        for(int i = 0; i < V; i++){
            for(int j = i + 1; j < V; j++){
                int xi = points[i][0];
                int yi = points[i][1];
                
                int xj = points[j][0];
                int yj = points[j][1];
                
                //Calculating Manhattan Distance
                int distance = abs(xj - xi) + abs(yj - yi);
                adjList[i].push_back({j, distance});
                adjList[j].push_back({i, distance});
            }
        }

        int minCost = primsAlgorithm(adjList);
        return minCost;
    }
};
