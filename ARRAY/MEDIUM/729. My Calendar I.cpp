/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
public:
    vector<pair<int,int>>ranges;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        for(auto it: ranges){
            int rStart = it.first; // 10
            int rEnd = it.second; // 20
            if(start < rEnd && end > rStart){
                return false;
            }
        }
        ranges.push_back({start, end});
        return true;
    }
};
10 15 20 25
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

