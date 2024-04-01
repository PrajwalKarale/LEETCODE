class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int lengthOfLastWord(string s) {
        vector<string>words;
        stringstream obj(s);
        string temp;
        while(obj>>temp)
        {
            words.push_back(temp);
        }
        int length = words[(words.size()-1)].size();
        return length;
    }
};
