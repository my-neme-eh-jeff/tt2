#include <stdio.h>

void main(){
    int a[100];
    int n;
    printf("Enter the number of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

/*
    In insertion sort we have a sorted part on the left(outer i loop) and 
    unsorted part on right (inner while loop). We keep chifting our elements till our element
    from unsorted part gets its position in current sorted part. 
*/

    for(int i=1;i<n-1;i++){
        int j=i-1;
        int current = a[i]
        while(a[j]>current && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}


