class Solution {
public:
    Node* reverseBetween(int a, int b, Node* head) {

        if (head == nullptr || a == b)
            return head;

        Node* prev = nullptr;
        Node* curr = head;
        Node* future = nullptr;

        int pos = 1;

        while (pos < a) {
            prev = curr;
            curr = curr->next;
            pos++;
        }

        Node* before = prev;
        Node* first = curr;

        while (pos <= b) {
            future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
            pos++;
        }

        if (before == nullptr)
            head = prev;
        else
            before->next = prev;

        first->next = curr;

        return head;
    }
};