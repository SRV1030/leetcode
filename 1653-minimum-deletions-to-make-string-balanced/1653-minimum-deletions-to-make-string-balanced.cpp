class Solution {
public:
    int minimumDeletions(string s) {
        int size = s.size();
        vector<int> a(size), b(size);
        int ca = 0, cb = 0, mnDel = INT_MAX;;
        for(int index = 0; index < s.size(); ++index){
            int revIndex = size - index - 1;
            a[index] = ca;
            b[revIndex] = cb;
            if(s[index] == 'a')
                ++ca;
            if(s[revIndex] == 'b')
                ++cb;
        }
        for(int index = 0; index < s.size(); ++index){
            mnDel = min(mnDel, size - (a[index] + b[index] + 1));
        }
        return mnDel;
    }
};