class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int>result;
        vector<int>actualIndex;
        for(int i = 0 ; i < positions.size(); i++){
            actualIndex.push_back(i);
        }
        auto lambda = [&positions](int &i, int &j){
            if(positions[i] < positions[j]){
                return true;
            }
            return false;
        };

        sort(actualIndex.begin(), actualIndex.end(), lambda);
        for(int i = 0; i < actualIndex.size(); i++){
            cout << actualIndex[i] << " ";
        }
        //The stack consists the actual index of the robot
        stack<int>s;
        for(int &currentIndex: actualIndex){
            if(directions[currentIndex] == 'R'){
                s.push(currentIndex);
            }else{
                //directions[currentIndex] == L
                while(!s.empty() && (healths[currentIndex] > 0)){
                    int topIndex = s.top();
                    s.pop();
                    if(healths[topIndex] > healths[currentIndex]){
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        s.push(topIndex);
                    }else if(healths[topIndex] < healths[currentIndex]){
                        healths[topIndex] = 0;
                        healths[currentIndex] -= 1;
                    }else{
                        healths[topIndex] = 0;
                        healths[currentIndex] = 0;
                    }
                }
            }
        }
        for(int i = 0; i < healths.size(); i++){
            if(healths[i] > 0){
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
