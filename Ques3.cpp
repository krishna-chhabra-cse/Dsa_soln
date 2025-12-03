#include <iostream>
using namespace std;

class Tree{
    public:
    Tree* left;
    Tree* right;
    int data;
    
    Tree(int n){
        data = n;
        left = nullptr;
        right = nullptr;
    }

    void insertNode(Tree* &root, int n){
        if(root == nullptr){
            Tree* node = new Tree(n);
            root = node;
            return;
        }
        Tree* curr = root;
        if(n > curr->data){
            insertNode(curr->right, n);
        }
        else if(n<curr->data){
            insertNode(curr->left, n);
        }
        else{
            cout<<"There should be no duplicates.";
        }
    }

    void deleteNode(Tree* &root, int n){
        if(root=NULL){
            return;
        }
        else if(root->data==n){
            //0 children
            if(root->left==nullptr && root->right==nullptr)delete root;

            // 1 child
            // left child
            else if(root->left!=nullptr && root->right==nullptr){
                Tree* temp = root;
                root = root->left;
                delete temp;
            }
            // right child
            else if(root->right!=nullptr && root->left==nullptr){
                Tree* temp = root;
                root = root->right;
                delete temp;
            }
            // 2 children
            else{
                Tree* temp = root->left;
                while(temp->right!=nullptr) temp = temp->right;
                int max = temp->data;
                root->data = max;
                deleteNode(root->left, max);
            }
        }
        else if(n<root->data){
            deleteNode(root->left, n);
        }
        else{
            deleteNode(root->right, n);
        }
    }
};

int main() {
    return 0;
}