class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, 'a');

        vector<int> fixed(n + m - 1);

        for(int i = 0; i < n; ++i){
            if(str1[i] == 'T'){
                for(int nxt = i; nxt < i + m; ++nxt){
                    if(fixed[nxt] && s[nxt] != str2[nxt - i])
                        return "";
                    else{
                        s[nxt] = str2[nxt - i];
                        fixed[nxt] = 1;
                    }
                }
            }
        }

        for(int ind = 0; ind < n; ++ind){
            if(str1[ind] == 'F'){
                bool flag = false;
                int idx = -1;
                for(int nxt = ind + m - 1; nxt >= ind; --nxt){
                    if(s[nxt] != str2[nxt - ind])
                        flag = true;
                    if(idx == -1 && !fixed[nxt]){
                        idx = nxt;
                    }
                }
                if(flag)
                    continue;
                if(idx != -1)
                    s[idx] = 'b';
                else
                    return "";
            }
        }

        return s;
    }
};