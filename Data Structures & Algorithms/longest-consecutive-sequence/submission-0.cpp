class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int longest = 0;
        for(int num : nums){
            set.insert(num);
        }
        for(const auto&num : set){
            if(set.count(num-1) == 0){
                int firstnum = set.count(num);
                int currentcount = 1;
                int i = 1;
            while(set.count(num+i)!=0){
                 currentcount++;
                 i++;
            }
            longest = max(longest, currentcount);
            }
            
          
        }
        return longest;
        
    }
};
