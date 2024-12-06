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
    int countInv(vector<int>&nums,int s,int e){
        int m=(s+e)/2,j=m+1,c=0;
        for(int i=s;i<=m;++i){
            while(j<=e && 1ll*nums[i]>1ll*2*nums[j])++j;
            c+=j-(m+1);
        }
        return c;
    }
    int mergeSort(vector<int>&nums,int s,int e){
        if(s>=e) return 0;
        int m=(s+e)/2,inv=0;
        inv+=mergeSort(nums,s,m);
        inv+=mergeSort(nums,m+1,e);
        inv+=countInv(nums,s,e);
        merge(nums,s,e);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,size(nums)-1);
    }
};