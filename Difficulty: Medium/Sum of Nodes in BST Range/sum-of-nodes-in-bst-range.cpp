/* Binary Tree Node Structure
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
    int nodeSum(Node* root, int l, int r) {
        if(root == NULL){
            return 0;
        }

        int sum = 0;

        if(root->data >= l && root->data <= r){
            sum += root->data;
        }

        if(l <= root->data){
            sum += nodeSum(root->left, l, r);
        }

        if(r >= root->data){
            sum += nodeSum(root->right, l, r);
        }

        return sum;
    }
};
