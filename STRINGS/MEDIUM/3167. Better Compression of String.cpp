auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    string betterCompression(string compressed) {
        map<char,int>freq;
        int n = compressed.length();
        string result = "";
        for(int i = 0; i < n - 1; i++){
            if(compressed[i] - '0' >= 49 && compressed[i] - '0' <= 74){
                int j = i + 1;
                int frequency = 0;
                while(isdigit(compressed[j])){
                    frequency = frequency * 10 + (compressed[j] - '0');
                    j++;
                }
                freq[compressed[i]] += frequency;
            }
        }
        for(auto &it: freq){
            result = result + it.first + to_string(it.second);
        }
        return result;
    }
};
