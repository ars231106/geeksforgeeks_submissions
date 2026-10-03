/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* preordertobst(Node* root, vector<int>& pre, int &i, int low, int high){
        if(i == pre.size() || pre[i] < low || pre[i] > high){
            return NULL;
        }
        
        root = new Node(pre[i]);
        i++;
        
        root -> left = preordertobst(root -> left, pre, i, low, root -> data);
        root -> right = preordertobst(root -> right, pre, i, root -> data, high);
        
        return root;
    }
    
    Node* preToBST(vector<int>& pre) {
        Node* root = NULL;
        int i = 0;
        
        Node* result = preordertobst(root, pre, i, INT_MIN, INT_MAX);
        return result;
    }
};