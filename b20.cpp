
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

int _get_height(node *sr)
{
	if (!sr)
        return -1;
	return 1 + max(_get_height(sr->left), _get_height(sr->right));
}

void _display_subtree(node *q, vector<string> & output, int left, int top, int width)
{
	string str = to_string(q->data);

	int left_begin_shift = 1 - (str.length()-1)/2;
	for (size_t i = 0; i < str.length() && left + width/2 + i < output[top].length(); i++)
		output[top][left + width/2 + left_begin_shift + i] = str[i];

	int branch_off_set = (width+3)/pow(2, 3);
	int mid = left + width/2;
	int left_mid = left + (width/2 - 1)/2;
	int right_mid = left + width/2 + 2 + (width/2 - 1)/2;

	if (q->left)
	{
		int branch_position = mid - branch_off_set + 1;
		for (int pos = mid + left_begin_shift - 2; pos > branch_position; pos--)
			output[top][pos] = '_';
		output[top+1][branch_position] = '/';
		for (int pos = branch_position-1; pos > left_mid + 2; pos--)
			output[top+1][pos] = '_';
		_display_subtree(q->left, output, left, top+2, width/2 - 1);
	}

	if (q->right)
	{
		int branch_position = mid + branch_off_set + 1;
		for (int pos = mid + left_begin_shift + str.length() + 1; pos < branch_position; pos++)
			output[top][pos] = '_';
		output[top+1][branch_position] = '\\';
		for (int pos = branch_position+1; pos < right_mid; pos++)
			output[top+1][pos] = '_';
		_display_subtree(q->right, output, left + width/2 + 2, top+2, width/2 - 1);
	}
}


void _display_tree(node *root)
{
	if (!root)
        return;

	int height = _get_height(root);
	int width_display = 4*pow(2, height) - 3;
	int height_display = 2 * height + 1;

	vector<string> output(height_display);
	for (size_t i = 0; i < output.size(); i++)
		output[i] = string(width_display + 4, ' ');

	_display_subtree(root, output, 0, 0, width_display);

	for (int row = 0; row < height_display; row++)
		cout << output[row] << endl;
}
// -------------------------------------------
void _insert(node *&core, int key)
{
    if (core == NULL) 
	{
		node* nw = new node();
		nw->data = key;
		nw->left = NULL;
		nw->right = NULL;
		core = nw;
	}
    else if (key < core->data)
		_insert(core->left, key);
    else if (key >= core->data)
        _insert(core->right, key);
}

int main()
{
    node *root = NULL;
    _insert(root, 5);
    _insert(root, 2);
    _insert(root, 6);
    _insert(root, 6);
    _insert(root, 7);
    _insert(root, 1);
    _insert(root, 4);
    _display_tree(root);
    return 0;
}