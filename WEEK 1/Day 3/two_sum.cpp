#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        //the solution as names two sum determine whether the sum of two elements is equal to target or not
        //Approach
        //1. place i at the begin 
        //2. j one step ahead of i 
        // check the sum of ith element and jth element for target
        //wherever found just return the index ;
        for(int i=0;i<n;i++){
            for(int j= i+1 ;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

