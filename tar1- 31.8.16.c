//Daniel buzuky 203550744
//Or Halevy 305346835

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "list.h"

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

/* Declarations of other functions */

int * powerArray(int sz);  //for first question
int ** productMatrix( int ** mat1, int **mat2, int rows_mat1, int columns_mat2); //for the second question
int ArrayOf( int **a, int n, item **ansArray ,int m, list **ansList); //for the third question


/* ------------------------------- */

int main() {
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number)  ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do {
		for (i = 1; i<4; i++)
			printf("Ex%d--->%d\n", i, i);
		printf("EXIT-->0\n");
		do {
			select = 0;
			printf("please select 0-3 : ");
			scanf("%d", &select);
		} while ((select<0) || (select>3));
		switch (select) {
		case 1: Ex1(); break;
		case 2: Ex2(); break;
		case 3: Ex3(); break;
				}
		} while (all_Ex_in_loop && select);
	return 0;
}
/* Function definitions */

//----------------------------------------


//Exercise 1
void Ex1(){
	int * arr,j;
	int n;

	//Get array size from the user
	printf("Please input the wanted size for the array: ");
	scanf("%d", &n);

	//Send the value to createArr function
	arr = powerArray(n);
	if(!arr){ //Check if the creation and fill was successful
		puts("Error creating array\n");
		exit(1);
	}

	puts("Printing array: ");
	for(j=0; j<n; j++){
		printf("%d ", arr[j]);
	}

	//Just add an empty line at the end, and free the memory.
	puts("");


	// free arr in quest 1 if used
	if(arr != NULL)
	{
	free(arr);
	}
}



int * powerArray(int sz){
//This function creates a new array with given size
//and returns a pointer to the array.
	int prev=2, i;
	int *arr = (int *) malloc(sz*sizeof(int));
	if(!arr){
		//If an error accoured during the allocation
		//print an error msg, and return null
		puts("Error allocating memory for array");
		return NULL;
	}

	printf("Memory was allocated: %p\n", arr);
	//Done allocating memory

	//**Note: As arr[0] will ALWAYS have the value: 1,
	//I decided to hard-code it.

	arr[0]=1;
	//This part of the function will fill the array
	for(i=1; i<sz; i++){
		arr[i]=prev;
		prev*=2;
	}//End of loop

	return arr;
}

//----------------------------------------

//Exercise 2

void Ex2(){
int **mat1, **mat2; //mat1, mat2
int rows_mat1,columns_mat1,rows_mat2,columns_mat2; //rows & columns mat1+2
int *pointer; //The pointer to the Multiplied matix
int i,j;

printf("\nEnter the rows of the First matrix  =>       ");
scanf("%d",&rows_mat1);

printf("\nEnter the columns of the First matrix  =>       ");
scanf("%d" ,&columns_mat1);

printf("\nEnter the rows of the Second matrix  =>       ");
scanf("%d",&rows_mat2);

printf("\nEnter the columns of the Second matrix  =>       ");
scanf("%d",&columns_mat2);


if(columns_mat1!=rows_mat2){ // A necessary condition that matrix could multiply each other
    printf("\n\nInvalid Order of matrix (can't multiply those martices because columns of mat1 are not even the rows of mat2\n\n"); // number of columns mat1 not even the number of rows mat2
    return;
}

mat1= (int**) malloc(rows_mat1*sizeof(int*)); //malloc first mat- rows

for(i=0;i<columns_mat1;i++) //malloc first mat- columns
    mat1[i]=(int*)malloc(columns_mat1*sizeof(int));

//Input Matrix1

	printf("\nNow we will input first matrix: \n");

    for(i=0;i<rows_mat1;i++) //scan from user the integers of mat 1
	{
        for(j=0;j<columns_mat1;j++)
		{
		printf("\nfill in the [%d],[%d] =>       ",j+1, i+1);
	
        scanf("%d",&mat1[i][j]);
		}
	}
    /*
	ADDITIONAL
        //Printing Input Matrix 1
        printf("\n Entered Matrix 1: \n");
        for(i=0;i<rows_mat1;i++){
            for(j=0;j<columns_mat1;j++)
                printf("%d ",mat1[i][j]);
            printf("\n");
        }
     */

mat2= (int**) malloc(rows_mat2*sizeof(int*)); //malloc second mat - rows

for(i=0;i<columns_mat2;i++) //malloc second mat - columns
    mat2[i]=(int*)malloc(columns_mat2*sizeof(int));

//Input Matrix2

	printf("\nNow we will input second matrix: \n");

    for(i=0;i<rows_mat2;i++) //scan from user the integers of mat 2
	{
        for(j=0;j<columns_mat2;j++)
		{
			printf("\nfill in the [%d],[%d] =>       ",j+1, i+1);
            scanf("%d",&mat2[i][j]);
		}
	}

/*
 ADDITIONAL
    //Printing Input Matrix 2
       printf("\n Entered Matrix 2: \n");
for(i=0;i<rows_mat2;i++){
    for(j=0;j<columns_mat2;j++)
        printf("%d ",mat2[i][j]);
    printf("\n");
}
*/



    pointer = *productMatrix( mat1, mat2, rows_mat1, columns_mat2);

    printf("address new array is: %p and point to %d \n\n\n)", &pointer, *pointer);



	//Free question 2 memory if used (mat1+2), the thirs will free in the func
	if(mat1 != NULL)
	{
		for(i=0;i<rows_mat1;i++)
			free(mat1[i]);
		free(mat1);
	}
		if(mat2 != NULL)
	{
		for(i=0;i<columns_mat2;i++)
			free(mat2[i]);
		free(mat2);
	}

}


int **productMatrix( int ** mat1, int **mat2, int rows_mat1, int columns_mat2){

    int **multiplied_mat;
    int i,j,k; //columns & rows new array and index k

multiplied_mat=(int**)calloc(rows_mat1,sizeof(int*));

for(i=0;i<columns_mat2;i++)
    multiplied_mat[i]=(int*)calloc(columns_mat2,sizeof(int));


//Multiplication

    for(i=0;i<rows_mat1;i++){
        for(j=0;j<columns_mat2;j++){
                multiplied_mat[i][j]=0;
                for(k=0 ; k < columns_mat2 ; k++ ) // here!
                    multiplied_mat[i][j]+= mat1[i][k]*mat2[k][j];

        }
        printf("\n");
    }


    /*
     ADDITIONAL
        //Printing third mat
         *
   printf("\nThe Multiplication of two matrix is\n");
   for(i=0;i<rows_mat1;i++){
       printf("\n");
       for(j=0;j<columns_mat2;j++){
            printf("%d\t",multiplied_mat[i][j]);
   }
    printf("\n");
    }
    */

return multiplied_mat; //return address new array

	//Free question 2 memory if used (multiplied_mat)
	if(multiplied_mat != NULL)
	{
		for(i=0;i<columns_mat2;i++)
			free(multiplied_mat[i]);
		free(multiplied_mat);
	}
}


//----------------------------------------

//
////Exercise 3
void Ex3()
{
	int counter; //the counter- what the function return
	int i,j; //columns and rows
	item *ansArray = NULL;
	int **a; //the mat
	list ansList = BuildList();
	list *pAnsList = &ansList;
	int m ,n ;
	int ansSize;



	
	printf("\nEnter the rows of the matrix  =>       ");
	scanf("%d",&n);

	printf("\nEnter the columns of the matrix  =>       ");
	scanf("%d" ,&m);


			a=(int**)malloc(n*sizeof(int*));
			for(i=0;i<n;i++)
			{
				a[i]=(int*)calloc(m,sizeof(int));
			}
			for(i = 0; i < n; ++i)
			{
				for(j = 0; j < m; ++j)
				 {
					printf("Fill the element in (%d, %d)=>       ", i, j);
					scanf("%d", &(a[i][j]));
				 }
			}
			counter = ArrayOf( a, n, &ansArray , m, &pAnsList);

			/*
			ADDITIONAL- print the numbers that answer on the i+j
			for(i=0;i<ansSize;i++)
				printf("%d+%d=%d, ",ansArray[i].data, ansArray[i].i, ansArray[i].j);
			printf("\n");
			*/

			printf("The func return %d \n\n\n\n",counter); //print the  function that the function return
		


	//freeing question 3 memory if used
	if (a != NULL)
	{
		for(i=0;i<n;i++)
			free(a[i]);
		free(a);
	}
	if(ansArray != NULL)
	{
	
		free(ansArray);
	}
	FreeList(ansList);

	}

int ArrayOf( int **a, int n, item **ansArray ,int m, list **ansList)
{
	int i,j,k; //rows, columns and 
	int count = 0;
	position pos = **ansList;

	printf("\n\n--- Solve exercise ---\n"); 

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(i+j == a[i][j])
			{// if i+j=the integer in the specific array place- create new sturct
				printf("\nCreate new node (because %d + %d = %d)\n",i,j,a[i][j] );
				InsertItem(**ansList, pos, a[i][j],i,j);
				count++;
				pos = pos->next;
			}
		}

	printf("\n");



	*ansArray = (item *)malloc(count*sizeof(item));
	pos = **ansList;
	pos = pos->next;
	i=0;
	while(pos!=NULL) 
	{
		(*ansArray)[i] = *pos;
		pos = pos->next;
		i++;
	}



	return count;
}
