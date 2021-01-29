#include <stdio.h>

//first part
// int sum(int a,int b, int c){
//     return (a+b+c);
// }
// void sum1(int a, int b, int c){
//     printf("The sum using void is %d\n",a+b+c);
// }
// int main()
// {
//     int a,b,c;
//     scanf("%d %d %d",&a,&b,&c);
//     printf("The sum of a,b,c are %d\n",sum(a,b,c));
//     sum1(a,b,c);
//     return 0;
// }

//2nd part
// void swap(int* a,int* b){
//     int temp=*a;
//     *a=*b;
//     *b=temp;
// }
// int main(){
//     int a,b;
//     scanf("%d %d",&a,&b);
//     swap(&a,&b);
//     printf("Finally a=%d and b=%d\n",a,b);
// }

//3rd part
// int main(){
//     int n;
//     scanf("%d",&n);
//     int ar[n];
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         scanf("%d",&ar[i]);
//     }
//     int* p=ar;
//     int sum=0;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         sum=sum+*(p+i);
//     }
//     printf("The sum is %d",sum);

//     return 0;
// }

// //4th part
// int main()
// {
//     int a,b;
//     scanf("%d %d",&a,&b);
//     int ar1[a][b], ar2[a][b];
//     for (int i = 0; i < a; i++){
//         for (int j = 0; j < b; j++)
//         {
//             /* code */
//             scanf("%d %d",&ar1[i][j],&ar2[i][j]);
//         }
//     }

//     for (int i = 0; i < a; i++)
//     {
//         /* code */
//         for (int j = 0; j < b; j++)
//         {
//             /* code */
//             printf("%d\t",*(*(ar1+i)+j));
//         }printf("\n");
//     }

//     printf("\n");
//     for (int i = 0; i < a; i++)
//     {
//         /* code */
//         for (int j = 0; j < b; j++)
//         {
//             /* code */
//             printf("%d\t",*(*(ar2+i)+j));
//         }printf("\n");
//     }
//     int ar[a][b];
//     for (int i = 0; i < a; i++)
//     {
//         /* code */
//         for (int j = 0; j < b; j++)
//         {
//             /* code */
//             *(*(ar+i)+j)=*(*(ar1+i)+j)+*(*(ar2+i)+j);
//         }

//     }
//     printf("\n");
//     for (int i = 0; i < a; i++)
//     {
//         /* code */
//         for (int j = 0; j < b; j++)
//         {
//             /* code */
//             printf("%d\t",*(*(ar+i)+j));
//         }printf("\n");
//     }

//     return 0;
// }



int main()
{
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d", &ar[i]);
    }
        /* code */
        for (int i = 0; i < (n / 2); i++)
        {
            /* code */
            int temp = *(ar+i);
            *(ar+i) = *(ar+n - i - 1);
            *(ar+n - i - 1) = temp;
        }


    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d", ar[i]);
    }

    return 0;
}