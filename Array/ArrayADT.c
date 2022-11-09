 #include<stdio.h>
 #include<stdlib.h>

 struct myArray // ADT
 {
    int total_size; // Memory to be reserved
    int used_size; // Memory to be used
    int *ptr; // requests memory in heap and gives you an pointer, pointing to the first element
 };
 
 void createArray(struct myArray * a, int tSize, int uSize){

    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *) malloc(tSize*sizeof(int));

    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize*sizeof(int)); // heap memory request
 } 

 void show(struct myArray * a){ //methods
    for (int i = 0; i < a->used_size; i++){
        printf("%d\n", (a->ptr)[i]);
    }
 }

 void setVal(struct myArray *a){ //methods
    int n;
    for (int i = 0; i < a->used_size; i++){
        (a->ptr)[i] = n;
        printf("Enter element %d\n", i);
        scanf("%d", &n);
    }
 }
 int main(){
    struct myArray marks; // Makes structure and memory allocate
    createArray(&marks, 100, 4);
    setVal(&marks);
    show(&marks);
    return 0;
 }