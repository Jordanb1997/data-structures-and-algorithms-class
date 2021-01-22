typedef struct bstNode{
	int data_item;
	struct bstNode *left;
	struct bstNode *right;
} *BSTNodePtr;

typedef struct bst{
	BSTNodePtr root;
} BST;

BST new_bst();
BSTNodePtr find_bst(BST *self, int n);
void insert_bst(BST *self, int n);
BSTNodePtr min_node(BSTNodePtr self);
void delete_bst(BST *self, int n);