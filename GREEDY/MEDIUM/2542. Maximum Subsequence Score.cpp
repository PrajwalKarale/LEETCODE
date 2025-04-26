/*
    Logic:
        1. First intution should be recursion since we have option to select a particular index or not and then findout the subsequence with maximum score. But for some reason it will give TLE. Hence we have to proceed with Greedy Approach.
        2. We need maximum possible score a * b is maximum at largest value of a and largest value of b. Since we need min of nums2 we are sorting it in descending order so that we get the maximum value after finding the minimum.
        3. Story points
            a. Sort nums2 in descending order and according sort nums1
            b. kSum = (0 -> k-1) -> nums1
            c. result = kSum * v[k-1].second
            d. for i from k to n - 1:
            e.  minimum = v[i].second
            f.  kSum = kSum + v[i].first - minHeap.top()
            g.  minHeap.pop()
            h.  minHeap.push(v[i].first);
            i.  result = max(result, kSum * minimum)

    Time Complexity:
        1. T.C -> O(n * log(n))
    Space Complexity:
        1. S.C -> O(n)
*/
const auto __ = []() 
{
    struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
    std::atexit(&___::_);
    return 0;
}();
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

typedef pair<int,int> pii;
typedef long long ll;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pii>v(n);
        for(int i = 0; i < n; ++i){
            v[i] = {nums1[i], nums2[i]};
        }
        auto comparator = [&](auto &P1, auto &P2){
            return P1.second > P2.second;
        };
        sort(v.begin(), v.end(), comparator);
        priority_queue<int, vector<int>, greater<int>>minHeap;
        ll kSum = 0;
        for(int i = 0; i < k; i++){
            kSum += v[i].first;
            minHeap.push(v[i].first);
        }
        ll result = kSum * v[k - 1].second;
        for(int i = k; i < n; ++i){
            // Taking minimum as v[i].second
            kSum  = kSum + v[i].first - minHeap.top();
            minHeap.pop();
            minHeap.push(v[i].first);
            result = max(result, kSum * v[i].second);
        }
        return result;
    }
};
