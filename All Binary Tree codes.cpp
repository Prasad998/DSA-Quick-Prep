## Class Representation ##

class Node {
public:
    int data;
    Node* left;
    Node* right;

	Node(int val)
	{
		data = val ;
		left = right = NULL ; 
	}

};

======================================================================
Pre Order Traversal 

void PreOrder(Node* node)
{
	if(node == NULL) return;  
	
	cout<< node->val << endl ; 
	PreOrder(node->left) ; 
	PreOrder(node->right) ; 
}
======================================================================
In Order Traversal 

void InOrder(Node* node)
{
	if(node == NULL) return;  
	
	InOrder(node->left) ; 
	cout<< node->val << endl ; 
	InOrder(node->right) ; 
}

======================================================================
Post Order Traversal 

void PostOrder(Node* node)
{
	if(node == NULL) return;  
	
	PostOrder(node->left) ; 
	PostOrder(node->right) ; 
	cout<< node->val << endl ; 
}


======================================================================
Level Order Traversal 

vector<int> LevelOrder(Node* root)
{
	vector<int> ans ; 
//BASE Condition 
	
	if(root == NULL) return ans ; 
	
	queue<Node*> q ; 
	q.push(root) ;
	while(!q.empty())
		{
			Node* node  = q.front() ; 
			q.pop() ;
			if(node->left) q.push(node->left) ;
			if(node->right) q.push(node->right) ;
			ans.push_back(node->data) ; 
		}
	return ans; 
}

======================================================================
Maximum Depth in a Binary Tree

int MaxDepth(Node* root)
{
	if(root == NULL) return 0  ; 

	int lh =  MaxDepth(root->left) ;
	int rh =  MaxDepth(root->right) ;

	return 1+ max(lh , rh) ; 
}

======================================================================
Maximum Depth in a Binary Tree

int MaxDepth(Node* root)
{
	if(root == NULL) return 0  ; 

	int lh =  MaxDepth(root->left) ;
	int rh =  MaxDepth(root->right) ;

	return 1+ max(lh , rh) ; 
}
======================================================================
Check Balanced Binary Tree //If Balanced, retruns the height of the Binary tree, else returns false.

int Balanced(Node* root)
{
	if(root == NULL) return 0  ; 

	int lh =  Balanced(root->left) ;
	int rh =  Balanced(root->right) ;

	if( (lh == -1) || (rh == -1) ) return -1 ; 

	if(abs(lh- rh)>1) return -1 ; 

	return 1+ max(lh , rh) ; 
}


	
