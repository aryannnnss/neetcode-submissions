class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> P(n);
        P[0] = 1;
        for(int i = 1; i < n; i++) {
            P[i] = P[i-1] * nums[i-1];
        }

        vector<int> S(n);
        S[n-1] = 1;
        for(int j = n - 2; j >= 0; j--) {
            S[j] = S[j+1] * nums[j+1];
        }

        vector<int> product(n);
        for(int i = 0; i < n; i++) {
            product[i] = P[i] * S[i];
        }
        return product;
    }
};
