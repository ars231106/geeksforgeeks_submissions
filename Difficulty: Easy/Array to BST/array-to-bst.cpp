/*
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
    Node* arraytobst(Node* root, vector<int>& arr, int left, int right){
        if(left > right){
            return NULL;
        }
        
        int mid = left + (right - left) / 2;
        
        root = new Node(arr[mid]);
        
        root -> left = arraytobst(root -> left, arr, left, mid - 1);
        root -> right = arraytobst(root -> right, arr, mid + 1, right);
        
        return root;
    }
    
    Node* sortedArrayToBST(vector<int>& arr) {
        Node* root = NULL;
        
        Node* result = arraytobst(root, arr, 0, arr.size() - 1);
        
        return result;
        
    }
};