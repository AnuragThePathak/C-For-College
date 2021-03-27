#include <stdio.h>

int main()
{
    printf("Time is %s\nDate is %s\n",__TIME__, __DATE__);
    printf("ANSI: %d\n",__STDC__);
    printf("version: %ld\n",__STDC_VERSION__);
    return 0;
}