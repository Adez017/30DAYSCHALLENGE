class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //bruteforce approach
        if(head== NULL || head->next == NULL){
            return head;
        }
        int cnt =0;
        ListNode* temp = head;
        while(temp!= NULL){
            cnt++;
            temp = temp->next;
        }
        //middle points to the middle node
        int middle = (cnt/2)+1; 
        temp = head;
        while(temp!=NULL){
            middle--;
            //till the node before the middle
            if(middle==0) break; // that is we reached the middle node
            temp= temp->next;
        }
        return temp;


        //optimised
        //Tortoise and horse method 
        //the main logic is if a is traveling with 2x speed
       // b is traveling with x speed 
        //the distance b cover will be half of the a 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
        
    }
};
