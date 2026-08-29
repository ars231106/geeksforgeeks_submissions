/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */

class Solution {
  public:
    bool detectLoop(Node* head) {
        Node* temp = head;
        unordered_map<Node*, bool> visited;
        
        while(temp != NULL){
                if(visited[temp]){
                    return true;
                }
            
            visited[temp] = true; 
            temp = temp -> next;
            
        }

        return false;
        
    }
    
};

        
        