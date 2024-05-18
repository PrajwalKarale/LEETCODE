//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    typedef pair<int, int>P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int minimumCost = 0;
        priority_queue<P, vector<P>, greater<P>> minHeap;
        
        //{weight, targetNode}
        minHeap.push({0,0});
        vector<bool>visited(V, false);
        
        while(!minHeap.empty()){
            pair<int,int> p = minHeap.top();
            int weight = p.first;
            int targetNode = p.second;
            minHeap.pop();
            
            if(visited[targetNode] == true){
                continue;
            }
            
            visited[targetNode] = true;
            minimumCost += weight;
            for(auto &neighbour: adj[targetNode]){
                int neighbourNode = neighbour[0];
                int neighbourNodeWeight = neighbour[1];
                if(visited[neighbourNode] == false){
                    minHeap.push({neighbourNodeWeight, neighbourNode});
                }
            }
        }
        return minimumCost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
