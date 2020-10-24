#include <stdio.h>
#include <stdlib.h>
#include<stdarg.h>
#include<string.h>

void createArray();
void displayArray();
void sortArrayAcending();
void sortArrayDecending();
void insertAscendSort();
void insertDescendSort();
void insertArray();
void rotateArray();
void ReverseArray();
void setArray();
void AvgArray();
void sumArray();
void miniArray();
void maxArray();
void BinarySearchArray();
void LinearSearchArray();
void deleteArray();

int *arr;
int size;
int length;

int *brr;
int lengthb;

void createArray() //containing the logic for creaton of array with ability to enter the size dynamically during runtime
{

printf("Enter the size of an array\n");
scanf("%d",&size);
printf("Enter the number of elements you want to insert in the array\n");
scanf("%d",&length);
arr=(int*)malloc(size*sizeof(int));  //main array
brr=(int*)malloc(size*sizeof(int)); //temporary array
lengthb=length;
if (length<=size)
{
printf("Enter the elements inside the array\n");
for(int i=0;i<length;i++)
{
	scanf("%d",&arr[i]);
}

int free = size - length;
printf("Free space in array is %d\n",free);
}
if(length>size)
{
    printf("Array creation Failed!!!!\n");
    printf("Number of elements you want to enter is more than the size of the array\n");
    printf("array size =%d\n", size);
    printf("number of elements to be entered inside the array = %d\n",length);
}
}

void displayArray() //display Array function
{

printf("Printing the array elements\n");
for(int i=0;i<length;i++)
{
	printf("A[%d] = %d\n",i,arr[i]);
}

}

void sortArrayAcending()
{
	int temp;
	for(int i=0;i<length-1;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(arr[j]<arr[i]) //sorting array in ascending order
			{
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
			}
		}
	}
	printf("Sorting in ascending order complete!\n");
}

void sortArrayDecending()
{
	int temp;
	for(int i=0;i<length-1;i++)
	{
		for(int j=i+1;j<length;j++)
		{
			if(arr[j]>arr[i]) //sorting array in descending order
			{
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
			}
		}
	}
	printf("Sorting in descending order complete!\n");
}

void insertAscendSort() //this function will only insert the element if the array is sorted in ascending order
{
	int num;
	printf("Use this option only after you sort the array in ascending order!!!!\n");
	printf("Enter the number you want to enter inside the sorted array\n");
	scanf("%d",&num);
	int i= length-1;
	if(length == size)
	{
		printf("there is no free space in the array\n");
		printf("Insertion failed!!!!\n");
	}
	else
	{
        while(i>=0 && arr[i]>num) //shifting elements inside the array to create free space for the new element
        {
        	arr[i+1]=arr[i];
        	i--;
        }
        arr[i+1]=num; //inserting the element inside the free space created after shifting
        length++;
        int free=size-length;
        printf("Free space in array is %d \n",free);

	}
	int free = size - length;
	printf("Insertion without distortion Successful\n");
	printf("free space left inside the array = %d\n",free);
}

void insertDescendSort() //this function will only insert the element if the array is sorted in descending order
{
	int num;
	printf("Use this option only after you sort the array in descending order!!!!\n");
	printf("Enter the number you want to enter inside the sorted array\n");
	scanf("%d",&num);
	int i= length-1;
	if(length == size)
	{
		printf("there is no free space in the array\n");
		printf("Insertion failed!!!!\n");
	}
	else
	{
        while(i>=0 && arr[i]<num) //shifting elements inside the array to create free space for the new element
        {
        	arr[i+1]=arr[i];
        	i--;
        }
        arr[i+1]=num; //inserting the element inside the free space created after shifting
        length++;
        int free=size-length;
        printf("Free space in array is %d \n",free);

	}
	int free = size - length;
	printf("Insertion without distortion Successful\n");
	printf("free space left inside the array = %d\n",free);
}

void insertArray() //this function will insert the element inside the array at the position givent by the user
{

	int pos; //it will hold the position at which we want to insert the element inside the array
	int i; //loop variable
	int num; //the element you want to insert inside of an array
	int free; //it will store the free space present inside the array to store new elements
	printf("Enter the element you want to insert inside of the array\n");
	scanf("%d",&num);
	printf("Enter the position at which you want to insert the element in the array\n");
	scanf("%d",&pos);
	printf("You want to enter element %d at position %d in the array\n",num,pos);
    if(pos>size)
    {
    	printf("The desired position %d does not exist in the array......\n",pos);
    	printf("Insertion of element %d FAILED!!!!!......\n",num);
    	return;
    }

    if(length!=size)
    {
         for(i=length;i>pos;i--)
         {
         	arr[i]=arr[i-1]; //it will shift the elements from the last to the desired position by one index
         }
         arr[pos]=num; //Inserting the element inside the desired position of the array after shifting all the elements of the array 
         length++; //updating the length of the array
         printf("Insertion of element %d is Successfull!!!!!!!!........\n",num);
         
	     free = size - length; //calculation of free space present inside of an array
	     printf("Available space inside the array for new element is %d\n",free);
	     return;
    }
    else
    {
    	printf("Cannot Insert the new element %d inside the array because there is no free space\n", num);
    	printf("Maximum array capacity reached!!!!...\n");
    	printf("Array Capacity = %d\n",size);
    	return;
    }
}

void deleteArray() //this function will delete the element from the array
{

   int num; //number that you want to delete from the array
   int i; //loop variable for linear search
   int tr=0; // this variable will store true or false value of the state wheater the element is present or not
   int j; //loop variable for shifting mechanism of the elements inside the array
   int free; //it will store the free space present inside the array to store new elements

   printf("Enter the number you want to Delete from the array\n"); //Entering the number that is to be deleted 
   scanf("%d",&num);

   printf("Searching for %d in the array....\n", num);
   for(i=0;i<length;i++)
   {
   	if(num==arr[i])
   	{  
   		tr=1;
   		break;
   	}
   }

   if (tr==1)
   {
   	printf("Element %d is in position %d inside the array\n", num,i);
   	printf("Deleting element %d from position %d in the array........\n",num,i);
   	//Applying linear search operation in the array in order to find the element and delete it from the array
   //Linear search is applied here becoz it works on sorted or unsorted array
   	for(j=i;j<length-1;j++)
   	{
   		arr[j]=arr[j+1]; //it will shift the elements from the last to the desired position by one index
   	}
   	length--; //updating array length
   	free = size - length; //calculation of free space present inside of an array
   	printf("Available space inside the array for new element is %d\n",free);
   	printf("Deletion operation successfull!!!!!!!!!.........\n");
   }
   else if(length==0)
   {
   	printf("The array is empty........\n");
   }
   else
   {
   	printf("Element %d is not present inside the array\n",num);
   	printf("Deletion operation FAILED!!!!!!......\n");
   }
}

void LinearSearchArray()
{
	int num; //number that you want to search
	int i; //Linear search loop variable
	int tr=0; //boolean variable
	printf("Enter the number that you want to search inside the array\n");
	scanf("%d",&num);
	printf("Searching for %d in the array....\n", num);
   for(i=0;i<length;i++)
   {
   	if(num==arr[i])
   	{  
   		tr=1; //boolean variable
   		break;
   	}
   }
   if(tr==1)
   {
   	printf("The element %d is stored in position %d inside of the array\n",num,i);
   	printf("Linear search Successfull !!!!!......\n");
   }
   else
   {
   	printf("The element %d is not present inside the array\n", num);
   	printf("Linear search FAILED!!!!!!!!.......\n");
   }
}

void BinarySearchArray()
{
	int num; //number that you want to search inside the array

    printf("Enter the number that you want to search inside the array\n");
    scanf("%d",&num);

	for(int i=0;i<length;i++)
	{
		brr[i]=arr[i]; //copying the elements from a array to b array
	}
	int tempo; // temporary variable that is used in swapping of elements
	for(int i=1;i<lengthb;i++)  //Bubble sorting the temporary array in ascending order
	{
		for(int j=0;j<lengthb-1;j++)
		{
			if(brr[j]>brr[i]) //this logic will sort the array in ascending order
			{// swapping logic 
				tempo=brr[j];
				brr[j]=brr[i];
				brr[i]=tempo;
			}
		}
	}

    //printing the sorted array 
    printf("Sorting the array before performing binary search.......\n");
    for(int i=0;i<lengthb;i++)
    {
    	printf("%d\n",brr[i]);
    }
    
	//now we can apply binary search on the temporary array 
	int low=0; //lower bound
	int high=lengthb; //higher bound
	int mid;
	int key; //key will store mid if the num is found inside the array
	while (low<=high) // condition for the loop
	{
        mid = (low+high)/2;
        if(num == brr[mid])
        {
        	key=brr[mid];
        	break;
        }
        else if(num<brr[mid])
        {
        	high=mid-1;
        }
        else
        {
        	low=mid+1;
        }
	}

	if(key==num)
	{
        printf("The element %d is found in array\n",num);
        printf("Binary search Successfull!!!!.....\n");
    }
    else 
    {
    	printf("The element %d is not present in the array\n",num);
    	printf("Binary Search FAILED!!!!!.....\n");
    }
}

void maxArray() // to find th max value in the array
{

   int minimum = -32768;  //minimum value supported by integer data type
   for(int i=0;i<length;i++)
   {
   	if (arr[i]>minimum)
   	{

         minimum = arr[i];

   	}
   }
   printf("Maximum value present inside the array is = %d\n",minimum);
	
}

void miniArray() //to find the minimum value in the array
{
	int maximum = 32768;  //minimum value supported by integer data type
   for(int i=0;i<length;i++)
   {
   	if (arr[i]<maximum)
   	{

         maximum = arr[i];

   	}
   }
   printf("Maximum value present inside the array is = %d\n",maximum);
}

void sumArray() //it will find the sum of all elements present inside the array
{
	int sum; //for storing the sum of all the elements present inside thae array
   for(int i=0;i<length;i++)
   {
       sum=sum+arr[i];
   }
   printf("Sum of all the elements present in the array is %d\n",sum);
}

void AvgArray() //it will find the average of all the elements present inside the array
{
	int sum; //for storing the sum of all the elements present inside thae array
   for(int i=0;i<length;i++)
   {
       sum=sum+arr[i];
   }
   int avg;
   avg= sum/length;
   printf("The average of all the elements present inside the array is %d\n",avg);
}

void setArray() //it will replace the elements at a desired position in the array
{
   int num; //number that you want to set
   int pos;//position at which you want to set the number inside the array
   printf("Enter the number you want to set inside the array\n");
   scanf("%d",&num);
   printf("Enter the position at which you want to set the number in the array\n");
   scanf("%d",&pos);
   if(pos>0 && pos<=length) //Logic to check whether the position entered by the user is valid or not
   {
   	printf("the Entered position is Valid......\n");
   	printf("setting the %d inside the array at %d position\n",num,pos);
   	arr[pos-1]=num;
   }
   else
   {
   	printf("the Entered position is not valid\n");
   	printf("setting up number %d inside the array FAILED!!!!....\n",num);
   }
}

void ReverseArray() //this function will reverse the elements inside the array and then save it inside the original array
{
	
	int j = length; //it will store the length of the array
	                    //by doing that we will be able to get the last position of the element in the array
	for(int i=0;i<length;i++)
	{
		brr[j-1]=arr[i]; //copying the elements inside the temporary array in reverse order
		j--;
	}
    for(int i=0;i<length;i++)
    {
    	arr[i]=brr[i]; //copying the temp array inside the original array A 
    }
    printf("elements Reversal inside the array is Successful!!!...\n");
}

void rotateArray() //this function will rotate the elements inside the array
{

   int tempo; //temporary variable that will hold the element inside the array at 0th position temporaily
              //as in this operation we will be shifting the elements inside the array forward by one position
              //and in doing so we will loose the first element so inorder to prevent it. It is crucial to take the backup of the first element inside the array
   tempo = arr[0];
   int j;
   for(int i=0;i<length;i++)
   {
   	j=i+1;
   	arr[i] = arr[j];    //logic for shifting of elements inside the array forward by one position
   	j++;
   }

   arr[length-1]=tempo; //now copying the element that used to be at the 0th positon in the array to the last position in the array
   printf("Rotation of array elements SUCESSFUL!!!!!.....\n");

}

int main()
{
	int key; //choice for menue switch case
	int O=0; // menue loop variable
//....................................................................................
	
	do
	{
    printf("---------------------------Menue--------------------------------\n");
    printf("Press 1 to Create the Array\n");
    printf("Press 2 to Display the Array\n");
    printf("Press 3 to sort the array in ascending array\n");
    printf("Press 4 to sort the array in descending array\n");
    printf("Press 5 to insert the element inside the sorted array in ascending without distorting the element sequence\n");
    printf("Press 6 to insert the element inside the sorted array in descending without distorting the element sequence\n");
    printf("Press 7 to insert the element inside the array in a user defined position\n");
    printf("Press 8 to delete an element from the array\n");
    printf("Press 9 to perform linear search on the array\n");
    printf("Press 10 to perform binary search on the array\n");
    printf("Press 11 to find the maximum value present inside the array\n");
    printf("Press 12 to find the minimum value present inside the array\n");
    printf("Press 13 to print the sum of all the elements present inside the array\n");
    printf("Press 14 to print the average of all the elements present inside the array\n");
    printf("Press 15 to replace the element in a user defined position inside an array\n");
    printf("Press 16 to reverse the sequence of elements inside the array \n");
    printf("Press 17 to rotate the elements inside the array\n");
    printf("Press 18 to Exit the program\n");
    scanf("%d",&key);
    printf("\n");
    switch(key)
    {
    	case 1:
    	createArray(); //create array
    	printf("\n");
    	break;
    	case 2:
    	displayArray(); //display elements in array
    	printf("\n");
    	break;
    	case 3:
    	sortArrayAcending();
    	printf("\n");
    	break;
    	case 4:
    	sortArrayDecending();
    	printf("\n");
    	break;
    	case 5:
    	insertAscendSort();
    	printf("\n");
    	break;
    	case 6:
    	insertDescendSort();
    	printf("\n");
    	break;
    	case 7:
    	insertArray();
    	printf("\n");
    	break;
    	case 8:
    	deleteArray();
    	printf("\n");
    	break;
    	case 9:
    	LinearSearchArray();
    	printf("\n");
    	break;
    	case 10:
    	BinarySearchArray();
    	printf("\n");
    	break;
    	case 11:
    	maxArray();
    	printf("\n");
    	break;
    	case 12:
    	miniArray();
    	printf("\n");
    	break;
    	case 13:
    	sumArray();
    	printf("\n");
    	break;
    	case 14:
    	AvgArray();
    	printf("\n");
    	break;
    	case 15:
    	setArray();
    	printf("\n");
    	break;
    	case 16:
    	ReverseArray();
    	printf("\n");
    	break;
    	case 17:
    	rotateArray();
    	printf("\n");
    	break;
    	case 18:
    	printf("------------------------Developer info----------------------\n");
    	printf("Name:- Aditya Kumar\n");
    	printf("Course:-B.Tech CS\n");
    	printf("Year:-2nd tear\n");
    	printf("Roll Number:-1901230100001\n");
    	printf("college code:-123\n");
    	printf("\n");
    	printf("Program terminated by the user........\n");
    	O=4000;
    	printf("\n");
    	break;
    	default:
    	printf("wrong choice\n");
    	printf("\n");
    	break;
    }

	}while(O<3000);
	return 0;
}