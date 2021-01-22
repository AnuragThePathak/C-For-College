#include <stdio.h>

int main(){
{
    int ar1[5];
    int ar2[] = {1, 3, 4, 7,9};

    //searching a number in the array
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &ar1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("The %d th element is %d\n ", (i + 1), ar1[i]);
    }

    int x;
    printf("Type the element want to be searched:");
    scanf("%d",&x);
    int flag,j;
    for (int i = 0; i < 5; i++)
    {

        if (ar1[i] ==x)
        {
            flag=1;
            j=i;
        }
    }
    if (flag==1)
    {
        /* code */
        printf("The element is ar[%d]\n",j);
    }
    else{
        printf("The number is not present");
    }

    //Finding match between two arrays
    for(int i=0;i<5;i++){
        for(int k=0;k<5;k++){
            if(ar1[i]==ar2[k]){
                printf("ar1[%d] and ar2[%d] are same\n",i,k);
            }
        }
    }

    //Finding sum of combination match
    int val=10;
    for(int i=0;i<5;i++){
        for(int k=0;k<5;k++){
            if((i!=k)&&(ar1[i]+ar1[k]==10)){
                printf("ar1[%d] and ar1[%d]\n",i,k);
            }
        }
    }

    // Finding number of pairs satisfying i<j where i and j are indices of elements of array
    for (int i = 0; i < 5; i++)
    {
        for(int k=0;k<5;k++)
        {
            if((i<k)&&(ar1[i]==ar1[k]))
            {
                printf("(%d,%d)",i+1,k+1);
            }
        }
    }

    // // finding number pairs of euqual elements 
    int y=0;
    for(int i=0;i<5;i++)
    {
        for(int k=0;k<5;k++)
        {
            if((i<k)&&(ar1[i]==ar1[k]))
            {
                y++;
            }
        }
    }
    printf("The number of matches is %d\n",y);

    // finding trace of a diagonal matrix(2D array starts)
    int ar[3][3];
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++){
            scanf("%d",&ar[i][k]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int k=0;k<3;k++){
            printf("%d\t",ar[i][k]);
        }
        printf("\n");
    }
    printf("The trace is %d\n",ar[0][0]+ar[1][1]+ar[2][2]);

    return 0;
}