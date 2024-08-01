/*
1. First approach comes to our mind is greedy but we can see that we cannot change the order hence we have to rule out Greedy.
2. We can see that there are options available that means we have to proceed with the recursive approach.*/
class Solution {
    int n;
    int ogWidth;
    int memo[1001][1001];
public:
    int solve(vector<vector<int>>& books, int i, int remainingWidth, int maxHeight){
        if(i >= books.size()){
            return maxHeight;
        }
        if(memo[i][remainingWidth] != -1){
            return memo[i][remainingWidth];
        }
        int bookHeight = books[i][1];
        int bookWidth = books[i][0];

        int keep = INT_MAX;
        int skip = INT_MAX;
        if(bookWidth <= remainingWidth){
            keep = solve(books, i+1,remainingWidth - bookWidth, max(maxHeight, bookHeight));
        }
        skip = maxHeight + solve(books, i+1, ogWidth - bookWidth, bookHeight);
        return memo[i][remainingWidth] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        memset(memo, -1, sizeof(memo));
        n = books.size();
        ogWidth = shelfWidth;
        int remainingWidth = shelfWidth;
        return solve(books, 0, remainingWidth, 0);
        return 0;
    }
};
