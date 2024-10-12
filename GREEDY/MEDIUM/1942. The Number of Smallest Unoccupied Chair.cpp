/*
    Time Complexity:
        1. Brute Force
            a. Sorting takes O(n * log(n))
            b. For loop takes O(n^2);
            c. T.C -> O(n^2) + O(n * log(n)) = O(n^2);
        2. Optimal
            a. Sorting takes O(n * log(n));
            b. We are traversing n elements and healp operations take log(n)
            c. T.C -> O(n * log(n))
    Space Complexity
        1. Brute Force
            a. We are not using any extra space so O(1)
        2. Optimal
            a. We are using two min Heaps which will contain n elements at worst
            b. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
};
class Solution {
public:
    int bruteForce(vector<vector<int>>& times, int targetFriend){
        int n = times.size();
        vector<int>targetTime = times[targetFriend];
        sort(times.begin(), times.end());
        vector<int>chairTime(n, 0);
        for(vector<int>&time: times){
            for(int i = 0; i < n; i++){
                if(chairTime[i] <= time[0]){
                    chairTime[i] = time[1];
                    if(time == targetTime){
                        return i;
                    }
                    break;
                }
            }
        }
        return 0;
    }
    typedef pair<int,int> pii;
    int optimal(vector<vector<int>>& times, int targetFriend){
        int n  = times.size();
        int targetArrivalTime = times[targetFriend][0];
        sort(times.begin(), times.end());

        priority_queue<pii, vector<pii>, greater<pii>>occupiedChair;
        priority_queue<int, vector<int>, greater<int>>freeChair;

        int chair = 0;
        for(int i = 0; i < n; i++){
            int arrival = times[i][0];
            int departure = times[i][1];
            while(!occupiedChair.empty() && arrival >= occupiedChair.top().first){
                freeChair.push(occupiedChair.top().second);
                occupiedChair.pop();
            }
            if(freeChair.empty()){
                occupiedChair.push({departure, chair});
                if(arrival == targetArrivalTime){
                    return chair;
                }
                chair++;
            }else{
                int availableChair = freeChair.top();
                freeChair.pop();
                if(arrival == targetArrivalTime){
                    return availableChair;
                }
                occupiedChair.push({departure, availableChair});
            }
        }
        return -1;
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // return bruteForce(times, targetFriend);
        return optimal(times, targetFriend);
    }
};
