//T.C -> O(N*LogN)

#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int m, int force){
        int previous = position[0];
        int balls = 1;
        for(int i = 1; i < position.size(); i++){
            int current = position[i];
            if(current - previous >= force){
                balls++;
                previous = current;
            }
            if(balls == m){
                break;
            }
        }
        return balls == m;
    }

    int maxDistance(vector<int>& position, int m) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        sort(position.begin(), position.end());
        int result = 0;
        int minForce = 1;
        // maximum magnetic force that can exists.
        int maxForce = position[position.size() - 1] - position[0];
        while(minForce <= maxForce){
            int mid = minForce + (maxForce - minForce) / 2;
            if(canPlaceBalls(position, m, mid)){
                result = mid;
                minForce = mid + 1;
            }else{
                maxForce = mid - 1;
            }
        }
        return result;
    }
};
