//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);
        for(int u = 0; u < V; u++){
            for(int &v: adj[u]){
                inDegree[v]++;
            }
        }
        queue<int>q;
        int count = 0;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v: adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count == V){
            return false;
        }
        return true;
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
