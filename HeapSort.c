#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[15], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	}
	
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
	}
	
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapsort(int arr[15], int n)
{
	int i;
	for (i=(n/2-1); i>=0; i--)
	{
		heapify(arr, n, i);
	}
	for(i=(n-1); i>=0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void display(int arr[15], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
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
	printf("The entered elements are: ");
	display(arr, n);
	heapsort(arr, n);
	printf("After sort the elements are: ");
	display(arr, n);
	return 0;
}
