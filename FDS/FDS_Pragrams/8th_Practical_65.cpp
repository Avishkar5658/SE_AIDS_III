#include<iostream>
using namespace std;

class node {
public:
    node *prev;
    bool n;
    node* next;

    node() {
        prev = next = NULL;
    }

    node(bool b) {
        n = b;
        prev = next = NULL;
    }

    friend class binary;
};

class binary {
    node* start;

public:
    binary() {
        start = NULL;
    }

    void generateBinary(int no);
    void displayBinary();
    void onesComplement();
    void twosComplement();
    binary operator +(const binary& n1);
    bool addBitAtBegin(bool val);
};

void binary::generateBinary(int no) {
    bool rem;
    node* p;
    rem = no % 2;
    start = new node(rem);
    no = no / 2;
    while (no != 0) {
        rem = no % 2;
        no = no / 2;
        p = new node(rem);
        p->next = start;
        start->prev = p;
        start = p;
    }
}

void binary::displayBinary() {
    node* t = start;
    while (t != NULL) {
        cout << t->n;
        t = t->next;
    }
    cout << endl;
}

void binary::onesComplement() {
    node* t = start;
    while (t != NULL) {
        if (t->n == 0)
            t->n = 1;
        else
            t->n = 0;
        t = t->next;
    }
}

binary binary::operator +(const binary& n1) {
    binary sum;
    node* a = start;
    node* b = n1.start;
    bool carry = false;

    while (a->next != NULL)
        a = a->next;
    while (b->next != NULL)
        b = b->next;

    while (a != NULL && b != NULL) {
        sum.addBitAtBegin((a->n) ^ (b->n) ^ carry);
        carry = ((a->n && b->n) || (a->n && carry) || (b->n && carry));

        a = a->prev;
        b = b->prev;
    }

    while (a != NULL) {
        sum.addBitAtBegin(a->n ^ carry);
        a = a->prev;
    }

    while (b != NULL) {
        sum.addBitAtBegin(b->n ^ carry);
        b = b->prev;
    }

    sum.addBitAtBegin(carry);
    return sum;
}

bool binary::addBitAtBegin(bool val) {
    node* newNode = new node(val);
    if (start == NULL) {
        start = newNode;
    }
    else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    return true;
}

void binary::twosComplement() {
    onesComplement();
    bool carry = 1;
    node* t = start;

    while (t->next != NULL) {
        t = t->next;
    }

    while (t != NULL) {
        if (t->n == 1 && carry == 1) {
            t->n = 0;
        }
        else {
            t->n = 1;
        }

        carry = (t->n == 0 && carry == 1);
        t = t->prev;
    }

    displayBinary();
}

int main() {
    int num, num1;
    binary n1, n3, n2;
    int choice = 1;

    do {
        cout << "\n\n=========Binary Number Operations========\n";
        cout << "1. Generate binary\n2.One's Complement\n3.Two's Complement\n4. Addition\n0.Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Number in decimal form: ";
                cin >> num;
                n1.generateBinary(num);
                cout << "\nBinary Representation: ";
                n1.displayBinary();
                break;

            case 2:
                cout << "\nEnter Number in decimal form: ";
                cin >> num;
                n1.generateBinary(num);
                cout << "\nBinary Representation: ";
                n1.displayBinary();
                cout << "\nOne's Complement: ";
                n1.onesComplement();
                n1.displayBinary();
                break;

            case 3:
                cout << "\nEnter Number in decimal form: ";
                cin >> num;
                n1.generateBinary(num);
                cout << "\nBinary Representation: ";
                n1.displayBinary();
                cout << "\nTwo's complement: ";
                n1.twosComplement();
                break;

            case 4:
                cout << "\nEnter Two Numbers: ";
                cin >> num >> num1;
                n1.generateBinary(num);
                n2.generateBinary(num1);
                cout << "\n";
                n1.displayBinary();
                cout << " + ";
                n2.displayBinary();
                cout << " = ";
                n3 = n1 + n2;
                n3.displayBinary();
                break;
        }
    } while (choice != 0);

    n1.generateBinary(7);
    cout << "\nBinary Representation: ";
    n1.displayBinary();
    n1.displayBinary();
    cout << "\nTwo's complement: ";
    n1.twosComplement();

    return 0;
}
