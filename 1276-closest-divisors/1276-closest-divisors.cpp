class Solution {
public:
    vector<int> closestDivisors(int num) {
   vector<int> ans;
   long dif=INT_MAX;
   for(int i=1;i*i<=num+2;++i){
       if((num+1)%i==0){
           int j= (num+1)/i;
           if(abs(j-i)<dif){
               dif=abs(j-i);
               ans={i,j};
           }
       }
       if((num+2)%i==0){
           int j= (num+2)/i;
           if(abs(j-i)<dif){
               dif=abs(j-i);
               ans={i,j};
           }
       }
   }
   return ans;
}
};