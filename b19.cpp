
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void _addatbeg(node **q, int num)
{
    node *temp;
    temp = new node;
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

void _display(node *q)
{
    int current_data = q->data;
    int current_data_freq = 0;
    while(q != NULL)
    {
        if(q->data == current_data)
            current_data_freq++;
        else
        {
            cout << current_data << " : " << current_data_freq << endl;
            current_data = q->data;
            current_data_freq = 1;
        }

        q = q->link;
    }

    cout << current_data << " : " << current_data_freq << endl;
}
// --------------------------
void _sort(char arr[])
{
    node *arr[100];
    char output[strlen(arr)];

    int count[255], i;
    memset(count, 0, sizeof(count));
 
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
 
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

int main()
{
    node *head;
    head = NULL;
    int n, temp_val;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_val;
        _addatbeg(&head, temp_val);
    }
    head = _sort(head);
    _display(head);
    return 0;
}
