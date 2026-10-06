/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* findLCA(Node* root, Node* n1, Node* n2) {
        if(root == NULL){
            return NULL;
        }
        
        if(n1 == root || n2 == root){
            return root;
        }
        
        
        Node* leftLCA = findLCA(root -> left, n1, n2);
        Node* rightLCA = findLCA(root -> right, n1, n2);
        
        if(leftLCA != NULL && rightLCA != NULL){
            return root;
        }
        
        else if(leftLCA != NULL && rightLCA == NULL){
            return leftLCA;
        }
        
        else{
            return rightLCA;
        }
        
    }
};