/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int find(vector<int>& inorder, int root, int left, int right){
        for(int i = left; i<= right; i++){
            if(inorder[i] == root){
                return i;
            }
        }
        
        return 0;
    }
    
    Node* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int &preidx){
        if(left > right){
            return NULL;
        }
        
        int root = preorder[preidx];
        int inidx = find(inorder, root, left, right);
        preidx++;
        
        Node* newNode = new Node(root);
        newNode -> left = helper(preorder, inorder, left , inidx - 1, preidx);
        newNode -> right = helper(preorder, inorder, inidx + 1, right, preidx);
        
        return newNode;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preidx = 0;
        Node* root = helper(preorder, inorder, 0, inorder.size() - 1, preidx);
        return root;
    }
};