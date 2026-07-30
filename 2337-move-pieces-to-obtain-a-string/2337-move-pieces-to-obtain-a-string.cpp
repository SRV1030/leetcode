class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char, int>> sq, tq;
        for(int ind = 0; ind < start.size(); ++ind){
            if(start[ind] != '_')
                sq.push({start[ind], ind});
            if(target[ind] != '_')
                tq.push({target[ind], ind});
        }
        if(sq.size() != tq.size())
            return false;
        while(!sq.empty()){
            auto[sc, si] = sq.front();
            sq.pop();
            auto[tc, ti] = tq.front();
            tq.pop();
            if(sc != tc || (sc == 'L' && si < ti) || (sc == 'R' && si > ti))
                return false;
        }
        return true;
    }
};