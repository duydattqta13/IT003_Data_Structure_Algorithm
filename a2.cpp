// Viết hàm thêm các sinh viên vào cây.
node* insert(node* root, int data)
{
    node* newnode = newNode(data);
    node* x = root;
    node* y = NULL;
 
    while (x != NULL) {
        y = x;
        if (data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        y = newnode;
    else if (data < y->data)
        y->left = newnode;
    else
        y->right = newnode;
    return y;
}