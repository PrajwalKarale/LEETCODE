#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int>s;
        int root = INT_MIN;
        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] < root){
                return false;
            }
            while(!s.empty() && s.top() < preorder[i]){
                root = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
        return true;
    }
};
