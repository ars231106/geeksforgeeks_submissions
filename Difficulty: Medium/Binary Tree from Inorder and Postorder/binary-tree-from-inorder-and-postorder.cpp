/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
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

    Node* postrecurssive(vector<int>& inorder, vector<int>& postorder, int left, int right, int &postidx){
        if(left > right){
            return NULL;
        }

        int root = postorder[postidx];
        int inidx = find(inorder, root, left, right);
        postidx--;

        Node* newNode = new Node(root);
        newNode -> right = postrecurssive(inorder, postorder, inidx + 1, right, postidx);
        newNode -> left = postrecurssive(inorder, postorder, left, inidx - 1, postidx);

        return newNode;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size() - 1;
        Node* root = postrecurssive(inorder, postorder, 0, inorder.size() - 1, postidx);
        return root;
    }
};