/* Structure for Link list node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteK(Node* head, int K) {
        Node* p = head;
        Node* q = NULL;
        
        int count = 1;
        if(K == 1){
            return NULL;
        }
        
        while(p != NULL){
            if(count == K){
                q -> next = p -> next;
                delete p;
                p = q -> next;
                count = 1;
            }
            
            else{
                count++;
                q = p;
                p = p -> next;
                
            }
        }
        
        
        return head;
        
    }
};