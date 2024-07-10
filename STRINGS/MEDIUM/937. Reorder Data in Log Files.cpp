class Solution {
public:
    static bool compare(pair<string,string>&a, pair<string, string>&b){
        if(a.second < b.second || (a.second == b.second && a.first < b.first)){
            return true;
        }
        return false;
    }
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<string>result;
        vector<string>digitLogs;
        vector<pair<string,string>>letterLogs;
        for(string &log: logs){
            //Finding the occurence of the first space
            auto index = log.find(' ');
            if(isDigit(log[index + 1])){
                digitLogs.push_back(log);
            }else{
                string identifier = log.substr(0, index);
                string content = log.substr(index + 1);
                letterLogs.push_back({identifier, content});
            }
        }
        sort(letterLogs.begin(), letterLogs.end(), compare);
        for(auto it: letterLogs){
            string temp = it.first + " " + it.second;
            result.push_back(temp);
        }
        result.insert(result.end(), digitLogs.begin(), digitLogs.end());
        return result;
    }
};
