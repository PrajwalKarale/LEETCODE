class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = s.length();
        vector<int>nearestLeft(n, -1);
        vector<int>nearestRight(n, s.length() - 1);
        vector<int>plates(n, 0);
        vector<int>result;
        plates[0] = (s[0] == '*') ? 1: 0;
        for(int i = 1; i < n; i++){
            if(s[i] == '*'){
                plates[i] = plates[i - 1] + 1;
            }else{
                plates[i] = plates[i - 1];
            }
        }
        nearestLeft[0] = (s[0] == '|') ? 0 : -1; 
        for(int i = 1; i < n; i++){
            if(s[i] == '|'){
                nearestLeft[i] = i;
                continue;
            }else{
                nearestLeft[i] = nearestLeft[i - 1];
            }
        }
        nearestRight[nearestRight.size() - 1] = (s[n - 1] == '|') ? n - 1 : INT_MAX;
        for(int i = n - 2; i>= 0; i--){
            if(s[i] == '|'){
                nearestRight[i] = i;
                continue;
            }else{
                nearestRight[i] = nearestRight[i + 1];
            }
        }
        for(vector<int>&query: queries){
            int left = nearestRight[query[0]];
            int right = nearestLeft[query[1]];
            if(left != -1 && right != -1 && left < right){
                result.push_back(plates[right] - plates[left]);
            }else{
                result.push_back(0);
            }
        }
        return result;
    }
};
