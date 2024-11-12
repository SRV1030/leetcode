class Solution {
public:
    void merge(vector<int> &arr,int s,int e){
        int i=s,m=(s+e)/2,j=m+1;
        vector<int>t;
        while(i<=m && j<=e){
            if(arr[i]<=arr[j])t.push_back(arr[i++]);
            else t.push_back(arr[j++]);
        }
        while(i<=m)t.push_back(arr[i++]);
        while(j<=e)t.push_back(arr[j++]);
        
        for(int x=s,k=0;x<=e;x++)arr[x]=t[k++];
        
        return ;
    }

    int countInv(vector<int> &arr,int s,int e){
        int m = (s+e)/2,c=0;
        int j=m+1;
        for(int i=s;i<=m;++i){
            while(j<=e && 1ll*arr[i]>1ll*2*arr[j])++j;
            c+=j-(m+1);
        }
        return c;
    }

    long long  mergeSort(vector<int> &arr,int s,int e){
        if(s>=e) return 0;
        int inv =0;
        int m = (s+e)/2;
        inv+=mergeSort(arr,s,m);
        inv+=mergeSort(arr,m+1,e);
        inv+= countInv(arr,s,e);
        merge(arr,s,e);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};