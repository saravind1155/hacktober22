#include <stdio.h>

void main(){
    int n,x1,x2,y1,y2,p;
    scanf("%d",&n);
    int arr[n];
    
        for (int j = 0; j < n; j++)
        {
           
            scanf("%d",&x1);
         
            scanf("%d",&y1);
            
            scanf("%d",&x2);
            
            scanf("%d",&y2);
            p=(x2/x1)+(y2/y1);
            arr[j]=p;
        }
        
        /* code */
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
        /* code */
    }
    
    
}