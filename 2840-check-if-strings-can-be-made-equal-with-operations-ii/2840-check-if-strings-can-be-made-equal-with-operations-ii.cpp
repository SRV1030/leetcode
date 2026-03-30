class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string o1, e1, o2, e2;
        for(int ind = 0; ind < s1.size(); ++ind){
            if(ind % 2){
                o1.push_back(s1[ind]);
                o2.push_back(s2[ind]);
            }
            else{
                e1.push_back(s1[ind]);
                e2.push_back(s2[ind]);
            }
        }
        sort(o1.begin(), o1.end());
        sort(o2.begin(), o2.end());
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        return o1 == o2 && e1 == e2;
    }
};