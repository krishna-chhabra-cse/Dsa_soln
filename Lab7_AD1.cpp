#include <iostream>
using namespace std;

class Tree{
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int d){
        left = nullptr;
        right = nullptr;
        this->data = d;
    }

    int sumOfLeftLeaves(Tree* root){
        if(root == nullptr) return 0;
        int sum = 0;
        if(root->left){
            if(root->left->left == nullptr && root->left->right == nullptr){
                sum += root->left->data;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }
        if(root->right) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
};

int main() {
    return 0;
}
