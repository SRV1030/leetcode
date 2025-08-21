class Solution {
public:
    void playGame(vector<int> &players,int k,int position = 0){
        if(players.size() == 1)
            return;
        position = (position + k) % players.size();
        players.erase(players.begin() + position);
        playGame(players, k, position);
    }
    int findTheWinner(int n, int k) {
        vector<int> players;
        for(int player = 1; player <=n; ++player)
            players.push_back(player);
        --k;
        playGame(players, k);
        return players[0];
    }
};