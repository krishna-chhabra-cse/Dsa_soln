#include <iostream>
using namespace std;

class Tree{
    Tree* left;
    Tree* right;
    int data;
    public:
        Tree(int n){
            data=n;
            right = nullptr;
            left = nullptr;
        }
        void Preorder(Tree* &temp){
            Tree* curr = temp;
            if(curr!=nullptr){
                cout<<curr->data<<" ";
                Preorder(curr->left);
                Preorder(curr->right);
            }
        }
        void Inorder(Tree* &temp){
            Tree* curr = temp;
            if(curr!=nullptr){
                Inorder(curr->left);
                cout<<curr->data<<" ";
                Inorder(curr->right);
            }
        }
        void Postorder(Tree* &temp){
            Tree* curr = temp;
            if(curr!=nullptr){
                Postorder(curr->left);
                Postorder(curr->right);
                cout<<curr->data<<" ";
            }
        }
};

int main() {
    return 0;
}