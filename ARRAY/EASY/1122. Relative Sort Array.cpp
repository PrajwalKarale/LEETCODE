//Counting Sort

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        map<int,int> freq;

        for(int &num: arr1){
            freq[num]++;
        }
        int i = 0;
        for(int &num: arr2){
            while(freq[num]-- > 0){
                arr1[i] = num;
                i++;
            }
        }
        for(auto it: freq){
            int frequency = it.second;
            while(frequency > 0){
                arr1[i] = it.first;
                i++;
                frequency--;
            }
        }
        return arr1;
    }
};
