#include<stdio.h>

int main(){
    int size;
    scanf("%d\n",&size);
    int arr[size];
    for(int i=1; i<=size; i++){
        scanf("%d ",&arr[i]);
    }
    int count = 0;
    for(int i=1; i<=size; i++){
        if(arr[i] == i){
            continue;
        }
        else if (arr[i] != i){
            for(int j=0; j<=size; j++){
                if(arr[j] == i){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
}