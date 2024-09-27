class MyCalendarTwo {
public:

    typedef pair<int,int>p;
    vector<p>totalBookings;
    vector<p>doubleBookings;

    MyCalendarTwo() {
        
    }

    bool checkOverlap(int pairFirst, int pairSecond, int start, int end){
        return max(pairFirst, start) < min(pairSecond, end);
    }
    pair<int,int> findOverlappedRegion(int pairFirst, int pairSecond, int start, int end){
        return {max(pairFirst, start), min(pairSecond, end)};
    }

    bool book(int start, int end) {
        for(auto &pair: doubleBookings){
            if(checkOverlap(pair.first, pair.second, start, end)){
                return false;
            }
        }
        for(auto &pair: totalBookings){
            if(checkOverlap(pair.first, pair.second, start, end)){
                doubleBookings.push_back(findOverlappedRegion(pair.first, pair.second, start, end));
            }
        }
        totalBookings.push_back({start, end});
        return true;
    }
};

