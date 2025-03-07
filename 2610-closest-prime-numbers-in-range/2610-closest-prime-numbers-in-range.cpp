class Solution {
public:
    vector<bool>isPrime;
    void seieve(int right){
        isPrime.resize(right+1);
        for(int i=3;i<=right;i+=2)isPrime[i]=1;
        isPrime[2]=1;
        for(long long i=3;i<=right;i++){
            if(isPrime[i]){
                for(long long j=i*i;j<=right;j+=i)isPrime[j]=0;
            }
        }
    }
    vector<int> closestPrimes(int left, int right) {
        seieve(right);
        vector<int> primes;
        for(int i=left;i<=right;i++){
            if(isPrime[i]) primes.push_back(i);
        }
        if(primes.size()<2) return {-1,-1};
        vector<int>ans;
        int diff=INT_MAX;
        for(int i=0;i<primes.size()-1;i++){
            if((primes[i+1]-primes[i])<diff){
                diff=primes[i+1]-primes[i];
                ans={primes[i],primes[i+1]};
            }
        }
        return ans;
    }
};