#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

#include <emmintrin.h>

static bool _ = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
}();

class Solution {
public:
    void fill(queue<string>&q, unordered_set<string>&st, string &current){
        for(int i = 0; i < 4; i++){
            char ch = current[i];

            char increaseCh = ch == '9'? '0' : ch+1;
            char decreasedCh = ch == '0'? '9' : ch - 1;

            current[i] = increaseCh;
            // this is if the new combination is not present in the set of depends
            if(st.find(current) == st.end()){
                q.push(current);
                st.insert(current);
            }
            current[i] = decreasedCh;
            if(st.find(current) == st.end()){
                q.push(current);
                st.insert(current);
            }
            current[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(), deadends.end());
        if(st.find("0000") != st.end()){
            return -1;
        }
        queue<string>q;
        q.push("0000");
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string current = q.front();
                q.pop();
                if(current == target){
                    return level;
                }
                fill(q,st,current);
            }
            level++;
        }
        return -1;
    }
};
