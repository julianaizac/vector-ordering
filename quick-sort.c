#include<stdio.h>

void receiveInformationInVector(int *pVector, int vectorSize);
void quickSort(int *pVector, int start, int end);
int partitions(int *pVector, int start, int end);
void printVector(int *pVector, int vectorSize);

int main(){
    int vectorSize;

    printf("============= Quick Sort =============\n\n");
    printf("Inform the vector size: ");
    scanf("%i", &vectorSize);

    int vector[vectorSize];
    receiveInformationInVector(vector, vectorSize);
    quickSort(vector, 0, vectorSize - 1);
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

void quickSort(int *pVector, int start, int end){
    int pivot;
    if(end > start){
        pivot = partitions(pVector, start, end);
        quickSort(pVector, start, pivot - 1);
        quickSort(pVector, pivot + 1, end);
    }
}

int partitions(int *pVector, int start, int end){
    int left, rigth, pivot, subsidiary;

    left = start;
    rigth = end;
    pivot = *(pVector + start);

    while(left < rigth){
        while(*(pVector + left) <= pivot){
            left++;
        }
        while(*(pVector + rigth) > pivot){
            rigth--;
        }
        if(left < rigth){
            subsidiary = *(pVector + left);
            *(pVector + left) = *(pVector + rigth);
            *(pVector + rigth) = subsidiary;
        }
    }

    *(pVector + start) = *(pVector + rigth);
    *(pVector + rigth) = pivot;
    return rigth;
}

void printVector(int *pVector, int vectorSize){
    int i;

    printf("\nGrowing ordered vector: \n");
    for (i = 0; i < vectorSize; i++){
        printf("%i ", *(pVector + i));
    }
}