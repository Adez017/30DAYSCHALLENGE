class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //aproach 
        //store the nums and their freq in the map 
        //map just maps the no . with freq  1 : 3 that means 1 has 3 occurance
        //use a vector pair to store this 
        //sort the pair wise to get the larget frequency wise 
        unordered_map<int , int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        //craeting a pair array 
        vector<pair<int,int>> vec ;
        for(auto it :freq){
            vec.push_back({it.second,it.first});
        }
        sort(vec.rbegin(),vec.rend());
        //fetching the top k most frequent elemnt
        //storing them in an array 
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(vec[i].second);

        }
        return res;


        
    }
};