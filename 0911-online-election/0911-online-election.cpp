class TopVotedCandidate {
    map<int, int> winner;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> votes;
        int maxVotes = -1, maxVotePerson = -1;
        for(int index = 0; index < persons.size(); ++index){
            votes[persons[index]]++;
            if(votes[persons[index]] >= maxVotes){
                maxVotes = votes[persons[index]];
                maxVotePerson = persons[index];
            }
            winner[times[index]] = maxVotePerson;
        }
    }
    
    int q(int t) {
       if(winner.count(t)){
        return winner[t];
       }
       auto itr = prev(winner.upper_bound(t));
       return itr->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */