#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

node *_get_tail(node *q)
{
    while (q != NULL && q->link != NULL)
        q = q->link;
    return q;
}

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
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}
struct node* partition(struct node* head, struct node* end,
                       struct node** newHead,
                       struct node** newEnd)
{
    struct node* pivot = end;
    struct node *prev = NULL, *q = head, *tail = pivot;
 
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (q != pivot) {
        if (q->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = q;
 
            prev = q;
            q = q->link;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->link = q->link;
            struct node* tmp = q->link;
            q->link = NULL;
            tail->link = q;
            tail = q;
            q = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
struct node* quickSortRecur(struct node* head,
                            struct node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    struct node* pivot
        = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        struct node* tmp = newHead;
        while (tmp->link != pivot)
            tmp = tmp->link;
        tmp->link = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = _get_tail(newHead);
        tmp->link = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->link = quickSortRecur(pivot->link, newEnd);
 
    return newHead;
}
 
void  _quick_sort(struct node** q)
{
    (*q)
        = quickSortRecur(*q, get_tail(*q));
    return;
}
 
//###INSERT CODE HERE -

int main()
{
    node *head, *tail;

    head = NULL;

    int n, temp_val;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp_val;
        _addatbeg(&head, temp_val);
    }

    tail = _get_tail(head);

    //_display(head);

    head = _quick_sort(head, tail);

    _display(head);

    return 0;
}
