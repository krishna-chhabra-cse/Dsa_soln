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

    Tree* buildTree(int postOrder[], int inorder[], int postStart, int postEnd, int inStart, int inEnd){
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        int rootData = postOrder[postEnd];
        Tree* root = new Tree(rootData);

        int rootIndex;
        for(rootIndex = inStart; rootIndex <= inEnd; rootIndex++){
            if(inorder[rootIndex] == rootData){
                break;
            }
        }
        int leftSubtreeSize = rootIndex - inStart;

        root->left = buildTree(postOrder, inorder, postStart, postStart + leftSubtreeSize - 1, inStart, rootIndex - 1);
        root->right = buildTree(postOrder, inorder, postStart + leftSubtreeSize, postEnd - 1, rootIndex + 1, inEnd);
        return root;
    }
};
