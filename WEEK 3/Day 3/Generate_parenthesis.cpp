class Solution {
public:

    void helper(vector<string>&v ,int n, int oc , int cc,string s)
    {
        //v : final result storage
        //n = given , oc = opening bracket, cc = closing,s = for the paternn
        
        //base case : if cc && oc = n i.e we had a valid parenthesis
        if(oc==n && cc==n){
            v.push_back(s);
            return;

        }
        // add "(" and again run for valid check
        if(oc<n){
            helper(v,n,oc+1,cc,s+"(");
        }
        //i.e we can add ) and call the helper
        if(cc<oc){
            helper(v,n,oc,cc+1,s+")");
        }
        //THIS ALWAYS ENSURES THAT OPENING NEVER EXEEDS n AND CLOSING LESS THEN
        // OPENING I.E. A VALID PARENTHESIS
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s = "";
        int oc =0 ;
        int cc=0;
        helper(v,n,oc,cc,s);
        return v;
        
        
    }
};