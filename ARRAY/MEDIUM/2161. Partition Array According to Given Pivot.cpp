/*
    Logic:
        1. First thing that comes to my mind is as follows. We can create three vectors where we
        will store elements smaller than pivot, equal to pivot, greater than pivot. 
        2. Second approach is what we can do is we can put two pointer i and j at starting and ending of the array
        and whenever an element less than pivot element is encountered i++ and element greater than pivot element is encountered j--
    Time Complexity:
        1. T.C -> O(n)
    Space Complexity:
        1. S.C -> O(1) since we are not count result vector as an auxiliary space
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int>approach1(vector<int>&nums, int pivot){
        vector<int>smallerPivot;
        vector<int>greaterPivot;
        vector<int>equalPivot;
        for(int &num: nums){
            if(num < pivot){
                smallerPivot.push_back(num);
            }else if(num == pivot){
                equalPivot.push_back(num);
            }else{
                greaterPivot.push_back(num);
            }
        }
        vector<int>result;
        for(int &num: smallerPivot){
            result.push_back(num);
        }
        for(int &num: equalPivot){
            result.push_back(num);
        }
        for(int &num: greaterPivot){
            result.push_back(num);
        }
        return result;
    }
    vector<int>approach2(vector<int>&nums, int pivot){
        int n = nums.size();
        vector<int>result(n, 0);
        int i = 0;
        int j = n - 1;
        int result_i = 0;
        int result_j = n - 1;
        while(i < n && j >= 0){
            if(nums[i] < pivot){
                result[result_i] = nums[i];
                result_i++;
            }else if(nums[i] > pivot){
                result[result_j] = nums[i];
                result_j--;
            }else{
                continue;
            }
            i++;
            j--;
        }
        return result;
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        return approach1(nums, pivot);
        return approach2(nums, pivot);
    }
};
