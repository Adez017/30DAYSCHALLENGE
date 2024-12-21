class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < (1 << n); i++) {  // Iterate over all 2^n combinations
            vector<int> subset;  // Store the current subset
            for (int j = 0; j < n; j++) {  // Check each bit
                if (i & (1 << j)) { 
                    subset.push_back(nums[j]);  // Add nums[j] to the subset
                }
            }
            ans.push_back(subset);  // Add the subset to the answer
        }
        
        return ans;
    }
};
