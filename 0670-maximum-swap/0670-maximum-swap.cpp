class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n=size(s);
        vector<int>ind(n);
        int mx = n-1;
        for(int j=n-1;j>=0;--j){
            if(s[j]>s[mx])mx=j;
            ind[j] = mx;
        }

        for(int i=0;i<size(s);++i){
            if(ind[i]!=i && s[ind[i]]!=s[i]){
                swap(s[i],s[ind[i]]);
                break;
            }
        }
        return stoi(s);
    }
};