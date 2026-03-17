class AuthenticationManager {
    unordered_map<string, int> mp;
    int time;
public:
    AuthenticationManager(int timeToLive) {
        time = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + time;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.count(tokenId)){
            if(mp[tokenId] > currentTime)
                mp[tokenId] = currentTime + time;
            else
                mp.erase(tokenId);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        for(auto itr = mp.begin(); itr != mp.end();){
            if(itr->second <= currentTime)
                itr = mp.erase(itr);   
            else
                ++itr;
        }
        return mp.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */