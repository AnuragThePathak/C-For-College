#include <stdio.h>
struct student
{
    char name[20];
    int roll;
};
struct student setInfo(struct student s)
{
    static int roll=1;
    s.roll=roll;
    roll++;
    return s;
}
int main()
{
    struct student s;
    scanf("%[^\n]",s.name);
    s=setInfo(s);
    printf("%d\n",s.roll);
    return 0;
}