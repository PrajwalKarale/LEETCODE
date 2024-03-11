class Solution {
public:
    string customSortString(string order, string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<char,int>sChar;
        for(int i = 0; i < s.length(); i++){
            sChar[s[i]]++;
        }
        string result = "";
        for(int i = 0; i < order.length(); i++){
            if(sChar.find(order[i]) != sChar.end()){
                while(sChar[order[i]]--){
                    result.push_back(order[i]);
                }
            }
        }
        for(auto &it: sChar){
            while(it.second > 0){
                result.push_back(it.first);
                it.second -= 1;
            }
        }
        return result;
    }
};
