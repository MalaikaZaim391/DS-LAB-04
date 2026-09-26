#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void insertAtBeginning(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        n->next = head;
        temp->next = n;
        head = n;
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 1 || head == NULL) {
            insertAtBeginning(val);
            return;
        }
        Node* n = new Node(val);
        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr->next != head; i++) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }

    void deleteNode(int key) {
        if (head == NULL) return;

        Node* curr = head;
        Node* prev = NULL;

        if (head->data == key) {
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        prev = head;
        curr = head->next;
        while (curr != head) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void Display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head: " << head->data << ")" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    cll.insertAtPosition(3, 15);

    cout << "Inserting 10, 20, 30 at End, 5 at Beginning, 15 at Position 3: "<< endl;
	cout << endl; 
	cout << "Circular Linked List: ";
    cll.Display();

    cll.deleteNode(15);
    cout << "After deleting 15: ";
    cll.Display();

    return 0;
}
