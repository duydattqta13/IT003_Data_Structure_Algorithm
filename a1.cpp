// Khai báo cấu trúc cây nhị phân tìm kiếm để lưu thông tin sinh viên
struct node
{
    int studentID;
    char name_family;
    char name;
    int average_score;
    node* left;
    node* right;
} 
node* newNode(int data1, char data2, char data3, int data4)
{
    node* temp = new node;
 
    temp->studentID = data1;
    temp->name_family = data2;
    temp->name = data3;
    temp->average_score = data4;
 
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}