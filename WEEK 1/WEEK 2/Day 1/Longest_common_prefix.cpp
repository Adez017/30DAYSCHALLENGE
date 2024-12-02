//the question is simple you have to find the 
//longest common substring from begin that is common among all
//ex = Input: strs = ["flower","flow","flight"]
 // Output: "fl"
 // we can observe over here that fl is the longest common in all strings

 //approach 
 //the question itself helps to observe that we can check at one index strs[0][0] = "flower"
 // if the characters in strs[0][0] are findable in other that is strts[1],[2],etc we can simultaneoulsy 
 //add these numbers into over result 
 //can be done using any approaches i am following a simple two pointer traversal
 class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; //base case
        
        string res = "";
        for (int i = 0; i < strs[0].size(); i++) { //i.e. the string at index 0  size ="flower" size =6
            char c = strs[0][i]; //element at index zero {strs[0][0]='f}
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) { //it at any position it doesnt match with other strings 
                //simply return whatever is stored in res 
                    return res; 
                }
            }
            res += c; //if match simply add to the result
        }
        return res; 
    }
};
