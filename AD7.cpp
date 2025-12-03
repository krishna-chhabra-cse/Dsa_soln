class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d){
        left = nullptr;
        right = nullptr;
        this->data = d;
    }
};

class DLLNode {
public:
    int val;
    DLLNode* prev;
    DLLNode* next;
    
    DLLNode(int value) {
        val = value;
        prev = nullptr;
        next = nullptr;
    }
};

class MergeBSTsToDLL {
private:
    // Get inorder traversal and count nodes
    void inorderTraversal(TreeNode* root, int arr[], int& index) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, arr, index);
        arr[index++] = root->data;
        inorderTraversal(root->right, arr, index);
    }
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
public:
    DLLNode* merge(TreeNode* root1, TreeNode* root2) {
        // Count nodes in both trees
        int size1 = countNodes(root1);
        int size2 = countNodes(root2);
        
        // Create arrays for inorder traversals
        int* list1 = new int[size1];
        int* list2 = new int[size2];
        
        // Fill arrays with inorder traversal
        int index1 = 0, index2 = 0;
        inorderTraversal(root1, list1, index1);
        inorderTraversal(root2, list2, index2);
        
        // Merge two sorted arrays
        int totalSize = size1 + size2;
        int* merged = new int[totalSize];
        int i = 0, j = 0, k = 0;
        
        while (i < size1 && j < size2) {
            if (list1[i] <= list2[j]) {
                merged[k++] = list1[i++];
            } else {
                merged[k++] = list2[j++];
            }
        }
        
        // Add remaining elements
        while (i < size1) {
            merged[k++] = list1[i++];
        }
        while (j < size2) {
            merged[k++] = list2[j++];
        }
        
        // Convert merged array to doubly linked list
        if (totalSize == 0) {
            return nullptr;
        }
        
        // Create first node
        DLLNode* head = new DLLNode(merged[0]);
        DLLNode* current = head;
        
        // Create remaining nodes and link them
        for (int m = 1; m < totalSize; m++) {
            DLLNode* newNode = new DLLNode(merged[m]);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        
        // Clean up
        delete[] list1;
        delete[] list2;
        delete[] merged;
        
        return head;
    }
};