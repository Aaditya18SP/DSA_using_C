#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.Menu options
enum MenuOptions{
    TRAVERSE=1,
    INSERT=2,
    DELETE=3,
    SEARCH=4,
    SORT=5,
    MERGE=6
};

int displayMenuOptions(){
    int selectedOption;
    printf("Select the operation you want to perform:\n 1.Traverse the array \n 2. Insert an element \n 3. Delete an element \n 4. Search for an item \n 5. Sort the array \n 6. Merge arrays\n Enter your option here:");
    scanf("%d",&selectedOption);
    return selectedOption;

}

//2. Traverse the array/ Display the array elements
void traverseArray(int* array, int size){
    printf("\n");
    for(int index=0;index<size;index++){
        printf("%d ", *(array+index));
    }
    printf("\n");
}

//3. Insert an element in an array
void insert(int *array, int size, int elementToInsert, int indexToInsertAt){
    int isLastPositionEmpty=0,isSlotEmpty=0;
    if(*(array+(size-1)) ==0){
        isLastPositionEmpty=1;
    }

    if(*(array+indexToInsertAt)==0){
        isSlotEmpty=1;
    }

    if(isSlotEmpty){
        *(array+indexToInsertAt)=elementToInsert;
    }
    else if(isLastPositionEmpty){
            for(int index=indexToInsertAt;index<size-1;index++){
                *(array+index+1)=*(array+index);
            }
        *(array+indexToInsertAt)=elementToInsert;

    }
    else{
        printf("Array is full\n");
    }
    
}

//4.Delete
void delete(int* array, int size,int elementToDelete){
    int startMovingElements=0;
    int indexAtWhichElementIs=-1;
    for(int index=0;index<size;index++){
        if(elementToDelete==*(array+index) && !startMovingElements){
            indexAtWhichElementIs=index;
            startMovingElements=1;
            printf("Element deleted at:%d", index);

            if(index==size-1){
                *(array+index)=0;//soft-delete the element
            }
            else{
                *(array+index)=*(array+index+1);
            }
            //break;
        }
        else if(index==size-1 && indexAtWhichElementIs==-1){
            printf("Element is not present");
        }
        else if(startMovingElements){
            if(index==size-1){
                *(array+index)=0;//soft-delete the element
            }
            else{
                *(array+index)=*(array+index+1);
            }

        }
    }

}



void bubbleSort(int *array, int size){
    //sort the array
        for(int index=0; index<size; index++){
            for (int inner_index=index; inner_index<size;inner_index++){
                if( *(array+index) > *(array+inner_index)){
                    int k= *(array+index);
                    *(array+index)=*(array+inner_index);
                    *(array+inner_index)=k;
                }
            }
        }
}


//6. search for an element
void search(int array[], int size, int elementToSearch){
    int searchMethod;
    printf("Enter which search method to use:\n 1. Linear search \n 2.Binary search\n");
    scanf("%d",&searchMethod);

    if(searchMethod==1){

        for(int index=0; index<size;index++){
            if(*(array+index)==elementToSearch){
                printf("Element found at:%d", index);
                break;
            }else if(index==size-1 && *(array+index)!=elementToSearch){
                printf("Element not present in the list");
            }
        }

    }
    else if(searchMethod==2){

        bubbleSort(array,size);
        //traverseArray(array,size);


        int start=0, end=size-1;
            //printf("%d %d",start,end);
        for(int index=start; index<=end;index++){
            //printf("here");
            int middleIndex=(end + start)/2;
            //printf("%lf ", middleIndex);
            
            if(*(array+middleIndex)==elementToSearch){
                printf("Element found at %d", middleIndex);
                break;
            }

           else if(*(array+middleIndex) < elementToSearch){
                start=middleIndex;
            }
            else{
                end=middleIndex;
            }
            
        }
        

    }else{
        printf("please select a valid option");
    }
    
}

int* mergeUnsortedArrays(int *array1, int *array2,int size_array1, int size_array2){
    int* mergedArray= (int*) malloc((size_array1+size_array2)*sizeof(int));


    if(mergedArray==NULL){
        return NULL;
    }

    for(int index=0; index<size_array1;index++){
        *(mergedArray+index)=*(array1+index);
    }

    for (int index=0;index<size_array2;index++){
        *(mergedArray+index+size_array1)=*(array2+index);
    }

    //traverseArray(mergedArray,(size_array1+size_array2));

    return mergedArray;

}

int * mergeSortedArrays(int* array1, int *array2,int size_array1, int size_array2){
    //merge in ascending order
    int mergedArraysize= size_array1+size_array2;
    int* mergedArray= (int*) malloc(mergedArraysize*sizeof(int));
    int i=0,j=0,k=0;

    for(i=0,j=0,k=0; i<size_array1 && j<size_array2 && k<mergedArraysize;k++){
        
        if (*(array1+i) <= *(array2+j)){
            *(mergedArray+k)=*(array1+i);
            i++;
            
        }
        else if(*(array1+i) > *(array2+j)){
         *(mergedArray+k)=*(array2+j);
            j++;
        }

    }

    if (i==size_array1){
        //printf("j is : %d\n", j);
        while(j<size_array2){

         *(mergedArray+k)=*(array2+j);
            j++;
            k++;
        }
    }
    else if(j==size_array2){
        while(i<size_array1){
         *(mergedArray+k)=*(array1+i);
            i++;
            k++;
        }
 
    }

    return mergedArray;
}


int main(int argc, char** argv){
    int array[10]={1,3,4,2,5,25,21245,5,3,53534};
    int array2[5]={567,4343,34634,632,343};
    int sortedArray1[5]={11,13,15,17,91};
    int sortedArray2[5]={22,44,69,238,10002};
    printf("size of array is :%lu\n", sizeof(array));
    //search(array,10, 4);
    /*
    traverseArray(array,10);
    delete(array,10,4);
   traverseArray(array,10);
    insert(array, 10, 1808,4);
    traverseArray(array,10);
*/

int userOptionSelected=displayMenuOptions();
switch(userOptionSelected){
    case TRAVERSE:
    traverseArray(array,10);
    break;
    case INSERT:
    insert(array,10,1808,4);
    break;
    case DELETE:
    delete(array,10,4);
    break;
    case SEARCH:
    search(array,10,4);
    break;
    case SORT:
    bubbleSort(array,10);
    break;
    case MERGE:{
    int* newArray=mergeUnsortedArrays(array, array2,10,5);
    traverseArray(newArray,(10+5));

    int* sortedNewArray= mergeSortedArrays(sortedArray1, sortedArray2, 5,5);
    traverseArray(sortedNewArray,10);

    break;
    }
    default:
    printf("Please select a valid option");
    
}

return 0;

}
