#include<bits/stdc++.h>
using namespace std;
//struct class to define custom data type
struct Node {
public:
    int data;
    Node* next;//pointer to the next node

    // Constructor accepting both data and a next pointer
    Node(int data1, Node* nextPtr = nullptr) {
        data = data1;
        next = nextPtr;
    }
};
//laymen approach to conevrt array to LL

Node* arraytoLL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}



//inserting node at the ending of a linked list
Node* insertAtEND(Node* head, int x) {
    Node* temp = head;
    while (temp) {
        if (temp->next == nullptr) {
            temp->next = new Node(x);
            break;
        }
        temp = temp->next;
    }
    return head;
}





void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



//inserting node at the starting of a linked list

Node* insertAtHead(Node* head, int ele) {
    Node* temp = new Node(ele);
    temp->next = head;
    return temp;
}

//insert at the Kth positon 
Node* insertAtKth(Node* head, int ele, int k) {
    if (head == NULL) {
        if (k == 1) return new Node(ele);
        else {
            return head;
        }
    }
    if (k == 1) {
        return new Node(ele, head);
    }
    int cnt = 1;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            Node* x = new Node(ele, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//main function
int main() {
    vector<int> arr = {1, 4, 5, 2, 3, 67, 23};
    Node* head = arraytoLL(arr);
    head = insertAtKth(head, 24, 3);
    printLL(head);
}
