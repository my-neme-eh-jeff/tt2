#include <stdio.h>
#include <stdbool.h>

int x;

void main(){
    int a[100];
    int n;
    printf("Enter the number of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be searched");
    scanf("%d",&x);    
    bool flag = binary(a,0,n-1,x)
}

bool binary(int a[], int l, int r,int x){
    if(l>r){
        return ;
    }
    int mid = (l+r)/2;

    if(a[mid]<x){
        binary(a,mid+1,x);
    }else if(a[mid>x]){
        binary(a,l,mid-1,x);
    }else{
        return true;
    }
}