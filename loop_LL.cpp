
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};
bool detectLoop(Node* head) {
    unordered_set<Node*>st;
    while (head != nullptr) {
        if (st.find(head) != st.end())
            return true;
        st.insert(head);
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
