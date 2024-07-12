class Solution {
public:
    string removeString(string s, string subStr){
        stack<char>st;
        for(char &c: s){
            if((!st.empty()) && (c == subStr[1]) && (st.top() == subStr[0])){
                st.pop();
            }else{
                st.push(c);
            }
        }
        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = s.length();
        int gain = 0;

        string maxString;
        string minString;
        if(x > y){
            maxString = "ab";
            minString = "ba";
        }else{
            maxString = "ba";
            minString = "ab";
        }

        // Since we are following the greedy approach we will first remove the substring that gives us the most points and then the substring that gives us the min points and then add both the score.

        string remainingS = removeString(s, maxString);
        int charactersRemoved = s.length() - remainingS.length();
        gain = gain + (charactersRemoved / 2)*max(x,y);
        string finalS = removeString(remainingS, minString);
        int charactersRemoved2 = remainingS.length() - finalS.length();
        gain = gain + (charactersRemoved2 / 2) * min(x, y);
        
        return gain;
    }
};
