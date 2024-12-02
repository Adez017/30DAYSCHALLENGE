//question : the question is check wheter the string can be achieved as goal after numebr of rotaions 
//the approach is simple 
// we can figure out that all the rotation will be in the s+s
//ex : s = abcde then s+s = abcdeabcde which contains all the roations
//if goal is there in the s+s then we can say that it is possible 
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string r = s+s;
        return r.find(goal)!= string ::npos;
        
        
        
    }
};