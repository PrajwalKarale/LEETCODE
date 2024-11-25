auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
typedef pair<int,int> p;
class Twitter {
public:
    unordered_map<int, vector<p>> posts;
    unordered_map<int, set<int>>followers;
    int postId = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({postId, tweetId});
        postId++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed = posts[userId];
       
        for (auto it : followers[userId]) {
            vector<pair<int, int>> temp = posts[it];
            cout << temp.size() << endl;

            feed.insert(feed.end(), temp.begin(), temp.end());
        }
        sort(feed.begin(), feed.end(),
             [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                 return a.first > b.first;
             });
        vector<int> output;
        for (auto it : feed) {

            output.push_back(it.second);
        }
        if (output.size() > 10)
            return vector<int>(output.begin(), output.begin() + 10);
        return output;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto pt = find(followers[followerId].begin(), followers[followerId].end(), followeeId);
        if(pt != followers[followerId].end()){
            followers[followerId].erase(pt);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
