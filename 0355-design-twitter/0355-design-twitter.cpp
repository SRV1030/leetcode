class Twitter {
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timer;
    const int k = 10;
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<pair<int, int>> &userTweets = tweets[userId];
        int size = userTweets.size();
        for(int ind = size - 1; ind >= max(0, size - k); --ind){
            minHeap.push(userTweets[ind]);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        for(int followee : following[userId]){
            vector<pair<int, int>> &followeeTweets = tweets[followee];
            size = followeeTweets.size();
            for(int ind = size - 1; ind >= max(0, size - k); --ind){
                minHeap.push(followeeTweets[ind]);
                if(minHeap.size() > k)
                    minHeap.pop();
            }
        }
        vector<int> feed;
        
        while(!minHeap.empty()) {
            feed.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(feed.begin(), feed.end());
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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