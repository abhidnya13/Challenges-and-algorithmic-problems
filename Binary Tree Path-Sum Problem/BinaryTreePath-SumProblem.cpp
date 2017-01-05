#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
using namespace std;
#define SIZE 50
stack<int> ans; // stack for backtracking the sequence of nodes in the path
struct node //tree node
{
    int data;
    struct node *left, *right;
};
 
struct Queue //queue is used for the construction of tree
{
    int front,rear;
    int size;
    struct node* *array;
};
struct node* newNode(int data) // creation of new tree node
{
    struct node* temp = (struct node*) malloc(sizeof( struct node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Queue* createQueue(int size) //queue creation
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (struct node**) malloc(queue->size * sizeof( struct node* ));
    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;
    return queue;
}
int isEmpty(struct Queue* queue) //checks if queue is empty
{
    return queue->front == -1;
}
 
int isFull(struct Queue* queue) // checks if queue is full
{  return queue->rear == queue->size - 1; }
 
int hasOnlyOneItem(struct Queue* queue) //checks if queue has only 1 item
{  return queue->front == queue->rear;  }
 
void Enqueue(struct node *root, struct Queue* queue) // inserting in the queue
{
    if (isFull(queue))
        return;
 
    queue->array[++queue->rear] = root;
 
    if (isEmpty(queue))
        ++queue->front;
}
 
struct node* Dequeue(struct Queue* queue) // deleting from the queue
{
    if (isEmpty(queue))
        return NULL;
 
    struct node* temp = queue->array[queue->front];
 
    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;
 
    return temp;
}
 
struct node* getFront(struct Queue* queue) // accessing the front of the queue
{  return queue->array[queue->front]; }
 
int hasBothChild(struct node* temp) // checks if node has both the children
{
    return temp && temp->left && temp->right;
}
 
void insert(struct node **root, int data, struct Queue* queue) //inserts a node in the tree
{
    struct node *temp = newNode(data);
    if (!*root)
        *root = temp;
    else
    {
        struct node* front = getFront(queue);
        if (!front->left)
            front->left = temp;
        else if (!front->right)
            front->right = temp;
        if (hasBothChild(front))
            Dequeue(queue);
    }
    Enqueue(temp, queue);
}
void printstack() // printing of stack which contains the final path
{
    int i,size;
    size= ans.size();
    for (i=0;i<size;i++)
    {
        cout<<ans.top();
        if(i==size-1)
          break;
        cout<<"-";
        ans.pop();
    }
}
int path(struct node* root, int sum ) // finding of path satisfying the property
{
    int a, b;
    if(root == NULL)
        return -1;
    if((root->left == NULL) && (root->right == NULL))
    {
        if(sum == root->data)
        {
            return root->data;
        }
        else return -1;
    }
    a = path(root->left, sum - root->data);
    if( a > 0)
    {
        ans.push(a);
        return root->data;
    }
    b = path(root->right, sum - root->data);
    if( b > 0 )
    {
        ans.push(b);
        return root->data;
    }
    return -1;
}
int main()
{
    int n,val,s;
    cin>>n;
    struct node* root = NULL;
    struct Queue* queue = createQueue(SIZE);
    int i;
    for(i = 0; i < n; i++) // creation of tree
    {
        cin>>val;
        insert(&root, val, queue);
    } 
    cin>>s;
    int r = path(root,s); // checking for a  path satisfying the specified condition
    if(r>0) //if path exists
    {
        ans.push(r);
        printstack();
    } 
    else // if path doesn't exist
    {
        cout<<"-";
    }
    return 0;
}

