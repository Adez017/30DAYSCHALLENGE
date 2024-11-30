class Solution {
public:
//pretty basics of binary search 
//1. divide the array into half 
//if the element is smaller then the middle value eliminate the left search space
//if greater eleminate the right search space
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0, high = n-1;
        return helper(nums,high,low,target);

        
    }
    int helper(vector<int>&arr,int high,int low,int target){
        if(low>high) return -1;
        int mid = (low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]){
            return helper(arr,high,mid+1,target);
        }
        return helper(arr,mid-1,low,target);
    }
};