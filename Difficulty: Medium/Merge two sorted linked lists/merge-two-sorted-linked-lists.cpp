/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
            Node* head = new Node(0);
            Node* tail = head;
            
            while(head1 != NULL && head2 != NULL){
                if(head1 -> data <= head2 -> data){
                    tail -> next = head1;
                    head1 = head1 -> next;
                    tail = tail -> next;
                    tail -> next = NULL;
                }
                
                else{
                    tail -> next = head2;
                    head2 = head2 -> next;
                    tail = tail -> next;
                    tail -> next = NULL;
                }
            }
            
            if(head1){
                tail -> next = head1;
            }
            
            if(head2){
                tail -> next = head2;
            }
            
            tail = head;
            head = head -> next;
            delete tail;
            
            return head;    
        
    }
};