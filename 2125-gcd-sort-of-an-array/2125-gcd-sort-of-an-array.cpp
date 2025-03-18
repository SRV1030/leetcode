class Solution {
public:
    vector<int>spf;
    void seieve(int n){
        spf.resize(n);
        for(int i=2;i<n;i++)spf[i]=i;
        for(int i=2;i*i<n;i++){
            if(spf[i]!=i) continue;
            for(int j=i*i;j<n;j+=i)spf[j]=i;
        } 
    }

    vector<int> getPrimeFactor(int n){
        vector<int>factors;
        while(n>1){
            factors.push_back(spf[n]);
            n/=spf[n];
        }
        return factors;
    }
    class DSU{
    private:
        int n;
        vector<int>parent,height;
    public:
        DSU(int n){
            this->n=n;
            parent.resize(n+1);
            iota(parent.begin(),parent.end(),0);
            height.resize(n+1,1);
        }
        int getParent(int x){
            while(x!=parent[x])
            {
                return parent[x]=getParent(parent[x]);
            }
            return x;
        }

        void unite(int u,int v){
            int s1=getParent(u);
            int s2=getParent(v);
            if(s1!=s2){
                if(height[s1]<height[s2]){
                    parent[s1]=s2;
                    height[s2]+=height[s1];
                }
                else {
                    parent[s2]=s1;
                    height[s1]+=height[s2];
                }
            }
        }
    };
    bool gcdSort(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        seieve(mx+1);
        DSU uf(mx+1);
        for(int num:nums){
            for(int i:getPrimeFactor(num))uf.unite(num,i);
        }
        vector<int>sortedArray(nums);
        sort(sortedArray.begin(),sortedArray.end());
        for(int i=0;i<nums.size();i++){
            if(uf.getParent(nums[i])!=uf.getParent(sortedArray[i])) return false;
        }
        return true;
    }
};