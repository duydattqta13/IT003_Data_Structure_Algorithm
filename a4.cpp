// Viết hàm hiển thị danh sách sinh viên khi duyệt cây theo thứ tự trước.
void PreOrder(node* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}