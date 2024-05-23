
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};

ListNode* createLinkedListWithCycle() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    ListNode* node9 = new ListNode(9);
    ListNode* node10 = new ListNode(10);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    node10->next = node4;

    return head;
}

int main() {
    Solution sol;
    ListNode* head = createLinkedListWithCycle();

    bool hasCycle = sol.hasCycle(head);
    std::cout << "Has Cycle: " << (hasCycle ? "Yes" : "No") << std::endl;

    if (hasCycle) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        std::cout << "Cycle Start Node: " << slow->val << std::endl;
    }

    return 0;
}

