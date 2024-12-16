class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [&](double p,double t){
            return (p+1)/(t+1)-(p/t);
        };
        priority_queue<pair<double,vector<int>>>pq;
        double total=0;
        for(auto&i:classes){
            total+=(double)i[0]/i[1];
            pq.push({profit(i[0],i[1]),{i[0],i[1]}});
        }
        while(extraStudents--){
            auto[added_prof,i]=pq.top();
            pq.pop();
            total+=added_prof;
            pq.push({profit(i[0]+1,i[1]+1),{i[0]+1,i[1]+1}});
        }
        return total/classes.size();
    }
};