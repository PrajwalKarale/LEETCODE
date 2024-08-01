class Solution {
public:
    int countSeniors(vector<string>& details) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int count = 0;
        for(string &detail: details){
            if(stoi(detail.substr(11,2)) > 60){
                count+=1;
            }
        }
        return count;
    }
};
