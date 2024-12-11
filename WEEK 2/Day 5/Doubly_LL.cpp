#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1, Node* prev1 = nullptr, Node* next1 = nullptr) {
        data = data1;
        prev = prev1;
        next = next1;
    }

};
Node* arraytoDLL(vector<int> arr){
    Node* head  = new Node(arr[0]);
    Node* prev = head;
    for( int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],prev);
        prev->next = temp;
        prev = temp;
    }
    return head;


}

Node* deleteHeadDLL(Node* head){
    if(head == NULL || head->next== NULL){
        return NULL;
    } 
    Node* prevs = head;
    head = head->next;
    head->prev=nullptr;
    prevs->next=nullptr;
    return head;


}

Node* deleteTailDLL(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* ele = head;
    while(ele->next!=NULL){
        ele = ele->next;
    }
    Node* prev = ele->prev; 
    prev->next = nullptr;
    ele->prev = nullptr;
    delete ele;
    return head;


}

Node* deletekthDLL(Node* head,int k){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    int cnt =0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp =temp->next;
    }
    Node* prev = temp->prev;
    Node* next = temp->next;

    //if k=1 that means there is single element
    if(prev ==NULL && next ==NULL){
        delete temp;
        return NULL;
    }
    //if the kth element is head
    else if(prev==NULL){
        deleteHeadDLL(head);
        return head;
    }
    //if the kth element is tail
    else if(next == NULL){
        deleteTailDLL(head);
        return head;

    }
    //the case remaining kth element in between 
    
        prev->next = prev->next->next;
        next->prev = next->prev->prev;
        temp->next = nullptr;
        temp->prev= nullptr;
        delete temp;
        return head;
    
}
void deleteNode(Node* temp){
    Node* prev = temp->prev;
    Node* next = temp->next;
    if(next == NULL){
       prev->next = nullptr;
       temp->prev = nullptr;
       free(temp);
       return;

    }
    prev->next = next;
    next->prev = prev;
    temp->prev= temp->next = nullptr;
    free(temp);
}

Node* insertAtheadDLL(Node* head, int val){
    Node* newHead = new Node(val,nullptr,head);
    head->prev = newHead;
    return newHead;
}
Node* insertAtTailDLL(Node* head,int val){
    if(head->next == NULL){
        return insertAtheadDLL(head,val);
    }
    Node* tail = head;
    while(tail->next!= NULL){
        tail = tail->next;
    }
    Node* prev = tail->prev;
    Node* temp= new Node (val,prev,tail);
    prev->next = temp;
    tail->prev = temp;
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data <<  " ";
        head = head->next;
    }
}

int main(){
    vector<int> arr = {1,4,56,7,8};
    Node* head = arraytoDLL(arr);
    head = insertAtTailDLL(head,10);
    print(head);

} 