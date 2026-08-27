/* Structure of Linked List Node
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        
        if(head -> next == NULL){
            return head;
        }
        
        vector<int> ans;
        Node* temp = head;
        while(temp != NULL){
            ans.push_back(temp -> data);
            temp = temp -> next;
        }
        
        temp = head;
        
        for(int i = ans.size() - 1; i>=0; i--){
            temp -> data = ans[i];
            temp = temp -> next;
        }
        
        return head;
    }
};