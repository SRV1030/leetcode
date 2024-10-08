class Solution {
public:unordered_map<int,string>mp;
    vector<string>res;
    void util(string d,int ind,string t=""){
        if(d.length()==ind) res.push_back(t);
        else{
            for(char i:mp[d[ind]]) util(d,ind+1,t+i);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return{};
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        util(digits,0);
        return res;        
    }
};
