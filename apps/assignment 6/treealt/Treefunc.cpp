
       removeLeaves(&root) {
    if (&root != NULL)
    {
        if (&root->left == NULL && &root->right == NULL)  //https://stackoverflow.com/questions/25151991/removing-all-leaves-from-a-binarytree
        return NULL
        else
        {
            &root->left = removeLeaves(&root->left);
            &root->right = removeLeaves(&root->right);
        }
    }
    return &root;
}
