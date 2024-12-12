class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
    // code here
    //bruteforce approach 
    //1. store the node values in arr
    //iterate through the arr and check if or target is found 
    //store the values in a list
    //return the ans
    vector<int> arr;
    Node * temp = head;
    while(temp!= NULL ){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    vector<pair<int,int>>ans;
    for(int i=0;i<arr.size();i++){
        for(int j =i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                ans.push_back({arr[i],arr[j]});
            }
        }
    }
    return ans;
    }



    //optimised 
     //optimised approach 
       //using the binary search
        vector<pair<int, int>>ans;
        Node* left = head;
        Node* right = head;
        //point  right to the end of the list
        while (right->next!=nullptr)right=right->next; 
        //binary search approach 
        // same as if (l< r)
        while(left!=nullptr&&right!=nullptr&&left->data<right->data){
            int s = left->data + right->data;
            if( s == target) {
                ans.push_back({left->data,right->data});
                // left
                //r--
                right = right->prev;
                left = left->next; //l++
            } else if (s > target) {
                right = right->prev;
            } else {
                left = left->next;
            }
        }
        return ans;
};