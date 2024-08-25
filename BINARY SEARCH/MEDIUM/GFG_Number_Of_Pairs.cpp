//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  typedef long long ll;
  public:
    ll countNumberOfPairs(int x, vector<int>&brr, int bSize, vector<int> &freqBrr, vector<int>&arr){
        // if x == 0 x^y > y^x will never be true for any values of y
        if(x == 0){
            return 0;
        }
        // if x == 1 x^y > y^x only when y is 0 so returning number of 0 in brr
        if(x == 1){
            return freqBrr[0];
        }
        auto it = upper_bound(brr.begin(), brr.end(), x);
        ll ans = bSize - (it - brr.begin());
        ans += freqBrr[0] + freqBrr[1];
        
        if(x == 2){
            ans -= (freqBrr[3] + freqBrr[4]);
        }
        if(x == 3){
            ans += freqBrr[2];
        }
        return ans;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        int aSize = arr.size();
        int bSize = brr.size();
        sort(brr.begin(), brr.end());
        ll totalPairs = 0;
        
        vector<int>freqBrr(5,0);//{0,1,2,3,4}
        for(int i = 0; i < bSize; i++){
            if(brr[i] < 5){
                freqBrr[brr[i]]++;
            }
        }
        for(int i = 0; i < aSize; i++){
            ll pairs = countNumberOfPairs(arr[i], brr, bSize, freqBrr, arr);
            totalPairs += pairs;
        }
        return totalPairs;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
