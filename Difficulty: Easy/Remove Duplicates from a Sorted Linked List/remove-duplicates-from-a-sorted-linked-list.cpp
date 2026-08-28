/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* temp = head;
        Node* p = NULL;
        while(temp != NULL && temp -> next != NULL){
            if(temp -> data == temp -> next -> data){
                Node* q = temp -> next;
                temp -> next = q -> next;
                delete q;
            }
            
            else{
                temp = temp -> next;
            }
        }
        
        return head;
        
    }
};