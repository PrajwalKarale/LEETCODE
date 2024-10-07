auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
};
class Solution {
public:
    string convertBinary(int num){
        if(num == 0){
            return "0";
        }
        string bi = "";
        while(num > 0){
            bi = (num % 2 == 0 ? "0" : "1") + bi;
            num = num / 2;
        }
        return bi;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string>arr;
        for(int &num: nums){
            arr.push_back(convertBinary(num));
        }
        vector<int> ans;

        string s1= arr[0]+arr[1]+arr[2];
        ans.push_back(stol(s1, nullptr, 2));
        string s2= arr[0]+arr[2]+arr[1];
        ans.push_back(stol(s2, nullptr, 2));
        string s3= arr[1]+arr[0]+arr[2];
        ans.push_back(stol(s3, nullptr, 2));
        string s4= arr[1]+arr[2]+arr[0];
        ans.push_back(stol(s4, nullptr, 2));
        string s5= arr[2]+arr[1]+arr[0];
        ans.push_back(stol(s5, nullptr, 2));
        string s6= arr[2]+arr[0]+arr[1];
        ans.push_back(stol(s6, nullptr, 2));

        sort(ans.begin(), ans.end());
        return ans[5];
    }
};
