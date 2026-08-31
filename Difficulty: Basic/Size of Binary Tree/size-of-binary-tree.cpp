/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void preorder(Node* root, int &count){
        if(root == NULL){
            return;
        }
        
        count++;
        preorder(root -> left, count);
        preorder(root -> right, count);
        
    }
    int getSize(Node* root) {
        int count = 0;
        preorder(root, count);
        return count;
        
    }
};