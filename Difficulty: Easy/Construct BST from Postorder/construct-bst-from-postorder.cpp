/* Structure of tree node
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
}; */

class Solution {
  public:
    Node* posttobst(Node* root, vector<int>& post, int &index, int low, int high){
        if(index < 0 || post[index] < low || post[index] > high){
            return NULL;
        }
        
        root = new Node(post[index]);
        index--;
        
        root -> right = posttobst(root -> right, post, index, root -> data, high);
        root -> left = posttobst(root -> left, post, index, low, root -> data);
        
        return root;
    } 
    
    Node* constructTree(vector<int>& post) {
        int index = post.size() - 1;
        Node* root = NULL;
        
        Node* result = posttobst(root, post, index, INT_MIN, INT_MAX);
        
        return result;
        
    }
};