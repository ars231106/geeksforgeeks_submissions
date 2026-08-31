/* Structure of Tree Node
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
};*/

class Solution {
  public:
    void pre(Node* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        ans.push_back(root -> data);
        pre(root -> left, ans);
        pre(root -> right, ans);
    }
  
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        pre(root, ans);
        
        return ans;
    }
};