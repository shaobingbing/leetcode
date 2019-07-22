#include<iostream>
#include<queue>
#include<vector>

using namespace std;

/** description:
 *  Given a binary tree, find the leftmost value in the last row of the tree.
 */
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode *init_tree(vector<int> &s);
vector<int> print_tree(TreeNode *root);
void print(vector<int> &s);
int findBottomLeftValue(TreeNode* root);

int main()
{
	vector<int> v = {1, 2, 3, -1, -1, 4, 5,6};
	TreeNode *root = init_tree(v);
	int res = findBottomLeftValue(root);
	cout << res << endl;
	return 0;
}

TreeNode *init_tree(vector<int> &s)
{
	if(s.empty())	return NULL;
	TreeNode *root = new TreeNode(s[0]);
	TreeNode *p = root;
	queue<TreeNode *> q;
	q.push(p);
	int i = 1;
	while(i < s.size())
	{
		TreeNode *t = q.front();
		q.pop();
		if(s[i] == -1)
		{
			i++;
		}
		else
		{
			TreeNode *temp = new TreeNode(s[i++]);
			t->left = temp;
			q.push(temp);
		}
		if(i < s.size())
		{
			if(s[i] == -1)
			{
				i++;
			}
			else
			{
				TreeNode *temp = new TreeNode(s[i++]);
				t->right = temp;
				q.push(temp);
			}
		}
	}
	return root;
}

vector<int> print_tree(TreeNode *root)
{
	queue<TreeNode *> q;
	vector<int> v;
	TreeNode *t = root;
	q.push(t);
	while(!q.empty())
	{
		TreeNode *temp = q.front();
		v.push_back(temp->val);
		q.pop();
		if(temp->left)
		{
			q.push(temp->left);
		}
		if(temp->right)
		{
			q.push(temp->right);
		}
	}
	return v;
}

void print(vector<int> &s)
{
	cout << "[" << s[0];
	for(int i = 1; i < s.size(); i++)
	{
		cout << ", " << s[i];
	}
	
	cout << "]" << endl;
}

int findBottomLeftValue(TreeNode* root)
{
	TreeNode *t = root;
	queue<TreeNode *> q;
	TreeNode *result;
	q.push(t);
	while(!q.empty())
	{
		result = q.front();
		int len = q.size();
		for(int i = 0; i < len; i++)
		{
			TreeNode *temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
	}
	return result->val;
}