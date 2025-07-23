class Solution {
public:
    // int gainAfterDelete(string &s, int score, string deleteString){
    //     int position = s.find(deleteString);
    //     if(position == string :: npos)
    //         return 0;
    //     s = s.erase(position, 2);
    //     return score + gainAfterDelete(s, score, deleteString);
    // }

    int gainAfterDelete(string &s, int score, string deleteString){
        int index = 0, gain = 0;
        for(auto& character: s){
            s[index++] = character;
            if(index > 1 && s[index - 2] == deleteString[0] && s[index - 1] == deleteString[1]){
                index -= 2;
                gain += score;
            }
        }
        s.resize(index);
        return gain;
    }
    int maximumGain(string s, int x, int y) {
        int score1 = x, score2 = y;
        string delete1 = "ab", delete2 = "ba";
        if(x < y){
            swap(score1, score2);
            swap(delete1, delete2);
        }
        int profit = gainAfterDelete(s, score1, delete1);
        profit += gainAfterDelete(s, score2, delete2);
        return profit;
    }
};