class Solution {
public:
    string getPermutation(int n, int k) {
        int blockSize = 1;
        vector<int> perm;
        string res = "";
        for(int index = 1; index < n; ++index){
            blockSize *= index;
            perm.push_back(index);
        }
        perm.push_back(n);
        --k;
        while(!perm.empty()){
            int index = k / blockSize;
            res += to_string(perm[index]);
            perm.erase(perm.begin() + index);
            if(perm.empty())
                return res;
            k %= blockSize;
            blockSize /= perm.size();
        }
        return res;
    }
};