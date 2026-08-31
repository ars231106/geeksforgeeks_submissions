/* Binary Tree Node Structure
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void preorder(Node* root, int &count){
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return;
        }
        
        count++;
        preorder(root -> left, count);
        preorder(root -> right, count);
    }
    
    int countNonLeafNodes(Node* root) {
        int count = 0;
        preorder(root, count);
        return count;
        
    }
};