/*
Time Complexity
    1. O(n) for converting vector into set where n is the number of words present in wordList
    2. The while loop will take O(wordLength * 26 * n) where n is the number of words present in the queue;
    3. T.C = O(n) + O(3*26*n) =  O(n)
Space Complexity
    1. Set of visited words
    2. Set of wordList
    3. Queue
    4. S.C -> O(n);
*/
class Solution {
public:
    typedef pair<string, int> p;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_set<string>s(wordList.begin(), wordList.end());
        
        // endWord should be present in wordList
        if(s.find(endWord) == s.end()){
            return 0;
        }
        unordered_set<string>visited;
        queue<p> q;
        q.push({beginWord, 1});
        visited.insert(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int currentLength = q.front().second;
            q.pop();
            int wordLength = word.length();
            if(word == endWord){
                return currentLength;
            }
            for(int i = 0; i < wordLength; i++){
                char og = word[i];
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(word == endWord){
                        return currentLength + 1;
                    }
                    if(visited.find(word) == visited.end() && s.find(word) != s.end()){
                        q.push({word, currentLength + 1});
                        visited.insert(word);
                    }
                }
                word[i] = og;
            }
        }
        return 0;
    }
};
