/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    void preorder(Node* root, int &count){
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            count++;
            return;
        }
        
        preorder(root -> left, count);
        preorder(root -> right, count);
    }
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        int count = 0;
        preorder(root, count);
        return count;
    }
};