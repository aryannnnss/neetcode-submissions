class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
        unordered_map<int , int> count;
        for(int n : nums){
            count[n]++;
        }
        vector<vector<int>>bucket(nums.size()+1);

        for(const auto&pair : count){
            int number = pair.first;
            int frequency = pair.second;
            bucket[frequency].push_back(number);
        }
        vector<int>result;
        for(int i = bucket.size()-1;i>=0;--i){
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size()==k){
                    return result;
                }
            }
        }
        return result;
        
    }
};
