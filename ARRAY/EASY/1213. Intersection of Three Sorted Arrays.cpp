auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool isPresent(vector<int> &arr, int element){
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == element){
                return true;
            }
            if(element <= arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        for(int i = 0; i < arr1.size(); i++){
            int element = arr1[i];
            if(isPresent(arr2, element) && isPresent(arr3, element)){
                result.push_back(element);
            }
        }
        return result;
    }
};
