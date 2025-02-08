auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class NumberContainers {
public:
    unordered_map<int,set<int>>numberToIndex;
    unordered_map<int,int>indexToNumber;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNumber.find(index) != indexToNumber.end()){
            int oldNumber = indexToNumber[index];
            numberToIndex[oldNumber].erase(index);
            if(numberToIndex[oldNumber].empty()){
                numberToIndex.erase(oldNumber);
            }
        }
        indexToNumber[index] = number;
        numberToIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numberToIndex.find(number) != numberToIndex.end()){
            return *(numberToIndex[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end
