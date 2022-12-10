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
    In insertion sort we find out the smallest element and replace it with the index i
    There are 2 for loops and swapping takes place once. 
*/

    for(int i=0;i<n-1;i++){
        int smallest = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[smallest]){
                smallest=j;
            }
        }
        int temp;
        temp=a[smallest];
        a[smallest]=a[i];
        a[i]=temp;
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}


