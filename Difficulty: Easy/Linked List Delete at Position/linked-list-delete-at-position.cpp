/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(head == NULL){
            return NULL;
        }

        if(x == 1){
            Node* temp = head;
            head = head -> next;
            delete temp;
            return head;
        }

        head -> next = deleteNode(head -> next, x - 1);
        return head;
        
    }
};