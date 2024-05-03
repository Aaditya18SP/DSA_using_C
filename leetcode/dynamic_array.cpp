#include <stdlib.h>
#include <stdio.h>
class DynamicArray {
    private:
        int* ptr=NULL;
        int length;
        int capacity;
public:
    //int arr[];

    DynamicArray(int in_capacity) {

        if(in_capacity>0){
            ptr=(int*)calloc(in_capacity,sizeof(int));
        }
        else{
            printf("Please enter a capacity");
        }
        capacity=in_capacity;
        length=0;
    }

    int get(int i) {
        return *(ptr+i);
    }

    void set(int i, int n) {
        int* new_ptr= ptr+i;
        *(new_ptr)=n;

    }

    void pushback(int n) {
        if(capacity==length){
            //printf("resize called");
            resize();
        }

        int* new_ptr= ptr+(length);
        *(new_ptr)=n;
        length++;
        //size_of_array++;

    }

    int popback() {
        int* last_element_ptr= ptr+length-1;
        int value_to_return=*(last_element_ptr);
        *(last_element_ptr)=0;
        length--;
        return value_to_return;
    }

    void resize() {
        int new_size= capacity*2;
        //printf("%d", new_size);
        int* new_array=(int*) calloc(new_size,sizeof(int));
        for(int index=0; index<capacity;index++){
            new_array[index]=*(ptr+index);
        }

        ptr=new_array;
        capacity=new_size;

        //printf("%d", capacity);
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;

    }

};


int main(){
    DynamicArray da= DynamicArray(1);
    printf("%d %d\n", da.getSize(),da.getCapacity());
 da.pushback(1);
    da.pushback(2);
    printf("%d %d\n", da.getSize(),da.getCapacity());
    printf("%d\n",da.get(1));
    da.set(1,3);
     printf("%d\n",da.get(1));
     da.popback();
printf("%d %d\n", da.getSize(),da.getCapacity());



    return 0;
}