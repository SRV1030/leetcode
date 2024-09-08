class Solution {
public:
    string binary(int n){
        string b = "";
        while(n!=0){
            if(n&1)b = "1" + b;
            else b = "0" + b; 
            n>>=1;
        }
        return b;
    }
    string convertDateToBinary(string date) {
        return binary(stoi(date.substr(0,4)))+"-"+binary(stoi(date.substr(5,2)))+"-"+binary(stoi(date.substr(8,2)));
    }
};