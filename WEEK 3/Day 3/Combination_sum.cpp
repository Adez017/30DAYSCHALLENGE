class Solution {
public:

    void Combination_(int ind , int target , vector<int> & arr, vector<vector<int>>&ans,vector<int> &ds){
        if(ind == arr.size()){
            //if(ind == size) i.e. we had iterated over all the elements 
            if(target==0){
                //we had the combination that has sum = target
                ans.push_back(ds);//valid pair as we have acheived the target ==0
            }
            return;//else backtrack to the previous 
        }
        if(arr[ind]<=target){
            //valid check for target
            ds.push_back(arr[ind]);
            Combination_(ind,target-arr[ind],arr,ans,ds);
            //valid Picked 
            ds.pop_back();
        }
        Combination_(ind+1,target,arr,ans,ds);//notpicked condition
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        Combination_(0,target,candidates,ans,ds);
        return ans;
        
    }
};