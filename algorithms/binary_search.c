#include <stdio.h>


int main(){

    int arr[10]={20,40,50,200,325,650,760,761,765,800};
    int start=0;
    int last=10;
    int toSearch=40;
    while(start<last){
        int middle=(last+start)/2;
        printf("calculating %d %d\n", start, last );
        if(arr[middle]==toSearch){
            printf("found %d at %d",arr[middle],middle);
            return middle;

        }
        
        else if(arr[middle]<toSearch){
            start=middle+1;

        }
        else{
            last=middle;
        }

    }

    return 0;
    }