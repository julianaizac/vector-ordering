#include<stdio.h>

int menuGrowingOrDecreasing();
void receiveInformationInVector(int *pVector, int vectorSize);
void growingAndDecreasingInsertion(int *pVector, int vectorSize, int option);
void printVector(int *pVector, int vectorSize);

int main(){
    int vectorSize, option;

    printf("============ Insertion Sort ===========\n\n");
    printf("Inform the vector size: ");
    scanf("%i", &vectorSize);

    int vector[vectorSize];

    option = menuGrowingOrDecreasing();
    receiveInformationInVector(vector, vectorSize);

    growingAndDecreasingInsertion(vector, vectorSize, option);
    printVector(vector, vectorSize);

    return 0;
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

void receiveInformationInVector(int *pVector, int vectorSize){
    int i;

    printf("\n");
    for (i = 0; i < vectorSize; i++){
        printf("number %i = ", i + 1);
        scanf("%i", (pVector + i));
    }
}

void growingAndDecreasingInsertion(int *pVector, int vectorSize, int option){
    int i, j, subsidiary;

    for (i = 1; i < vectorSize; i++){
        subsidiary = *(pVector + i);
        if(option == 1){
            for (j = i; (j > 0) && (subsidiary < *(pVector + j - 1)); j--){
            *(pVector + j) = *(pVector + j - 1);
            }
        } else{
            for (j = i; (j > 0) && (subsidiary > *(pVector + j - 1)); j--){
            *(pVector + j) = *(pVector + j - 1);
            }
        }
        *(pVector + j) = subsidiary;
    }
}
void printVector(int *pVector, int vectorSize){
    int i;

    printf("\nOrdered vector: \n");
    for (i = 0; i < vectorSize; i++){
        printf("%i ", *(pVector + i));
    }
}