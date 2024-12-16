class Solution {
public:
    void helper(int ind,vector<int>given ,vector<int>&arr,vector<vector<int>>&ds){
        ds.push_back(arr);
        //leyman approach easy to understand
        for(int i=ind;i<given.size();i++){
            if(i>ind &&given[i]==given[i-1]) continue;
            //ensuring not duplicates 
            if(i==given.size()) break;
            arr.push_back(given[i]);
            helper(i+1,given,arr,ds);
            arr.pop_back();
            
        }
        

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int>ds;
        sort(nums.begin(), nums.end());
        helper(0,nums,ds,ans);
        return ans;
          
        
        
        
        
    }
};