/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node {
    int ele;
    Node * next;

    Node(int ele) {
        this->ele = ele;
        next = nullptr;
    }
    
    ~Node() {}
};

class Hash_Table {

    int hash_fn(int ele) {
        return ele % size;
    }
    
    
public:    
    Node **array;
    int size;
    Hash_Table(int numOfEle) {
        size = numOfEle;
        array = new Node*[size];
        print_table();
    }
    
    bool search(int ele) {
        int index = hash_fn(ele);
        Node *node = array[index];
        while (node) {
            if (node->ele == ele) return true;
            node = node->next;
        }
        return false;
    }
    
    void store(int ele) {
        int index = hash_fn(ele);
        if (!array[index]) {
            array[index] = new Node(ele);
            print_table();
            return;
        }
        Node *node = array[index];
        while (node->next) {
            node = (node)->next;
        }
        node->next = new Node(ele);
        print_table();
    }
    
    void rm(int ele) {
        if (search(ele)) {
            int index = hash_fn(ele);
            if (array[index]->ele == ele) {
                Node *waste = array[index];
                array[index] = waste->next;
                delete waste;
                print_table();
                return;
            }
            Node *node = array[index];
            while(node->next->ele != ele) {
                node = node->next;
            }
            Node * waste = node->next;
            node->next = node->next->next;
            delete waste;
        }
        print_table();
    }

    void destroy() {
        //cout << "+HASH_TABLE destroy"<<endl;
        for(int i = 0; i < size; i ++) {
            Node * nt = (array[i]);
            while (nt) {
                Node * waste = nt;
                nt = nt->next;
                delete waste;
            }
            array[i] = nullptr;
        }
        print_table();
        delete [] array;
    }

    void print_table() {
        cout << "-----Print Hash Table, size is " << size << endl;
        for(int i = 0; i < size; i++) {
            Node * node = array[i];
            cout << "| ";
            while(node) {
                cout << node->ele << " --> ";
                node = node->next;
            }
            cout <<endl;
        }

        cout << "------------------" << endl;
    }

    
};


int main()
{
    Hash_Table table (10);
    table.store(1);
    table.store(11);
    table.store(21);
    table.store(8);
    table.store(16);
    table.store(28);
    table.rm(28);
    table.rm(1);

    table.destroy();

    return 0;
}

