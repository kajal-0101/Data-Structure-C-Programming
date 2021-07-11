#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node* BST;

BST createNode(int );
BST insertNode(BST , int);
void inorderInBST(BST );
void postorderInBST(BST );
void preorderInBST(BST );
BST maxValue(BST );
BST minValue(BST );
BST search(BST , int );


BST createNode(int item)
{
	BST temp;
	temp = (BST)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

BST insertNode(BST node, int item)
{
	if(node == NULL)
	{
		printf("Sucessfully inserted\n");
		return createNode(item);
	}
	if(item < node->data)
	{
		node->left = insertNode(node->left, item);
	}
	else if(item > node->data)
	{
		node->right = insertNode(node->right, item);
	}
	else
	{
		printf("Element already exists in BST\n");
	}
	return node;
}

void inorderInBST(BST root)
{
	if(root != NULL)
	{
		inorderInBST(root->left);
		printf("%d ", root->data);
		inorderInBST(root->right);
	}
}

void postorderInBST(BST root)
{
	if(root != NULL)
	{
		postorderInBST(root->left);
		postorderInBST(root->right);
		printf("%d ", root->data);
	}
}

void preorderInBST(BST root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preorderInBST(root->left);
		preorderInBST(root->right);
	}
}

BST minValue(BST node)
{
	BST current;
	current = node;
	if(current->left == NULL)
	{
		return node;
	}
	else
	{
		while(current->left != NULL)
		{
			current = current->left;
		}
		return(current);
	}
}

BST maxValue(BST node)
{
	BST current;
	current = node;
	if(current->right == NULL)
	{
		return node;
	}
	else
	{
		while(current->right != NULL)
		{
			current = current->right;
		}
		return(current);
	}
}

BST search(BST root, int ele)
{
	if(root == NULL || root->data == ele)
	{
		return root;
	}
	if(ele < root->data)
	{
		return search(root->left, ele);
	}
	else
	{
		return search(root->right, ele);
	}
}

BST deleteNode(BST root, int ele)
{
	BST temp, min;
	if(root == NULL)
	{
		printf("Cannot find %d in the Binary Search Tree\n");
		return root;
	}
	if(ele < root->data)
	{
		root->left = deleteNode(root->left, ele);
	}
	else if(ele > root->data)
	{
		root->right = deleteNode(root->right, ele);
	}
	else
	{
		if(root->left == NULL)
		{
			temp = root->right;
			printf("%d is deleted\n", root->data);
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			temp = root->left;
			printf("%d is deleted\n", root->data);
			free(root);
			return temp;
		}
		
			temp = minValue(root->right);
			root->data = temp->data;
			temp->data = ele;
			root->right = deleteNode(root->right, temp->data);
	}
	return root;
}
int main()
{
	int option, ele;
	BST root = NULL;
	BST temp;
	do
	{
		printf("1.Insert 2.Inorder Traversal 3.Postorder Traversal\n");
		printf("4.Preorder Traversal 5.Search 6.Delete\n");
		printf("7.Finding minimum 8.Finding Maxmimum 9.Exit\n");
		scanf("%d", &option);
		system("cls");
		switch(option)
		{
			case 1: printf("Enter the element : ");
					scanf("%d", &ele);
					root = insertNode(root, ele);
				break;
			
			case 2: if(root == NULL)
					{
						printf("The tree is empty\n");
					}
					else
					{
						printf("Traversing the tree in inorder fashion\n");
						inorderInBST(root);
						printf("\n");
					}
				break;
				
			case 3: if(root == NULL)
					{
						printf("The tree is empty\n");
					}
					else
					{
						printf("Traversing the tree in postorder fashion\n");
						postorderInBST(root);
						printf("\n");
					}
				break;
		
			case 4: if(root == NULL)
					{
						printf("The tree is empty\n");
					}
					else
					{
						printf("Traversing the tree in preorder fashion\n");
						preorderInBST(root);
						printf("\n");
					}
				break;
				
			case 5: printf("Enter an element to search : ");
					scanf("%d", &ele);
					if(search(root, ele) == NULL)
					{
						printf("Element not found in the tree\n");
					}
					else
					{
						printf("Element %d found in the tree\n", ele);
					}
				break;
				
			case 6: printf("Enter the element to be deleted : ");
					scanf("%d", &ele);
					root = deleteNode(root, ele);
				break;
				
			case 7: temp = minValue(root);
					printf("The minimum value of the BST is : %d\n", temp->data);
				break;
				
			case 8: temp = maxValue(root);
					printf("The maximum value of the BST is : %d\n", temp->data);
				break;
				
			case 9: printf("Exiting from the porgram\n"); 
			exit(0);
				break;
				
			default: printf("Wrong option\n");
		}
	}while(1);
	return 0;
}
