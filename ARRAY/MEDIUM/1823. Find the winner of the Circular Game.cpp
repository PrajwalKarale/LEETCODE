/*
    Logic:
        1. Using simple simulation as they have told
        2. Using queue
    Time Complexity:
        1. usingSimulation has worst case T.C -> O(n^2) since erase function is used which takes O(n) time
        2. usingQueue has T.C -> O(n * k)
    Space Complexity:
        1. S.C -> O(n) since we used queue and vector to store n elements

*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int usingSimulation(int n, int k){
        vector<int>arr;
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }
        int i = 0;
        while(arr.size() > 1){
            int index = (i + k - 1)% arr.size();
            arr.erase(arr.begin() + index);
            i = index;
        }
        return arr[0];
    }
    int usingQueue(int n, int k){
        queue<int>q;
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        while(q.size() > 1){
            for(int count = 1; count <= k - 1; count++){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
    int findTheWinner(int n, int k) {
        // return usingSimulation(n, k);
        return usingQueue(n, k);
    }
};
