/* Tree Node Structure
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
    void preorder(Node* root, int &sum){
        if(root == NULL){
            return;
        }
        
        sum = sum + (root -> data);
        preorder(root -> left, sum);
        preorder(root-> right, sum);
    }
    
    int sumBT(Node* root) {
        int sum = 0;
        preorder(root, sum);
        return sum;
    }
};