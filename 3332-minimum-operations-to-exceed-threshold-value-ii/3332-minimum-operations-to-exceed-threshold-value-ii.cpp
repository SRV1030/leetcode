class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ops=0;
        priority_queue<long,vector<long>,greater<long>>pq(nums.begin(),nums.end());
        while(!pq.empty()){
            long i=pq.top();
            if(i>=k) return ops;
            ++ops;
            pq.pop();
            long j=pq.top();
            pq.pop();
            pq.push(i*2+j);
        }
        return ops;

    }
};