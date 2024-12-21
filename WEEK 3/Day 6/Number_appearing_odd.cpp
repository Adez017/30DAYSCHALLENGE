class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //bruteforece approach
        //use a map to map the values with frequency
        
        unordered_map<int,int> mpp;
        for (int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        //check if an element had frequency 1 
        //simply return it 
        for (auto num : mpp){
            if(num.second == 1){
                return num.first;
                break;
            }

        }
        //never be executed but we had to return something 
        //thats why -1 
        return -1;
        //optimal using the bit manipulation
        //key concept : Xor of two same number is always the 0 
        //so the result will always had the numnbers which frequency will be one
        // int result = 0;
        // for (int num : nums) {
        //     result ^= num;
        // }
        // return result;
    }
};