#include <iostream>
#include <Windows.h>
using namespace std;

class List {
protected:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) {
            data = d;
            next = n;
        }
    };
    Node* head;
    int size;
public:
    List() {
        head = nullptr;
        size = 0;
    }
    ~List() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    virtual void insert(int x) = 0;
    virtual int remove() = 0;
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack : public List {
public:
    void insert(int x) override {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }
    int remove() override {
        if (isEmpty()) {
            cout << "���� �������!" << endl;
            return -1;
        }
        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }
};

class Queue : public List {
public:
    void insert(int x) override {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    int remove() override {
        if (isEmpty()) {
            cout << "����� �������!" << endl;
            return -1;
        }
        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Stack s;
    Queue q;
    int choice;
    int data;
    do {
        cout << "������� ��������:" << endl;
        cout << "1. �������� � ����" << endl;
        cout << "2. �������� � �����" << endl;
        cout << "3. �������� � �����" << endl;
        cout << "4. �������� � �����" << endl;
        cout << "5. ������� ����" << endl;
        cout << "6. ������� �����" << endl;
        cout << "0. �����" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "������ ���:" << endl;
            cin >> data;
            s.insert(data);
            break;
        case 2:
            data = s.remove();
            if (data != -1) {
                cout << "������� ���: " << data << endl;
            }
            break;
        case 3:
            cout << "������ ���:" << endl;
            cin >> data;
            q.insert(data);
            break;
        case 4:
            data = q.remove();
            if (data != -1) {
                cout << "������� ���: " << data << endl;
            }
            break;
        case 5:
            cout << "����:" << endl;
            s.print();
            break;
        case 6:
            cout << "�����:" << endl;
            q.print();
            break;
        case 0:
            cout << "�� ���������!" << endl;
            break;
        default:
            cout << "������� ����, ��������� �����." << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
