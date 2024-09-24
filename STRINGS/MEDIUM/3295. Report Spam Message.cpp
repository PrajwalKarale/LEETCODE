class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_set<string>banned(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for(string &word: message){
            if(banned.find(word) != banned.end()){
                count += 1;
            }
            if(count >= 2){
                return true;
            }
        }
        return false;
    }
};
