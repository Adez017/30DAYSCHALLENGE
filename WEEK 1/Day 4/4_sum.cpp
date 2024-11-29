class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //bruteforce Approach 
        //using the the same naive 
        //use the four loops to get the quadruple == target
        //use of set to store the unique elements 
        int n = nums.size();
        set<vector<int>>s ;
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                for(int k= j+1 ;k<n;;k++ ){
                    for(int l = k+1;l<n;l++){
                        long long sum = nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            s.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;


        //optimised apparoach 
        //same as the two and three sum 
        //using the search space conecpt 
        sort(nums.begin(),nums.end());
        int n  = nums.size();
        vector<vector<int>> ans;
        for ( int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for( int j =i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;

                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        
                        l--;
                    }
                }
                
            }
        }
        return ans;
        
    }
};