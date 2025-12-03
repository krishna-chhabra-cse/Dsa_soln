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

    Tree* buildTree(int preorder[], int inorder[], int prestart, int preend, int instart, int inend){
        if(prestart>preend || instart>inend){
            return nullptr;
        }
        int rootData = preorder[prestart];
        Tree* root = new Tree(rootData);

        int rootIndex;
        for(rootIndex=instart; rootIndex<=inend; rootIndex++){
            if(inorder[rootIndex] == rootData){
                break;
            }
        }
        int leftSubtreeSize = rootIndex - instart;
        root->left = buildTree(preorder, inorder, prestart+1, prestart+leftSubtreeSize, instart, rootIndex-1);
        root->right = buildTree(preorder, inorder, prestart+leftSubtreeSize+1, preend, rootIndex+1, inend);
        return root;
    }
};