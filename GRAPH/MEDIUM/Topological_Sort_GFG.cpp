
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>inDegree(V, 0);
	    for(int u = 0; u < V; u++){
	        for(int &v: adj[u]){
	            inDegree[v]++;
	        }
	    }
	    
	    queue<int>q;
	    
	    //Pushing the nodes with indegree 0 since they should be printed first in topological sort
	    for(int i = 0; i < inDegree.size(); i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> result;
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        result.push_back(u);
	        for(int &neighbour: adj[u]){
	            inDegree[neighbour]--;
	            if(inDegree[neighbour] == 0){
	                q.push(neighbour);
	            }
	        }
	    }
	    return result;
	    // code here
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
