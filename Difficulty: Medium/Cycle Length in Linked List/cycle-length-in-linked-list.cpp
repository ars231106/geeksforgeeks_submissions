/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* fast = head;
        Node* slow = head;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast){
                break;
            }
        }
        
        if(fast == NULL || fast -> next == NULL){
            return NULL;
        }
        
        slow = head;
        
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        
        int length = 0;
        Node* addr = slow;
        slow = slow -> next;
        fast = fast -> next;
        length = 1;
        
        while(slow != addr){
            length++;
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return length;
    }
};