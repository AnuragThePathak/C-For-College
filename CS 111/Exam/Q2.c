#include <stdio.h>

struct student
{
    int RollNo;
    char Name[25];
    int Age;
    float MarkPhy, MarkC, MarkMath; //MarkPhy,MarkC,MarkMath are marks in physics,c and mathematics respectively
};

int main()
{
    int i, n;
    n = 5;
    struct student s[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %[^\n] %d %f %f %f", &s[i].RollNo, s[i].Name, &s[i].Age, &s[i].MarkPhy, &s[i].MarkC, &s[i].MarkMath);
    }
    for (i = 0; i < n; i++)
    {
        printf("Details of %dth student:\n", i + 1);
        printf("Roll No. of the student is %d\nName of the student is %s\nAge of the student is %d\nAverage Mark is %f\n", s[i].RollNo, s[i].Name, s[i].Age, (s[i].MarkPhy + s[i].MarkC + s[i].MarkMath) / 3);
    }
    return 0;
}