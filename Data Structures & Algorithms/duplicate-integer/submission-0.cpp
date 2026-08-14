class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = (int)nums.size() - 1;
        for(int k = 0; k < j; k++){
            if(nums[k]==nums[k+1]){
                return true;
            }
        }
        return false;
    }
};