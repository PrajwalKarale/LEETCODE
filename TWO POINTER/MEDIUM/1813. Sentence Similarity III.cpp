/*
  Time Complexity:
    1. T.C -> O(m + n) where m = sentence1.length and n = sentence2.length()
  Space Complexity:
    1. S.C -> O(m + n) since 2 deques were created to store the words of sentence1 and sentence2
*/
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int s1Len = sentence1.length();
        int s2Len = sentence2.length();
        if(s1Len < s2Len){
            swap(sentence1,sentence2);
        }
        deque<string>v1;
        stringstream ss1(sentence1);
        string token;
        while(ss1 >> token){
            v1.push_back(token);
        }
        deque<string>v2;
        stringstream ss2(sentence2);
        while(ss2 >> token){
            v2.push_back(token);
        }
        // Finding the common prefix
        while(!v1.empty() && !v2.empty() && v1.front() == v2.front()){
            v1.pop_front();
            v2.pop_front();
        }
        //Finding the common suffix
        while(!v1.empty() && !v2.empty() && v1.back() == v2.back()){
            v1.pop_back();
            v2.pop_back();
        }
        return v2.empty();
    }
};
