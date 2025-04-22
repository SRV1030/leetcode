class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> perm0;
        for (int i = 1; i < n; i++) {
            fact *= i;
            perm0.push_back(i);
        }
        --k;
        perm0.push_back(n);
        string permK = "";
        while(!perm0.empty()){
            int ind = k/fact;
            permK.push_back(perm0[ind]+'0');
            perm0.erase(perm0.begin()+ind);
            if(perm0.empty()) break;
            k%=fact;
            fact/=perm0.size();
        }
        return permK;
    }
};