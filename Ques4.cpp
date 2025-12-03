#include <iostream>
using namespace std;

class Tree{
private:
    Tree* lptr;
    Tree* rptr;
    int data;
public:
    bool isBST(Tree* &root, int min, int max){
        if(root == nullptr) return false;
        if(root->data<=max && root->data>=min){
            bool left = isBST(root->lptr, min, root->data);
            bool right = isBST(root->rptr, root->data, max);
            return left && right;
        }
        else return false;
    }   
};

int main() {
    return 0;
}