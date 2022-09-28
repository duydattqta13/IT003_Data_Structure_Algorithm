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
    while(q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}
//-------------
int length(struct node* current)
{
    int count = 0;
    while (current != NULL) {
        current = current->link;
        count++;
    }
    return count;
}
void merge(struct node** start1, struct node** end1,
          struct node** start2, struct node** end2)
{
    struct node* temp = NULL;
    if ((*start1)->data > (*start2)->data) {
        swap(*start1, *start2);
        swap(*end1, *end2);
    }
 
    // Merging remaining nodes
    struct node* astart = *start1, *aend = *end1;
    struct node* bstart = *start2, *bend = *end2;
    struct node* bendnext = (*end2)->link;
    while (astart != aend && bstart != bendnext) {
        if (astart->link->data > bstart->data) {
            temp = bstart->link;
            bstart->link = astart->link;
            astart->link = bstart;
            bstart = temp;
        }
        astart = astart->link;
    }
    if (astart == aend)
        astart->link = bstart;
    else
        *end2 = *end1;
}
 
void _merge_sort(struct node** head)
{
    if (*head == NULL)
        return;
    struct node* start1 = NULL, *end1 = NULL;
    struct node* start2 = NULL, *end2 = NULL;
    struct node* prevend = NULL;
    int len = length(*head);
 
    for (int gap = 1; gap < len; gap = gap*2) {
        start1 = *head;
        while (start1) {
 
            // If this is first iteration
            bool isFirstIter = 0;
            if (start1 == *head)
                isFirstIter = 1;
 
            // First part for merging
            int counter = gap;
            end1 = start1;
            while (--counter && end1->link)
                end1 = end1->link;
 
            // Second part for merging
            start2 = end1->link;
            if (!start2)
                break;
            counter = gap;
            end2 = start2;
            while (--counter && end2->link)
                end2 = end2->link;
 
            // To store for link iteration.
            node *temp = end2->link;
 
            // Merging two parts.
            merge(&start1, &end1, &start2, &end2);
 
            // Update head for first iteration, else
            // append after previous list
            if (isFirstIter)
                *head = start1;
            else
                prevend->link = start1;
 
            prevend = end2;
            start1 = temp;
        }
        prevend->link = start1;
    }
}

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
    //_display(head);
    _merge_sort(&head);
    _display(head);
    return 0;
}
