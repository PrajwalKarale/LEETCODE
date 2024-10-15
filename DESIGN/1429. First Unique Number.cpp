#pragma GCC optmize ("O12")
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class FirstUnique {
public:
    queue<int>q;
    unordered_map<int,int>mp;
    FirstUnique(vector<int>& nums) {
        for(int &num: nums){
            add(num);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && mp[q.front()] > 1){
            q.pop();
        }
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
    
    void add(int value) {
        if(mp.find(value) == mp.end()){
            q.push(value);
        }   
        mp[value]+=1;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
