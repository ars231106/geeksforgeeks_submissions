/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node* first = new Node(0);
        first -> next = head;
        head = first;
        
        while(first -> next != NULL){
            
            int x = k;
            
            Node* second = first -> next;
            Node* prev = first;
            Node* curr = second;
            Node* future = NULL;
            
            while(x && curr != NULL){
                future = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = future;
                x--;
            }
            
            first -> next = prev;
            second -> next = curr;
            first = second;
        }
        
        first = head;
        head = head -> next;
        delete first;
        
        return head;
    }
};