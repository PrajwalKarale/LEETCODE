class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_set<string>ban(banned.begin(), banned.end());
        for (auto &c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        unordered_map<string, int>freq;
        istringstream iss(paragraph);
        string w;
        while(iss >> w){
            freq[w] += 1;
        }
        istringstream iss1(paragraph);
        string w1;
        pair<string, int>result("", 0);
        while(iss1 >> w1){
            if(ban.find(w1) == ban.end() && freq[w1] > result.second){
                result = make_pair(w1, freq[w1]);
            }
        }
        return result.first;
    }
};
