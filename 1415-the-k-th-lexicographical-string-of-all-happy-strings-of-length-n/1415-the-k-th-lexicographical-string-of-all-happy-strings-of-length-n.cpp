class Solution {
public:
    vector<string> sv;
    void buildS(string &s,int ind,int n){
        if(ind==n){
            sv.push_back(s);
            return;
        }
        for(char i : {'a', 'b', 'c'}){
            if(ind==0 || s.back()!=i){
                s.push_back(i);
                buildS(s,ind+1,n);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s="";
        buildS(s,0,n);
        return sv.size()>=k?sv[k-1]:"";
    }
};