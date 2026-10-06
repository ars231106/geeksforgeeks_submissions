/* structure of Linked List Node
class LNode {
public:
    int data;
    LNode* next;

    LNode(int x) {
        data = x;
        next = nullptr;
    }
};

// Tree Node
class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int x) {
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    TNode *helper(LNode* &temp, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = start + (end - start + 1) / 2;
        
        TNode* left = helper(temp, start, mid - 1);
    
        TNode* root = new TNode(temp -> data);
        temp = temp -> next;
        
        root -> left = left;
        root -> right = helper(temp, mid + 1, end);
        
        return root;
    }
    
    TNode *sortedListToBST(LNode *head) {
        LNode *temp = head;
        int n = 0;
        
        while(temp != NULL){
            n++;
            temp = temp -> next;
        }
        
        temp = head;
        return helper(temp, 0, n - 1);
        
    }
};