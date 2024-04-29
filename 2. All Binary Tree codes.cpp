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

=================================================================================================
Pre Order Traversal 

void PreOrder(Node* node)
{
	if(node == NULL) return;  
	
	cout<< node->val << endl ; 
	PreOrder(node->left) ; 
	PreOrder(node->right) ; 
}

=================================================================================================
In Order Traversal 

void InOrder(Node* node)
{
	if(node == NULL) return;  
	
	InOrder(node->left) ; 
	cout<< node->val << endl ; 
	InOrder(node->right) ; 
}

=================================================================================================
Post Order Traversal 

void PostOrder(Node* node)
{
	if(node == NULL) return;  
	
	PostOrder(node->left) ; 
	PostOrder(node->right) ; 
	cout<< node->val << endl ; 
}


=================================================================================================
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

=================================================================================================
Maximum Depth in a Binary Tree 

int MaxDepth(Node* root)
{
	if(root == NULL) return 0  ; 

	int lh =  MaxDepth(root->left) ;
	int rh =  MaxDepth(root->right) ;

	return 1+ max(lh , rh) ; 
}

=================================================================================================
Check Balanced Binary Tree //If Balanced, retruns the height of the Binary tree, else returns false.

int Balanced(Node* root)
{
	if(root == NULL) return 0  ; 

	int lh =  Balanced(root->left) ;
	int rh =  Balanced(root->right) ;

	if( (lh == -1) || (rh == -1) ) return -1 ; //addition in previous code
	if(abs(lh- rh)>1) return -1 ; 		   //	

	return 1+ max(lh , rh) ; 
}

=================================================================================================
Diameter of Binary Tree  // Function height returns [1+max(lh, rh)] used to calculate int diameter.


class Solution {
public:
    int diameterOfBinaryTree(Node* root) {
        int diameter = 0; 
        height(root, diameter); //Function called
        return diameter;
    }
private:
    // Function to calculate the height of the tree and update the diameter
    int height(Node* node, int& diameter) {

        if (node == NULL) return 0 ; 
		
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh); //addition in previous code
        return 1 + max(lh, rh);
    }
};

=================================================================================================
Maximum Path Sum // Function MaxPath returns [max(lh, rh) + node->val] used to calculate int maxpathsum.

class Solution {
public:
    int MaxPathSum(Node* root) {
        int maxpathsum = 0; 
        maxPath(root, maxpathsum);  //Function called
        return maxpathsum;
    }
private:
    // Function to calculate the height of the tree and update the diameter
    int maxPath(Node* node, int& maxpathsum) {

        if (node == NULL) return 0 ; 
		
        int lh = maxPath(node->left, maxpathsum);
        int rh = maxPath(node->right, maxpathsum);

        maxpathsum = max(maxpathsum, lh + rh + node->val);  //addition in previous code
        return max(lh, rh) + node->val ;
    }
};

=================================================================================================
Check two trees are identical

bool isSameTree(Node* p, Node* q)
{
	if( p== NULL || q== NULL) return (p==q) ; 

	return (p->val == q->val)                    //Return statement is a paid actor.
		&& isSameTree(p->left, q->left) 
		&& isSameTree(p->right, q->right) ; 
}

=================================================================================================
Boundary Traversal

class Solution {
public:
    bool isLeaf(Node* root)  return !root->left && !root->right;  // Helper function for checking leaf.

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (isLeaf(curr)== false)  res.push_back(curr->data);
            if (curr->left)  curr = curr->left;
	    			else curr = curr->right;   
        }
    }
	
   void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        stack<int> st; 								// Stack because we want rightBoundary elements in reverse order.
        while (curr) {
            if (!isLeaf(curr))     stack.push(curr->data);
            if (curr->right)  curr = curr->right;
	    			else curr = curr->left;   
        }
	   		while(!st.empty())
		   	{
			  	 res.push_back(st.top());
				   st.pop() ; 
				}
    }
    void addLeaves(Node* root, vector<int>& res) {
        // If the current node is a leaf, add its value to the result
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        // Recursively add leaves of the left and right subtrees
        if (root->left)   addLeaves(root->left, res);

        if (root->right)  addLeaves(root->right, res);
    }
    // Main function to perform the boundary traversal of the binary tree
    vector<int> printBoundary(Node* root) {
        vector<int> res;   
        if (root == NULL) return res ; 
        if (!isLeaf(root))  res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};



                            
