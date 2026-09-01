/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    vector<int> bfs(Node* root, vector<int>& ans){
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int max = INT_MIN;
            
            for(int i = 0; i < size; i++){
                Node* temp = q.front();
                q.pop();
                
                if(temp -> data > max){
                    max = temp -> data;
                }
                
                if(temp -> left){
                    q.push(temp -> left);
                }
                
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
            
            ans.push_back(max);
        }
        
        return ans;
    }
  
    vector<int> largestValues(Node* root) {
        vector<int> ans;
        ans = bfs(root, ans);
        return ans;
    }
};