class Solution {
public:
    int getUpperBound(int i,string s,vector<int> &leftOccur,vector<int> &rightOccur){
        int right = rightOccur[s[i]-'a'];
        for(int j=i;j<=right;j++){
            if(leftOccur[s[j]-'a']<i) return -1;
            right = max(right,rightOccur[s[j]-'a']);
        }
        return right;
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> leftOccur(26,INT_MAX),rightOccur(26);
        for(int i=0;i<s.size();i++){
            int ind = s[i]-'a';
            leftOccur[ind] = min(leftOccur[ind],i);
            rightOccur[ind]=i;
        }
        vector<string> answer;
        int right = -1;
        for(int i=0;i<s.size();i++){
            int charInd = s[i]-'a';
            if(i==leftOccur[charInd]){
                int nextRight = getUpperBound(i,s,leftOccur,rightOccur);
                if(nextRight!=-1){
                    if(i>right)answer.push_back("");
                    right=nextRight;
                    answer.back()=s.substr(i,right-i+1);
                }
            }
        }
        return answer;
    }
};