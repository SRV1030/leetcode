class Solution {
public:
    string countAndSay(int n) {
        string sequence = "1";
        for(int j=1;j<n;j++){
            string nextSequence = "";
            int c=1;
            for(int i=0;i<sequence.size()-1;i++){
                if(sequence[i]==sequence[i+1]) c++;
                else{
                    nextSequence+=to_string(c);
                    nextSequence.push_back(sequence[i]);
                    c=1;
                }
            }
            nextSequence+=to_string(c);
            nextSequence.push_back(sequence.back());
            sequence = nextSequence;
        }
        return sequence;
    }
};