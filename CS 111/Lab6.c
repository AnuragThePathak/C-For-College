#include <stdio.h>

////this method for printing fibonacci series is not good
// int term(int n){
//     if(n<3){
//         return 1;
//     }
//     else{
//         return (term(n-1)+term(n-2));
//     }
// }
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         printf("%d ",term(i));
//     }

//     return 0;
// }

// //print fibonacci
// static int n1=1,n2=1,n3;
// void fib(int n){
//     if(n>0){
//     n3=n1+n2;
//     n1=n2; n2=n3;
//     printf("%d ",n3);
//     fib(n-1);
//     }
// }

// int main(){
//     int n;
//     scanf("%d",&n);
//     printf("%d %d ",n1,n2);
//     fib(n-2);
//     return 0;
// }

// //printing sum of digits in a number
// int factorial(int n){
//     if(n<2){
//         return 1;
//     }
//     return (n*factorial(n-1));
// }
// int sum_digit(int n)
// {
//     if (n==0)
//     {
//         /* code */
//         return 0;
//     }
    
//     return ((n%10)+sum_digit(n/10));
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     printf("%d\n",sum_digit(n));
// }

// //finding exponent of a number
// int power(int a,int b){
//     if (b==1){
//         return a;
//     }
    
//     return (a*power(a,b-1));
// }
// int main(){
//     int a,b;
//     scanf("%d %d",&a,&b);
//     printf("%d\n",power(a,b));
// }

//finding if a number if palindrome or not
void pal(int n){
    int x=n,rev=0;
    for (int i = 0; x>0; x=x/10)
    {
        /* code */
        rev=rev*10+(x%10);//to understand this check for anumber. there's no other way
    }
    
    if (n==rev)
    {
        /* code */
        printf("The number is palindrome\n");
    }
    else{
        printf("Not palindrome\n");
    }
}
int main(){
    int n;
    scanf("%d",&n);
    pal(n);
}
