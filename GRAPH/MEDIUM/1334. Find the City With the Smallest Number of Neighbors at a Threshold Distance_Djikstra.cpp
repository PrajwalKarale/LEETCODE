/*
1. Finding the shortest path matrix using Djikstra's Algorithm. This can be done using Bellman Ford as well as Floyd Warshall Algorithm.
2. Djikstra's Algorithm and Bellman Ford is Single Source Shortest Path Algorithm so we need to apply it from each and every node so that we can find the shortes path between the nodes.
3. For Djikstra's Algorithm approach the  T.C will be as follows:
   findCity() -> O(V^2)
   djikstra() -> O(V*E * logV) since we are applying Djikstra on every node to fill the shortestPathMatrix
   S.C -> shortestPathMatrix -> O(V^2)
          adjList -> O(V + E)  
*/

# define P pair<int,int>
class Solution {
public:
    int findCity(vector<vector<int>>&shortestPathMatrix, int n, int d){
        int resultantCity = -1;
        int leastCount = INT_MAX;
        for(int i = 0; i < n; i++){
            int tempCount = 0;
            for(int j = 0; j < n; j++){
                if(i != j && shortestPathMatrix[i][j] <= d){
                    tempCount++;
                }
            }

            if(tempCount <= leastCount){
                leastCount = tempCount;
                resultantCity = i;
            }
        }
        return resultantCity;
    }
    void djikstra(unordered_map<int,vector<P>> &adjList, int source, vector<int>&result){
        // Creating a min Heap
        priority_queue<P, vector<P>, greater<P>>pq;
        fill(result.begin(), result.end(), INT_MAX);
        pq.push({0, source});
        result[source] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto &p: adjList[node]){
                int adjNode = p.first;
                int distance = p.second;
                if(d + distance < result[adjNode]){
                    result[adjNode] = d + distance;
                    pq.push({d + distance, adjNode});
                }
            }
        }
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>>shortestPathMatrix(n , vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++){
            shortestPathMatrix[i][i] = 0;
        }
        unordered_map<int, vector<P>>adjList;

        for(vector<int>&edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        for(int i = 0; i < n; i++){
            djikstra(adjList, i, shortestPathMatrix[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << shortestPathMatrix[i][j] << " ";
            }
            cout << endl;
        }
        return findCity(shortestPathMatrix, n, distanceThreshold);
    }
};
