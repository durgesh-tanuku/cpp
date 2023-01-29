#include <iostream>

using namespace std;

class MyHashSet {
    struct LinkedList {
        int val;
        LinkedList* next;
    };

    struct LinkedList* head;
public:
    MyHashSet() {
        head = NULL;
    }
    
    void add(int key) {
        if (contains(key)) {
            return;
        } else {
            struct LinkedList* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
            node->val = key;
            node->next = NULL;
            struct LinkedList* trav = head;
            if (trav == NULL) {
                head = node;
                return;
            }
            while(trav->next != NULL) {
                trav = trav->next; 
            }
            trav->next = node;
        }
    }
    
    void remove(int key) {
        struct LinkedList* prev = NULL;
        struct LinkedList* current = head;
        struct LinkedList* next;

        while(current != NULL) {
            next = current->next;
            if (current->val == key) {
                free(current);
                if (prev == NULL) {
                    head = next;
                    return;
                }
                prev->next = next;
                return;
            }
            prev = current;
            current = next;
        }
    }
    
    bool contains(int key) {
        struct LinkedList* trav = head;
        while(trav != NULL) {
            if (trav->val == key) return true;
            trav = trav->next;
        }
        return false;
    }

    void print() {
        struct LinkedList* trav = head;
        while(trav != NULL) {
            cout << trav->val << "\t" << endl;
            trav = trav->next;
        }
        cout << endl;
    }
};

int main() {
    MyHashSet myHashSet;
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.print();
    cout << myHashSet.contains(1) << endl; // return True
    cout << myHashSet.contains(3) << endl; // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    cout << myHashSet.contains(2) << endl; // return True
    myHashSet.remove(2);   // set = [1]
    cout << myHashSet.contains(2) << endl; // return False, (already removed)
    myHashSet.print();
    return 0;
}
