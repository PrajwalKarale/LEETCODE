class Solution {
public:
    string alienOrder(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(words.size() == 0){
            return "";
        }
        // Creating adjacency list: In this each character is a node
        unordered_map<int,unordered_set<int>> adjList;
        unordered_map<int,int>inDegree;
        for(auto &word: words){
            for(char &c: word){
                inDegree[c - 'a'] = 0;
            }
        }
        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
                return "";
            }
            //We will loop till length of that string whose length is minimum between word1 and word2
            int length = min(word1.length(), word2.length());
            for(int i = 0; i < length; i++){
                if(word1[i] != word2[i]){
                    int index1 = word1[i] - 'a';
                    int index2 = word2[i] - 'a';
                    if(adjList[index1].find(index2) == adjList[index1].end()){
                        adjList[index1].insert(index2);
                        inDegree[index2]++;
                    }
                    break;
                }
            }
        }

        queue<int>q;
        vector<int>result;
        string order = "";
        for(auto &it: inDegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        for(auto it: inDegree){
            cout << it.first << " " << it.second << endl;
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(auto &v: adjList[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() != inDegree.size()){
            return "";
        }
        for(int i = 0; i < result.size(); i++){
            order.push_back(result[i] + 'a');
        }
        return order;
    }
};
