class Solution {
public:
    bool canChange(string start, string target) {
        queue<pair<char,int>>sq,tq;
        for(int i=0;i<size(start);++i){
            if(start[i]!='_')sq.push({start[i],i});
            if(target[i]!='_')tq.push({target[i],i});
        }
        if(sq.size()!=tq.size()) return false;

        while(!sq.empty()){
            auto [sc,si] = sq.front();
            sq.pop();
            auto [tc,ti] = tq.front();
            tq.pop();

            if(sc!=tc || (sc=='L' && si<ti) || (sc=='R' && si>ti)) return false;
        }
        return true;
    }
};