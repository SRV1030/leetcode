class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        char bf = '$' , p ='$';
        priority_queue<pair<int,char>>pq;
        if(a)pq.push({a,'a'});
        if(b)pq.push({b,'b'});
        if(c)pq.push({c,'c'});
        string ans = "";
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            if(t.second == p && p == bf){
                if(pq.empty()) return ans;
                auto t2=pq.top();
                pq.pop();
                pq.push(t);
                bf = p;
                p = t2.second;
                ans+=p;
                --t2.first;
                if(t2.first){
                    pq.push(t2);
                }
                continue;
            }
            bf = p;
            p = t.second;
            ans+=p;
            --t.first;
            if(t.first)pq.push(t);
        }
        return ans;
    }
};