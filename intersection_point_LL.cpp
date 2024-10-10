#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node *getIntersectionNode(Node *head1, Node *head2) {
    while (head2 != NULL) {
        Node *temp = head1;
        while (temp) {

            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }

    return NULL;
}

int main() {
      Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);
      Node *head2 = new Node(3);
      head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = head1->next;
    Node *intersectionPoint = getIntersectionNode(head1, head2);
    if (intersectionPoint == NULL)
        cout << " No Intersection Point \n";
    else
        cout << "Intersection Point: " << intersectionPoint->data << endl;
}

