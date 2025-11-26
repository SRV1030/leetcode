class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        if(len == 1)
            return to_string(stoi(n) - 1);

        vector<long long> candidates;
        long long pow10 = pow(10, len - 1);
        candidates.push_back(pow10 - 1);
        candidates.push_back(pow10 * 10 + 1);

        long long prefix = stoi(n.substr(0, (len + 1) / 2));
        for(int index = -1; index <= 1; ++index){
            string left = to_string(prefix + index);
            string pal = left + string(left.rbegin() + (len % 2), left.rend());
            candidates.push_back(stoll(pal));
        }

        long long num = stoll(n);
        long long closest = -1;

        for(auto cand : candidates){
            if(cand == num)
                continue;
            if (closest == -1 || abs(cand - num) < abs(closest - num) ||  (abs(cand - num) == abs(closest - num) && cand < closest)){ 
                closest = cand;
            }
        }
        return to_string(closest);
    }
};