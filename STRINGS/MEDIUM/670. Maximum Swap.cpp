auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int>maxRight(n, -1);
        maxRight[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--){
            int maxRightIndex = maxRight[i + 1];
            int maxRightElement = s[maxRightIndex] - '0';

            if((s[i] - '0') > maxRightElement){
                maxRight[i] = i;
            }else{
                maxRight[i] = maxRightIndex;
            }
        }
        for(int i = 0; i < n; i++){
            int maxRightAti = maxRight[i];
            int maxRightAtiElement = s[maxRightAti] - '0';
            if((s[i] - '0') < maxRightAtiElement){
                swap(s[i], s[maxRightAti]);
                return stoi(s);
            }
        }
        return num;
    }
};
