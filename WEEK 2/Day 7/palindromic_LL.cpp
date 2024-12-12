class Solution {
public:
bool isPalindrome(ListNode* head) {
    //bruteforce approach 
    vector<int> ls; // Create a vector to store the list values
    ListNode* temp = head;
    
    // Traverse the linked list and store its values in the vector
    while (temp != NULL) {
        ls.push_back(temp->val);
        temp = temp->next;
    }

    // Use two pointers to compare values from the start and end of the vector
    int left = 0;
    int right = ls.size() - 1;
    while (left < right) {
        if (ls[left] != ls[right]) { // If mismatch found, it's not a palindrome
            return false;
        }
        left++;
        right--;
    }

    // If no mismatches, it's a palindrome
    return true;
 }
};

//optmised approach using the hore and tortiose method 
//logic = if hore is moving 2x and tortoise x
//when tortoise reaches x dist. hore already  covered x + 1/2 
//agr a is at 2x and b at x speed 
// when b will be at the end then a will be x/2 becuase it cover the whole diatance and 
//will be at the again half distnace
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head== NULL || head->next == NULL){
            return true;
        }
        while (fast->next!= nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if the list is palindrome and we reverse half of list it will be identical 
        //ex 1221 part 12 | 21 and after reversing  12| 12
                                                    |   |
                                                slow    |
                                                        fast
                                                 
        ListNode* rev = reverse(slow->next);
        while (rev != nullptr) {
            if (head->val != rev->val) {
                reverse(rev);
                return false;
                //cheking both half values 
            }
            head = head->next;
            rev = rev->next;
        }
        // reverse(rev);
        return true;
    }
};