#include <iostream>
#include <cstring>

using namespace std;

class tree {
    private:
        class node {
            public:
                node *left;
                node *right;
                string key;
                int count;
        };
        node *root;
        
    public:
        tree() {
            root = NULL;
        }
        
        bool isEmpty() const { return root==NULL; }
        void insert(string);
        void print_inorder();
        void inorder(node*);
};

void tree::insert(string data) {
    
    node *t = new node;
    node *parent;
    t->key = data;
    t->left = NULL;
    t->right = NULL;
    t->count = 1;
    parent = NULL;
    
    if (isEmpty()) {
        root = t;
    } else {
        node *curr;
        curr = root;
        while(curr) {
            parent = curr;
            if (curr->key.compare(t->key) == 0) {
                break;
            } else if (curr->key.compare(t->key) < 0) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        if (parent->key.compare(t->key) == 0) {
            curr->count += 1;
        } else if (parent->key.compare(t->key) < 0) {
            parent->right = t;
        } else {
            parent->left = t;
        }
    }
}

void tree::print_inorder() {
    inorder(root);
}

void tree::inorder(node *p) {
    if(p != NULL) {
        inorder(p->left);
        cout << p->key << " " << p->count << "\n";
        inorder(p->right);
    } else {
        return;
    }
}

int main() {
   int i, num_lines, num_countries=0;
   string country, name;
   tree country_tree;
   
   cin >> num_lines;
   
   for (i=0; i<num_lines; i++) {
       cin >> country;
       getline(cin, name);
       
       country_tree.insert(country);
   }
   
   country_tree.print_inorder();
   return 0;
}
