# include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}


int partition(int arr[], int low, int high){
    int pivot  = arr[high];
    int i = (low - 1);
    int j;
    for(j=low; j<=high-1; j++){
        if(arr[j]< arr[pivot]){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[high], &arr[i+1]);
    return (i+1);
}


void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

void printArray(int arr[], int size){
    // int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}


int main(){

    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: n"); 
    printArray(arr, n); 
    return 0; 







    return 0;
}