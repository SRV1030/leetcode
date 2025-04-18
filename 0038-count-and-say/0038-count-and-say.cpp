class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prevSequence = countAndSay(n-1),current = "";
        int c=1;
        for(int i=0;i<prevSequence.size()-1;i++){
            if(prevSequence[i]==prevSequence[i+1]) c++;
            else{
                current+=to_string(c);
                current.push_back(prevSequence[i]);
                c=1;
            }
        }
        current+=to_string(c);
        current.push_back(prevSequence.back());
        return current;
    }
};