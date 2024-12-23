class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng=size(g),ns=size(s);
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int i=0,j=0,cm=0;
        while(i<ng && j<ns){
            if(s[j]>=g[i]){
                ++cm;
                ++i;
            }
            ++j;
        }
        return cm;
    }
};