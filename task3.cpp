#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
    	data = 0;
    	next = NULL;
    	prev = NULL;
	}
    Node(int val) {
    	data = val;
    	next = NULL;
    	prev = NULL;
	}
};

class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 1 || head == NULL) {
            insertAtBeginning(val);
            return;
        }
        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr->next != head; i++) {
            curr = curr->next;
        }
        if (curr->next == head && pos > 2) {
            insertAtEnd(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }

    void deleteNode(int key) {
        if (head == NULL) return;

        Node* curr = head;
        do {
            if (curr->data == key) {
                if (curr->next == curr) {
                    delete curr;
                    head = NULL;
                    return;
                }
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                if (curr == head) {
                    head = curr->next;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void Display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head: " << head->data << ")" << endl;
    }
};

int main() {
    CircularDoublyLinkedList cdll;

    cdll.insertAtEnd(10);
    cdll.insertAtEnd(20);
    cdll.insertAtEnd(30);
    cdll.insertAtBeginning(5);
    cdll.insertAtPosition(3, 15);
    
    cout << "Inserting 10, 20, 30 at End, 5 at Beginning, 15 at Position 3: "<< endl;
	cout << endl;

    cout << "Circular Doubly Linked List: ";
    cdll.Display();

    cdll.deleteNode(20);
    cout << "After deleting 20: ";
    cdll.Display();

    return 0;
}
