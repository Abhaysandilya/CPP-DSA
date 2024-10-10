
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
Node *reverse(Node *head) {
    Node *prev = nullptr, *curr = head, *next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *addTwoLists(Node *num1, Node *num2) {
    Node *res = nullptr, *curr = nullptr;
    int carry = 0;

    num1 = reverse(num1);
    num2 = reverse(num2);
    while (num1 != nullptr || num2 != nullptr || carry != 0) {
        int sum = carry;
        if (num1 != nullptr) {
            sum += num1->data;
            num1 = num1->next;
        }

        if (num2 != nullptr) {
            sum += num2->data;
            num2 = num2->next;
        }

        Node* newNode = new Node(sum % 10);

        carry = sum / 10;

          if(res == nullptr) {
            res = newNode;
              curr = newNode;
        }
          else {

            curr->next = newNode;
            curr = curr->next;
        }
    }

    return reverse(res);
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << "\n";
}

int main() {
    Node *num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);
    Node *num2 = new Node(9);
    num2->next = new Node(9);
    num2->next->next = new Node(9);

    Node *sum = addTwoLists(num1, num2);
    printList(sum);

    return 0;
}
