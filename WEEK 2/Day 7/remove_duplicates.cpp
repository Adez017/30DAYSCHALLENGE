class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        Node* temp = head;
        while(temp!= NULL && temp->next!= NULL){
            Node* nextn = temp->next;
            while(nextn!= NULL && nextn->data == temp->data){
                nextn = nextn->next;
            }
            temp->next = nextn;
            if(nextn) nextn->prev = temp;
            
            temp = temp->next;
        }
        return head;
    }
};