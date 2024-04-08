#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int result;
        int n = students.size();
        int students1 = 0;
        int students0 = 0;
        for(int i = 0; i < n; i++){
            if(students[i] == 1){
                students1++;
            }else{
                students0++;
            }
        }
        for(int i = 0; i < n; i++){
            if(sandwiches[i] == 1){
                if(students1 > 0){
                    students1--;
                }else{
                    result = n - i;
                    break;
                }
            }else{
                if(students0 > 0){
                    students0--;
                }else{
                    result = n - i;
                    break;
                }
            }
        }
        return result;
    }
};
