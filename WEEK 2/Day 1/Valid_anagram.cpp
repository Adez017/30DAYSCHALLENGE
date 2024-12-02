class Solution {
public:
    bool isAnagram(string s, string t) {
        //brute force approach
        //sort both and check if they are equal or not 
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
        

        //optimised aproach 
        //1. create a map and store the character of s by frequency 
        // for the same use decrease the element freq in t 
        // if  after the complete iteration any elemnt is still their then it will be false 
        //else true

        unordered_map<char,int> count ;
        for ( auto  it : s){
            count[it]++;
        }
        for ( auto it : t){
            count[it]--;
        }
        for ( auto it : count){
            if(it.second!=0){
                return false;
            }
        }
        return true;
        
    }
};