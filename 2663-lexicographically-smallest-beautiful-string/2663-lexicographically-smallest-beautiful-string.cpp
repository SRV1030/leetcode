class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int size = s.size(), pos = -1;
        for(int ind = size - 1; ind >= 0 && pos == -1; --ind){
            int curr = s[ind] - 'a' + 1;
            while(curr < k && pos == -1){
                bool isPal = false;
                if((ind - 1 >= 0 && s[ind - 1] - 'a' == curr) || (ind - 2 >= 0 && s[ind - 2] - 'a' == curr))
                    isPal = true;
                if(!isPal){
                    s[ind] = curr + 'a';
                    pos = ind;
                }
                ++curr;
            }
        }
        
        if(pos == -1)
            return "";
        
        for(int ind = pos + 1; ind < size; ++ind){
            for(int ch = 0; ch < 3; ++ch){
                bool isPal = false;
                if((ind - 1 >= 0 && (s[ind - 1] - 'a') == ch) || (ind - 2 >= 0 && (s[ind - 2] - 'a') == ch))
                    isPal = true;
                if(!isPal){
                    s[ind] = (ch + 'a');
                    break;
                }
            }
        }

        return s;
    }
};