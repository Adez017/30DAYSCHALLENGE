
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //bruteforce approach : 
        // simple use three pointers and serch for all possible solutions in the array 
        //store them in vector
        //sort them and then store as result (st)
        set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }//TC : O(N^3* (log N)) loops + the sorting 
            }
        }
    }


        int target = 0;
        //Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> output;
        //we will use set to get the unique solutions only 
        //set has the property that it store only elements
        //some what similar to searching 
        //check for target if samller elemnt the left search space 
        //if greater element the right search space
        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {// left serch space eliminated
                    j++;
                } else { //right search space eliminated
                    k--;
                }
            }
        }
        for(auto triplets : s)
            output.push_back(triplets);
        return output;
    }
};