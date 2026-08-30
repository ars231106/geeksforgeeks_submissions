/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* curr, Node* prev){
        Node* future = NULL;
        
        while(curr != NULL){
            future = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = future;
        }
        
        return prev;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        Node* first = reverse(head1, NULL);
        Node* second = reverse(head2, NULL);
        
        Node* sumhead = new Node(0);
        Node* sumtemp = sumhead;
        
        int carry = 0;
        
        Node* temp1 = first;
        Node* temp2 = second;
        
        while(temp1 != NULL && temp2 != NULL){
            int sum = temp1 -> data + temp2 -> data + carry;
            Node* newNode = new Node(sum % 10);
            sumtemp -> next = newNode;
            sumtemp = newNode;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
            carry = sum / 10;
        }
        
        while(temp1 != NULL){
            int sum = temp1 -> data + carry;
            Node* newNode = new Node(sum % 10);
            sumtemp -> next = newNode;
            sumtemp = newNode;
            temp1 = temp1 -> next;
            carry = sum / 10;
            
        }
    
        while(temp2 != NULL){
            int sum = temp2 -> data + carry;
            Node* newNode = new Node(sum % 10);
            sumtemp -> next = newNode;
            sumtemp = newNode;
            temp2 = temp2 -> next;
            carry = sum / 10;
        }
    
        while(carry){
            Node* newNode = new Node(carry % 10);
            sumtemp -> next = newNode;
            sumtemp = newNode;
            carry /= 10;
        }
    
        sumhead = reverse(sumhead -> next, NULL);
        while(sumhead != NULL && sumhead -> data == 0 && sumhead->next != NULL){
            Node* temp = sumhead;
            sumhead = sumhead -> next;
            delete temp;
        }
        return sumhead;
    }
};