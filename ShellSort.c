/* Program to implement Shell Sort */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
/* Protyping */
void swap(int *, int *);
void display(int [], int );
void shellSort(int [], int );

/* Code for Shell sort */
void shellSort(int arr[15], int n)
{
	int i, j, k, pass=0;
	for(i=n/2; i>0; i=i/2)
	{
		pass++;
		printf("pass = %d\n", pass); // printing the pass
		for(j=i; j<n; j++)
		{
			for(k=j-i; k>=0; k=k-i)
			{
				if(arr[k+i] >= arr[k])
				{
					break;
				}
				else
				{
					swap(&arr[k+i], &arr[k]);
				}
			}
		}
		printf("Displaying the intermediate list: ");
		display(arr, n); // checking the intermediate list
		printf("\n");
	}
	
}

/* Code for displaying the array */
void display(int arr[15], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/* Code for swapping elements */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int arr[15];
	int i, n;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);
	printf("Enter %d elements: ",n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	system("cls"); // in case using ubuntu, change cls to clear
	printf("The entered numbers are: ");
	display(arr, n);
	shellSort(arr,n);
	printf("After completion of sorting the elements are: ");
	display(arr, n);
	return 0;
}
