class Solution {
public:
    bool hasCycle(ListNode *head) {
        //same tortoise and hare algorithm 
        //if fast is moving 2x to slow 
        //when slow reaches the end the fast will be x- steps of slow 
        //if they meet that mean there is cycle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
            
        
        }
        
        return false;
        

        
    }
};