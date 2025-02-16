/*
    Logic:
        1. First we will have to construct a graph. Then the question is like finding similar components. So our approach will be assigning componentId to the components and then checking in the `equations`
        when there is `!=` constraint
        2. We can solve the question using DSU too.
    Time Complexity:
        1. Graph Construction: O(n) where n is the number of equation
        2. BFS: O(n)
        3. Checking '!=' Constraints: O(n)
    Space Complexity:
        1. Graph Construction: O(n)
        2. Queue: O(n) can contain n nodes in worst case.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    void bfs(unordered_map<char, vector<char>>&adjList, int componentId, unordered_map<char,int>&components, char node){
        queue<char>q;
        q.push(node);
        while(!q.empty()){
            char currNode = q.front();
            q.pop();
            for(auto &nieghbor: adjList[currNode]){
                if(components.find(nieghbor) == components.end()){
                    components[nieghbor] = componentId;
                    q.push(nieghbor);
                }
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, vector<char>>adjList;
        for(string &equation: equations){
            char u = equation[0];
            char v = equation[3];
            if(equation[1] == '='){
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }   
        unordered_map<char,int>components;
        int componentId = 0;
        for(auto it: adjList){
            if(components.find(it.first) == components.end()){
                bfs(adjList, componentId, components, it.first);
                componentId++;
            }
        }
        for(string &equation: equations){
            if(equation[1] == '!'){
                char u = equation[0];
                char v = equation[3];
                if(u == v){
                    return false;
                }
                if(
                    components.find(u) != components.end() &&
                    components.find(v) != components.end() &&
                    components[u] == components[v]
                ){
                    return false;
                }
            }
        }
        return true;
    }
};
