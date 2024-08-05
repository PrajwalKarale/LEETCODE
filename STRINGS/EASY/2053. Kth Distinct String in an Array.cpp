class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<string,int>freq;
        for(string &str: arr){
            freq[str]++;
        }
        for(string &str: arr){
            if(freq[str] == 1 && --k == 0){
                return str;
            }
        }
        return "";
    }
};
