#include<stdio.h>

void receiveInformationInVector(int *pVector, int vectorSize);
int menuGrowingOrDecreasing();
void growingAndDecreasingBubble(int *pVector, int vectorSize, int option);
void printVector(int *pVector, int vectorSize);

int main(){
    int vectorSize, option;

    printf("============= Bubble Sort =============\n\n");
    printf("Inform the vector size: ");
    scanf("%i", &vectorSize);

    int vector[vectorSize];

    option = menuGrowingOrDecreasing();

    receiveInformationInVector(vector, vectorSize);
    growingAndDecreasingBubble(vector, vectorSize, option);
    printVector(vector, vectorSize);
    return 0;
}

void receiveInformationInVector(int *pVector, int vectorSize){
    int i;

    printf("\n");
    for (i = 0; i < vectorSize; i++){
        printf("number %i = ", i + 1);
        scanf("%i", (pVector + i));
    }
}

int menuGrowingOrDecreasing(){
    int option;

    do{
        printf("\nType it:\n[1] Growing\n[2] Decreasing\n\nOption: [ ]\b\b");
        scanf("%i", &option);
        if(option != 1 && option != 2){
            printf("Invalid option, retype\n");
            system("pause");
        }
    } while (option != 1 && option != 2);
    return option;
}

void growingAndDecreasingBubble(int *pVector, int vectorSize, int option){
    int i, proceed, end = vectorSize, subsidiary;

    do{
        proceed = 0;

        for (i = 0; i < end - 1; i++){
            // growing
            if(*(pVector + i) > *(pVector + i + 1) && option == 1){ 
                subsidiary = *(pVector + i);
                *(pVector + i) = *(pVector + i + 1);
                *(pVector + i + 1) = subsidiary;
                proceed = i;
            } 
        }
        end--;
    } while (proceed != 0);
}

void printVector(int *pVector, int vectorSize){
    int i;

    printf("\nOrdered vector: \n");
    for (i = 0; i < vectorSize; i++){
        printf("%i ", *(pVector + i));
    }
}