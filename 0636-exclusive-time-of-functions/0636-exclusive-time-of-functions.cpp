class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n);
        stack<vector<int>> st;

        for(auto& log : logs){
            stringstream str(log);
            string id, event, time;
            getline(str, id, ':');
            getline(str, event, ':');
            getline(str, time, ':');
            if(event == "start"){
                st.push({stoi(id), stoi(time)});
            }
            else{
                int _time = stoi(time);
                vector<int> prev = st.top();
                st.pop();
                result[prev[0]] += _time - prev[1] + 1;
                if(!st.empty())
                    result[st.top()[0]] -= _time - prev[1] + 1;
            }
        }
        return result;
    }
};