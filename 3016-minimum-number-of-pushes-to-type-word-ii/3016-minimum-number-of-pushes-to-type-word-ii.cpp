class Solution {
public:
    int minimumPushes(string word) {
        int push = 1;
        int res = 0, count = 0;
        vector<int> fr(26);
        priority_queue<int> minHeap;
        for(auto& ch : word)
            fr[ch - 'a']++;
        for(auto& f : fr)
            if(f)
                minHeap.push(f);
        while(!minHeap.empty()){
            if(count == 8){
                count = 0;
                push++;
            }
            res += minHeap.top() * push;
            minHeap.pop();
            ++count;
        }
        return res;
    }
};