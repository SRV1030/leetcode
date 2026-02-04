class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        auto cmp = [&](int a, int b){
            int ta = time[a][0] + time[a][2];
            int tb = time[b][0] + time[b][2];
            if(ta != tb)
                return ta < tb;
            return a < b;
        };

        priority_queue<int, vector<int>, decltype(cmp)> waitL(cmp), waitR(cmp);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> workL, workR;

        for(int worker = 0; worker < k; ++worker)
            waitL.push(worker);
        
        long long remaining = n, currentTime = 0, answer = 0;

        while(remaining > 0 || !waitR.empty() || !workR.empty()){
            while(!workL.empty() && workL.top().first <= currentTime){
                waitL.push(workL.top().second);
                workL.pop();
            }

            while(!workR.empty() && workR.top().first <= currentTime){
                waitR.push(workR.top().second);
                workR.pop();
            }

            if(!waitR.empty()){
                int worker = waitR.top();
                waitR.pop();
                currentTime += time[worker][2];
                answer = currentTime;
                workL.push({currentTime + time[worker][3], worker}); 
            }
            else if(!waitL.empty() && remaining > 0){
                int worker = waitL.top();
                waitL.pop();
                currentTime += time[worker][0];
                workR.push({currentTime + time[worker][1], worker}); 
                --remaining;
            }
            else{
                long long nextTime = LLONG_MAX;
                if (!workL.empty()) nextTime = min(nextTime, workL.top().first);
                if (!workR.empty()) nextTime = min(nextTime, workR.top().first);
                currentTime = nextTime;
            }
        }
        return answer;
    }
};