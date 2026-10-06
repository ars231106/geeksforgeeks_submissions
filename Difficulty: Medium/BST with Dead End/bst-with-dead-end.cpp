/* Tree Node structure
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    bool canAttach(Node* root, int low, int high){
        if(root == NULL){
            return false;
        }
        
        if(abs(low - high) == 2){
            return true;
        }
        
        bool left = canAttach(root -> left, low, root -> data);
        bool right = canAttach(root -> right, root -> data, high);
        
        return left || right;
        
    }
    
    bool isDeadEnd(Node *root) {
        int boolresult = false;
        
        boolresult = canAttach(root, 0, INT_MAX);
        return boolresult;
    
    }
};