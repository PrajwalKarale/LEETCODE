/*
    Logic:
        1. We know that Alice and Bob are moving independently. So that means we have to do traversal for Alice and Bob differently. So the important thing we should note that 'time' is an important factor, because whenever alice and bob are on the same node we need to divide the value between these two.
        2. So we will traverse the graph first and then note down the timings of each node.
        3. First we will apply DFS/BFS from bob -> 0 and store the timing
        4. Then for Alice we will apply DFS/BFS from 0 -> leaf node
    Time Complexity:
        1. We are using DFS two times so T.C -> O(n + n) ~ O(n)
    Space Complexity:
        1. We are using auxiliary space as visited vector.
        2. S.C -> O(n)
*/
class Solution {
public:
    unordered_map<int,int>nodeTime;
    int aliceIncome;
    void dfsAlice(unordered_map<int,vector<int>>&adjList, vector<bool>&visited, vector<int>&amount, int time, int income, int currentNode){
        visited[currentNode] = true;
        if((nodeTime.find(currentNode) == nodeTime.end()) || time < nodeTime[currentNode]){
            income += amount[currentNode];
        } else if(time == nodeTime[currentNode]){
            income += (amount[currentNode] / 2);
        }

        if(adjList[currentNode].size() == 1 && currentNode != 0){
            aliceIncome = max(aliceIncome, income);
        }

        for(auto &neighbour: adjList[currentNode]){
            if(!visited[neighbour]){
                dfsAlice(adjList, visited, amount, time + 1, income, neighbour);
            }
        }
    }
    bool dfsBob(unordered_map<int,vector<int>>&adjList, vector<bool>&visited, int time, int currentNode){
        visited[currentNode] = true;
        nodeTime[currentNode] = time;
        
        // This means we have reached the target
        if(currentNode == 0){
            return true;
        }
        for(auto & neighbour: adjList[currentNode]){
            // If neighbour is unvisited
            if(visited[neighbour] == false){
                if(dfsBob(adjList, visited, time+1, neighbour) == true){
                    return true;
                }
            }
        }
        nodeTime.erase(currentNode);
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); // n nodes from 0 -> n-1
        unordered_map<int,vector<int>>adjList;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        int time = 0;
        aliceIncome = INT_MIN;
        vector<bool>visited(n, false);
        dfsBob(adjList, visited, time, bob);
        visited.assign(n, false);
        dfsAlice(adjList, visited, amount, 0, 0, 0);
        return aliceIncome;
    }
};
