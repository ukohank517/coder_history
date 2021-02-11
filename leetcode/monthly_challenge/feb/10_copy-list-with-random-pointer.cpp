#include <iostream>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = copyNext(head);

        copyRandom(head, ans, head, ans);

        return ans;
    }

    Node* copyNext(Node* head){
        if(head == NULL) return NULL;

        Node* ans = new Node(head->val);
        ans->next = copyNext(head->next);
        return ans;
    }

    void copyRandom(Node* baseH, Node* aimH, Node* base, Node* aim){
        if(base == NULL) return;

        Node* base_next = baseH;
        Node* aim_next = aimH;

        while(true){
            if(base_next == base->random){
                aim -> random = aim_next;
                break;
            }
            base_next = base_next -> next;
            aim_next = aim_next -> next;
        }

        copyRandom(baseH, aimH, base->next, aim->next);
    }
};