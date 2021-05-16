#include<stdio.h>
//Function declaration.......
void pushZerosToEnd(int arr[],int n);
void main()
{
	int i,n;
	printf("Enter no. of elements to be entered in the array :");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the array :\n");
	//Getting input and storing it in an array.....
	for(i=0;i<n;i++)
	{
		printf("Enter the element :");
		scanf("%d",&arr[i]);
	}
	//Printing the ouput..
	printf("Input :");
	for(i=0;i<n;i++)
	{
		printf("[%d]  ",arr[i]);
	}
	pushZerosToEnd(arr,n);
}
//Pushing the zero to end of the same array by updating the same element in the array....
void pushZerosToEnd(int arr[],int n)
{
	int i,k=0;
	int a[n];
	printf("\nOutput:");
//Assigning the non-zero element orderly from first....... 	
	for(i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			arr[k]=arr[i];
			k++;
		}
	}
//Assigning the zero to end the array till the array length......
	for(i=k;i<n;i++)
	{
		arr[i]=0;
	}
//Printing the modified array.....	
	for(i=0;i<n;i++)
	{
		printf("[%d]  ",arr[i]);
	}
}
/*Output :
PS C:\TDM-GCC-64\myprogram> gcc 33-push.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter no. of elements to be entered in the array :8
Enter the elements in the array :
Enter the element :5
Enter the element :3
Enter the element :0
Enter the element :1
Enter the element :3
Enter the element :0
Enter the element :8
Enter the element :0
Input :[5]  [3]  [0]  [1]  [3]  [0]  [8]  [0]
Output:[5]  [3]  [1]  [3]  [8]  [0]  [0]  [0]
PS C:\TDM-GCC-64\myprogram> gcc 33-push.c -o a
PS C:\TDM-GCC-64\myprogram> ./a
Enter no. of elements to be entered in the array :7
Enter the elements in the array :
Enter the element :10
Enter the element :20
Enter the element :0
Enter the element :0
Enter the element :0
Enter the element :30
Enter the element :60
Input :[10]  [20]  [0]  [0]  [0]  [30]  [60]
Output:[10]  [20]  [30]  [60]  [0]  [0]  [0]
*/