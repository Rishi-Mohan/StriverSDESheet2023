void inorder(TreeNode<int> *root, int &k, int &ans){
    if(root == NULL)
        return;
    inorder(root->left, k, ans);
    k -= 1;
    if(k == 0){
        ans = root->data;
        return;
    }
    inorder(root->right, k, ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1;
    inorder(root, k, ans);
    return ans;
}
