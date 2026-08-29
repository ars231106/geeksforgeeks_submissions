/*Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class Solution {
  public:
    void removeLoop(Node* head) {
        Node* p = NULL;
        Node* temp = head;
        unordered_map<Node*, bool> visited;
        
        while(temp != NULL){
            if(visited[temp]){
                p -> next = NULL;
                return;
            }
            visited[temp] = true;
            p = temp;
            temp = temp -> next;
        }
    }
};

