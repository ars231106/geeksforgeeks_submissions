/* Structure of a Tree Node
class Node {
    int data;
    Node* right;
    Node* left;
    Node(int x){
        data = x;
        right = nullptr;
        left = nullptr;
    }
}; */

class Solution {
  public:
    void inorder_traversal(Node* root, int &k, int &sum){
        if(root == NULL){
            return;
        }
        
        inorder_traversal(root -> left, k, sum);
        
        if(k > 0){
            sum += root -> data;
        }
        k--;
        
        inorder_traversal(root -> right, k, sum);
    }
     
    int sum(Node* root, int k) {
        int sum = 0;
        inorder_traversal(root, k, sum);
        
        return sum;
    }
};