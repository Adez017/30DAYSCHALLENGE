class Solution{   
public:
    pair<int, int> get(int a, int b){
        //brute force approach using the bult in swap function
        swap(a,b);
        pair<int,int> ans;
        ans.first = a;
        ans.second = b;
        return ans;


        //using bit manipulation
        a = a^b;
        b = a^b;
        a = a^b;
        return {a,b};
    }
};