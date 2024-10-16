/*
    Time Complexity:
        1. We are visiting each and every characters of the string only once
        2. T.C -> O(a + b + c) ~ constant time
    Space Complexity:
        1. We have used maxHeap to store a,b,c we are pushing the same characters
        2. S.C -> O(1)

*/
class Solution {
public:
    typedef pair<int,char> pic;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pic>maxHeap;
        string result = "";

        if(a > 0){
            maxHeap.push({a, 'a'});
        }
        if(b > 0){
            maxHeap.push({b, 'b'});
        }
        if(c > 0){
            maxHeap.push({c, 'c'});
        }
        while(!maxHeap.empty()){
            int currentCharCount = maxHeap.top().first;
            char currentChar = maxHeap.top().second;
            maxHeap.pop();

            if(result.length() >= 2 && result[result.length() - 1] == currentChar && result[result.length() - 2] == currentChar){
                if(maxHeap.empty()){
                    break;
                }
                char nextChar = maxHeap.top().second;
                int nextCharCount = maxHeap.top().first;
                maxHeap.pop();
                result.push_back(nextChar);
                nextCharCount--;

                if(nextCharCount > 0){
                    maxHeap.push({nextCharCount, nextChar});
                }

            }else{
                currentCharCount--;
                result.push_back(currentChar);
            }
            if(currentCharCount > 0){
                maxHeap.push({currentCharCount, currentChar});
            }
        }
        return result;
    }
};
