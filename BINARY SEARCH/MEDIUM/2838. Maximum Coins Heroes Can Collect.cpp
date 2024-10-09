/*
    Time Complexity:
        1. Sorting takes O (m log m) time where m is sizeof monsters array
        2. T.C -> O(n log m) where n is the size of heroes array and m is the size of monsters array
    Space Complexity:
        1. S.C -> O(m) where m is the size of monsters array
*/
class Solution {
typedef pair<int,int>p;
typedef long long ll;
public:
    int binarySearch(vector<p>& monstersCoin, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target >= monstersCoin[mid].first) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        int n = heroes.size();
        int m = monsters.size();
        vector<p>monstersCoin;
        for(int i = 0; i < m; i++){
            monstersCoin.push_back({monsters[i], coins[i]});
        }   
        sort(monstersCoin.begin(), monstersCoin.end());
        vector<ll>coinSum(m, 0);
        coinSum[0] = monstersCoin[0].second;
        for(int i = 1; i < m; i++){
            coinSum[i] = coinSum[i - 1] + monstersCoin[i].second;
        }
        vector<ll>result;
        for(int i = 0; i < n; i++){
            int index = binarySearch(monstersCoin, 0, m - 1, heroes[i]);
            if(index == 0){
                result.push_back(0);
            }else{
                result.push_back(coinSum[index - 1]);
            }
        }
        return result;
    }
};
