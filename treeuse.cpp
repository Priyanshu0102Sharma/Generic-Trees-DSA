#include<iostream>
#include "TreeNode.h"
#include<queue>

using namespace std;


TreeNode<int> * takeinputlevelwise()
{
    //first make root node
    int rootdata;
    cout<<"Enter root data: ";
    cin>>rootdata;
    // make the node of the root data;
    TreeNode<int> * root= new TreeNode<int>(rootdata);
    // make a queue to store the node so that children of specific node can be made
    queue<TreeNode<int>*> pendingnode;
    //pushing root node into queue
    pendingnode.push(root);
    // taking children of root node and taking children of these node
    while(!pendingnode.empty())
    {
        //making a front node to store the front element of the queue
        TreeNode<int>* front=pendingnode.front();
        pendingnode.pop();
        
        //to get no. of children of front node
        int n;
        cout<<"Enter number of children of "<<front->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            //to enter data of children node of node present in front o queue
            int childdata;
            cout<<"Enter data of "<<i<<"th node: ";
            cin>>childdata;
            //to make node of this childdata;
            TreeNode<int> *child=new  TreeNode<int>(childdata);
            // to connect this node to front node;
            front->children.push_back(child);
            //to store the above node to queue
            pendingnode.push(child);
            
        }

    }
    return root;
}


TreeNode<int>* takeinput()
{
    int rootdata;
    cout<<"Enter data: "<<endl;
    cin>>rootdata;
    TreeNode<int>* root= new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter no. of children of "<<rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int> * child=takeinput();
        root->children.push_back(child);
    }
    return root;
}


void printtreelevelwise(TreeNode<int>*root)
{
    // to print root data;
    // cout<<root->data;
    // create a queue to print nodes children
    queue<TreeNode<int> *> childrenNode;
    //push root node into childrenNode;
    childrenNode.push(root);
    while(!childrenNode.empty())
    {
        TreeNode<int>* front=childrenNode.front();
        
        childrenNode.pop();
        cout<<front->data<<": ";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<",";
            childrenNode.push(front->children[i]);
        }
        cout<<endl;
    }
}

void printtree(TreeNode<int> *root)
{
    cout<<root->data<<": ";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
            printtree(root->children[i]);
    }
}

int numberofNode(TreeNode<int>*root)
{
int ans=1;
for(int i=0;i<root->children.size();i++)
{
    ans+=numberofNode(root->children[i]);
}
return ans;
}

int heightoftree(TreeNode<int> *root){
    int height=-1;
    for(int i=0;i<root->children.size();i++)
    {
        int tempheight=heightoftree(root->children[i]);
        height=max(tempheight,height);
    }
return height+1;
    

}

void depthoftree(TreeNode<int> * root, int depth)
{
// edge case
if(root==NULL)
return ;


    // base case
    if(depth==0)
    {
        cout<<root->data<<endl;
        return;
    }

for(int i=0;i<root->children.size();i++)
{
    depthoftree(root->children[i],--depth);
}
}

int main()
{

    // making tree nodes
// TreeNode<int>* root=new TreeNode<int>(5);
// TreeNode<int>* Node1=new TreeNode<int>(3);
// TreeNode<int>* Node2=new TreeNode<int>(4);



// // connection root to his childrens
// root->children.push_back(Node1);
// root->children.push_back(Node2);


// TreeNode<int> *root=takeinput();
TreeNode<int> * root=takeinput();
printtreelevelwise(root);
cout<<endl;

// printtree(root);

cout<<heightoftree(root);
    return 0;
}