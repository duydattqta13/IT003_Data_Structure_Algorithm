// Viết hàm xóa các sinh viên có điểm trung bình < 5.0 ra khỏi cây.
node* Delete( node* root, int value )
{
    if (value < 5)
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        if ( root->left == NULL )
        {
            node* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
}   
    return root;
}