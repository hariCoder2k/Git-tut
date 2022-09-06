TreeNode* BST :: deleteRecursion(TreeNode* root, int rno)
{
        TreeNode* parent = root;
        TreeNode* min;
        if (parent == NULL )
                return parent;
        if (rno < parent->roomno)
                parent->left =  deleteRecursion(parent->left,rno);
        if (rno > parent->roomno)
                 parent->right =  deleteRecursion(parent->right,rno);
        if (rno == parent->roomno)
        {
                if (parent->left == NULL)
                {
                        TreeNode* temp = parent->right;
                        free(parent);
                        return temp;
                }
                else if(parent->right == NULL)
                {
                        TreeNode* temp = parent->left;
                        free(parent);
                        return temp;
                }
                min = findMin(parent->right);
                parent->name = min->name;
                parent->age = min->age;
                parent->roomno = min->roomno;
                parent->right = deleteRecursion(parent->right,min->roomno);

        }
        return parent;
}