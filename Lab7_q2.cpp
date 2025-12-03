#include <iostream>
using namespace std;

class Tree{
    int data;
    Tree* left;
    Tree* right;
    public:
        Tree(int n){
            data=n;
            left=nullptr;
            right = nullptr;
        }
        bool searchrec(int n, Tree* &root){
            Tree* curr = root;
            if(curr==nullptr) return false;
            if(n==curr->data) return true;
            if(n<curr->data) searchrec(n, curr->left);
            else searchrec(n, curr->right);
        }
        bool searchit(int n, Tree* &root){
            Tree* curr = root;
            while(curr!=nullptr) {
                if(n==curr->data) return true;
                if(n<curr->data) curr = curr->left;
                else curr = curr->right;
            }
            return false;
        }
        int max(Tree* &root){
            Tree* temp = root;
            while(temp->right!=nullptr){
                temp=temp->right;
            }
            return temp->data;
        }
        int min(Tree* &root){
            Tree* temp = root;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            return temp->data;
        }
};

int main() {
    return 0;
}
