class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(auto&i:s){
            if(i!=']') st.push(i);
            else{
                string populate="", frequency="";
                while(st.top()!='['){
                    populate+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(populate.begin(),populate.end());
                if(st.empty()) return populate;
                while(!st.empty() && isdigit(st.top())){
                    frequency+=st.top();
                    st.pop();
                }
                reverse(frequency.begin(),frequency.end());
                int frequencyValue = stoi(frequency);
                while(frequencyValue--){
                    for(auto&i:populate)st.push(i);
                }
            }
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};