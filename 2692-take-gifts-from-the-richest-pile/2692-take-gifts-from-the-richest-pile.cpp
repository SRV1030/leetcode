class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq(gifts.begin(),gifts.end());
        while(k--){
            int x=pq.top();
            pq.pop();
            pq.push(sqrt(x));
        }
        long long sm=0;
        while(!pq.empty()){
            sm+=pq.top();
            pq.pop();
        }
        return sm;
    }
};