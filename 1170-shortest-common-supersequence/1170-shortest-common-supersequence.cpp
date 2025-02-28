class Solution {
public:
    vector<vector<int>>dp;
    int size1,size2;
    int buildLCS(int i,int j,string str1, string str2){
        if(i==size1 || j==size2) return 0;
        int &ans=dp[i][j];
        if(ans!=-1) return ans;
        ans=0;
        if(str1[i]==str2[j])ans=1+buildLCS(i+1,j+1,str1,str2);
        else ans = max({buildLCS(i+1,j,str1,str2),buildLCS(i,j+1,str1,str2)});
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        size1=str1.length();
        size2=str2.length();
        dp.resize(size1+1,vector<int>(size2+1,-1)); 
        buildLCS(0,0,str1,str2);
        int i=0,j=0;
        string res;
        while(i<size1 && j<size2){
            if(str1[i]==str2[j]) {
                res+=str1[i++];
                ++j;
            }
            else if(dp[i+1][j]>dp[i][j+1]) res+=str1[i++];
            else res+=str2[j++];
        }
        while(i<size1)res+=str1[i++];
        while(j<size2)res+=str2[j++];
        return res;
    }
};





// class Solution {
// public:
//     vector<vector<string>>dp;
//     int size1,size2;
//     string findMinSuperSet(int i,int j,string str1, string str2){
//         if(i==size1){
//             return str2.substr(j);
//         }
//         if(j==size2){
//             return str1.substr(i);
//         }
//         string &ans=dp[i][j];
//         if(ans!="$") return ans;
//         ans=str1+str2;
//         if(str1[i]==str2[j])ans=str1[i]+findMinSuperSet(i+1,j+1,str1,str2);
//         else{
//             string pick_i=str1[i]+findMinSuperSet(i+1,j,str1,str2);
//             string pick_j=str2[j]+findMinSuperSet(i,j+1,str1,str2);
//             if(pick_i.size()<ans.size())ans=pick_i;
//             if(pick_j.size()<ans.size())ans=pick_j;
//         }
//         return ans;
//     }
//     string shortestCommonSupersequence(string str1, string str2) {
//         size1=str1.length();
//         size2=str2.length();
//         dp.resize(size1+1,vector<string>(size2+1,"$")); 
//         return findMinSuperSet(0,0,str1,str2);
//     }
// };