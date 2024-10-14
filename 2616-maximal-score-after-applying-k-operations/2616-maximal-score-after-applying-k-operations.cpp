class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto&i:nums)pq.push(i);
        long long c=0;
        while(!pq.empty() && k--){
            int i=pq.top();
            c+=i;
            pq.pop();
            pq.push(ceil((double)i/3.0));
        }
        return c;
    }
};