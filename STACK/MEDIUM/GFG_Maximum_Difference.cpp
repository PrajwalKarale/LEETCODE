//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        // Your code here
        vector<int>leftSmaller(n, 0);
        vector<int>rightSmaller(n, 0);
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] < arr[st.top()] ){
                rightSmaller[st.top()] = arr[i]; 
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[i] < arr[st.top()]){
                leftSmaller[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        int result = INT_MIN;
        for(int i = 0; i < n; i++){
            int difference = abs(leftSmaller[i] - rightSmaller[i]);
            result = max(result, difference);
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
