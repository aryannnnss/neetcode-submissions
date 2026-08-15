class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result; // Create the 2D vector to store answers
        
        // 1. Sort the array (crucial for the two-pointer method)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // 2. Outer loop to anchor the first number
        for (int i = 0; i < n - 2; i++) {
            
            // Skip duplicate anchor values to avoid identical triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            // 3. Initialize the two pointers
            int j = i + 1;       // Left pointer starts just after the anchor
            int k = n - 1;       // Right pointer starts at the very end
            
            // 4. Squeeze the pointers together
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    // Sum is too small, move left pointer up to increase it
                    j++;
                } else if (sum > 0) {
                    // Sum is too large, move right pointer down to decrease it
                    k--;
                } else {
                    // Found a valid triplet, add it to our results
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates for the left and right pointers
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    
                    // Move both pointers inward after finding a match
                    j++;
                    k--;
                }
            }
        }
        
        // 5. Return the 2D vector
        return result;
    }
};