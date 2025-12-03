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

    int calculate(Tree* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftDepth = calculate(root->left);
        int rightDepth = calculate(root->right);
        
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
};