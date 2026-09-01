/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int height(Node* root, bool &valid){
        if(root == NULL){
            return 0;
        }
        
        int leftside = height(root -> left, valid);
        int rightside = height(root -> right, valid);
        
        
        if(abs(leftside - rightside) > 1){
            valid = 0;
        }
        
        return 1 + max(leftside, rightside);
    }
    
    bool isBalanced(Node* root) {
        bool valid = true;
        height(root, valid);
        return valid;
        
    }
};