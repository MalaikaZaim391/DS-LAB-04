#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Singly {
public:
    Node* head;
    Node* tail;

    Singly() {
        head = NULL;
        tail = NULL;
    }
    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }
    void segregateEvenOdd() {
        if (head == NULL || head->next == NULL) return;
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;
        while (curr != NULL) {
            int val = curr->data;
            if (val % 2 == 0) {
                if (evenStart == NULL) {
                    evenStart = curr;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            } else {
                if (oddStart == NULL) {
                    oddStart = curr;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }

        if (evenStart == NULL || oddStart == NULL) return;
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
        tail = oddEnd;
    }

    void Display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Singly list;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cout << "Enter element " << i+1 << ": ";
        cin >> val;
        list.insertAtTail(val);
    }

    cout << "\nOriginal List: ";
    list.Display();

    list.segregateEvenOdd();

    cout << "Modified List: ";
    list.Display();

    return 0;
}
