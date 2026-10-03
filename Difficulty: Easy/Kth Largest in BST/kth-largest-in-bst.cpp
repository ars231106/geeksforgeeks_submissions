/* Structure of a Binary Tree Node
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
    void inorder_traversal(Node* root, int &k, int &result){
        if(root == NULL){
            return;
        }
        
        inorder_traversal(root -> right, k, result);
        
        k--;
        if(k == 0){
            result = root -> data;
            return;
        }
        
        inorder_traversal(root -> left, k, result);
        
    }
    
    int kthLargest(Node *root, int k) {
        int result = INT_MIN;
        inorder_traversal(root, k, result);
        
        return result;
        
    }
};