class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>m;

        for(auto i:s){
            m[i]++;
        }
        priority_queue<pair<int,char>>p;
         for(auto i:m){
             p.push({i.second,i.first});
         }
         while(!p.empty()){
             int n=p.top().first;
             while(n--){
                 ans+=p.top().second;
             }
             p.pop();
         }
         return ans;
    }
};