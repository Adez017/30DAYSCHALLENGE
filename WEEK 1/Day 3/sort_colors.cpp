#include <vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {

        //bruteforce : direct use any sort algo or sort() 😁
        //optimsed:
        //approach 
        //we know that there will be only three no. 1 , 0 , 2
        //we know if the first elemnt is 0 no need 
        //second  after all 0 exhuasted there should be 1 and so on 
        //we can search in the array where the elements are or not 
        //this give a idea of binary search
        int low=0,mid =0,high =nums.size()-1;
        while(mid<=high){
            if (nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
        
    }
    
};