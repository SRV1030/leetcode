class Solution {
    void separateNegativeAndPositive(vector<int> &nums,vector<int> &negatives, vector<int> &positives){
        for(auto& num : nums){
            if(num < 0)
                negatives.push_back(-num);
            else
                positives.push_back(num);
        }
        reverse(negatives.begin(), negatives.end());
    }

    long long productsLessThanValue(vector<int>& nums1, vector<int>& nums2, long long value){
        int index = nums2.size() - 1;
        long long count = 0;
        for(auto& num : nums1){
            while(index >= 0 && 1ll * num * nums2[index] > value)
                --index;
            count += (index + 1);
        }
        return count; 
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = 0, high = 1e10;
        vector<int> positives1, negatives1, positives2, negatives2;
        separateNegativeAndPositive(nums1, positives1, negatives1);
        separateNegativeAndPositive(nums2, positives2, negatives2);
        int negativeCount = negatives1.size() * positives2.size() + negatives2.size() * positives1.size();
        int sign = 1;
        if(k > negativeCount){
            k -= negativeCount;
        }
        else{
            k = (negativeCount - k + 1);
            swap(positives2, negatives2);
            sign = -1;
        }
        while(low < high){
            long long mid = (low + high) / 2;
            if(productsLessThanValue(positives1, positives2, mid) + productsLessThanValue(negatives1, negatives2, mid) >= k)
                high = mid;
            else 
                low = mid + 1;
        }
        return low * sign;
    }
};