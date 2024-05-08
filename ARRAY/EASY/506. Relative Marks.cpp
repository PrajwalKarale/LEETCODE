const int ZERO = []()
{
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
std::cout.tie(nullptr);
return 0;
}();

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,int>mp;
        for(int i = 0; i < score.size(); i++){
            mp[score[i]] = i;
        }
        vector<string>result(score.size());
        sort(score.begin(), score.end(), greater<int>());
        for(int i = 0; i < score.size(); i++){
            if(i == 0){
                result[mp[score[i]]] = "Gold Medal";
            }
            else if( i == 1){
                result[mp[score[i]]] = "Silver Medal";
            }
            else if( i == 2){
                result[mp[score[i]]] = "Bronze Medal";
            }else{
                result[mp[score[i]]] = to_string(i + 1);
            }
        }
        return result;
    }
};
