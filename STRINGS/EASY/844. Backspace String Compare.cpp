/*
    Logic:
        1. bruteForce() -> Take a temporary string and start adding the characters and whenvever a # encountered delete the last string encountered.
        2. Whenever we are encountering # we are removing the char before it. Instead of doing that what if we traverse the string from the end and whenever we encounter # we skip the character next to #. This time we wont need auxiliary space.
    Time Complexity:
        1. bruteForce() -> T.C -> O(n)
        2. optimised() -> T.C -> O(n)
    Space Complexity:
        1. bruteForce() -> S.C -> O(n) since temporary string is created.
        2. optimised() -> S.C -> O(1)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    string helper(string s){
        string temp = "";
        for(char &ch: s){
            if(ch != '#'){
                temp.push_back(ch);
            }
            else if(temp.length() > 0){
                temp.pop_back();
            }
        }
        return temp;
    }
    bool bruteForce(string s, string t){
        string newS = helper(s);
        string newT = helper(t);
        if(newS == newT){
            return true;
        }
        return false;
    }
    bool optimised(string s, string t){
        int m = s.length();
        int n = t.length();
        int i = m - 1;
        int j = n - 1;
        int hashS = 0;
        int hashT = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    hashS++;
                    i--;
                }else if(hashS > 0){
                    hashS--;
                    i--;
                }else{
                    break;
                }
            }
            while(j >= 0){
                if(t[j] == '#'){
                    hashT++;
                    j--;
                }else if(hashT > 0){
                    hashT--;
                    j--;
                }else{
                    break;
                }
            }
            char first = i < 0 ? '$': s[i];
            char second = j < 0 ? '$': t[j];
            if(first != second){
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    bool backspaceCompare(string s, string t) {
        // return bruteForce(s, t);
        return optimised(s,t);
    }
};
