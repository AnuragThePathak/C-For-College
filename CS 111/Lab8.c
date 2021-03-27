#include <stdio.h>

int main()
{
    // typedef struct student
    // {
    //     int roll_no[5], age[5], mark[5];
    //     char name[20];
    // } ep;

    // for(int i=0; i<5; i++){
    // ep st1;
    // scanf("%d %d %d",&st1.roll_no[i],&st1.age[i], &st1.mark[i]);
    // printf("%d",st1.roll_no[i]);
    // printf("%d",st1.age[i]);
    // printf("%d",st1.mark[i]);
    // }

    struct complex
    {
        int re, im;
    };
    void operation(struct complex num1, struct complex num2)
    {
        
    }
    struct complex num1;
    struct complex num2;
    scanf("%d %d %d %d",&num1.re,&num1.im,&num2.re,&num2.im);
    printf("Adding we get %d + %di\n",(num1.re+num2.re),(num1.re+num1.im));
    printf("Subtracting we get %d + %di\n",(num1.re-num2.re),(num1.re-num1.im));
    return 0;
    
}