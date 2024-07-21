class Solution {
public:
    vector<int>prefix;
    Solution(vector<int>& w) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        prefix.resize(w.size());
        prefix[0] = w[0];
        for(int i = 1; i < w.size(); i++){
            prefix[i] = prefix[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int l = 0;
        int r = prefix.size() - 1;
        int target = rand() % prefix.back();
        while(l < r){
            int mid = (l + r) / 2;
            if(prefix[mid] > target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
