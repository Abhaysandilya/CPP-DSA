#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void hashAndRemove(Node* head) {
    unordered_set<Node*> st;
    Node* prev = nullptr;
    while (head != nullptr) {
        if (st.find(head) == st.end()) {
            st.insert(head);
            prev = head;
            head = head->next;
        }
        else {
            prev->next = nullptr;
            break;
        }
    }
}

int main() {
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = head->next->next;
    hashAndRemove(head);
    printList(head);
    return 0;
}

