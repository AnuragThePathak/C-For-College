#include <stdio.h>

int main()
{
    FILE* ptr = NULL;
    // char str[40]="This is first file.";
    ptr=fopen("fileManage.txt","w");
    // fputs("Lorem ipsum, dolor sit amet consectetur adipisicing elit. In quod perspiciatis cumque, temporibus dolor perferendis laboriosam cum! Magni, eos. Distinctio, doloribus illum. Atque laudantium nulla recusandae, nobis ipsam natus aperiam labore tempora a aliquam cupiditate facere eum eveniet facilis odit itaque, commodi sed, ullam nesciunt exercitationem nemo animi. Debitis eum quam, voluptas blanditiis distinctio porro. Quas, ab quis? Sunt voluptas modi architecto, odit illum doloremque nam aspernatur.",ptr);
    
    //***one method***
    // fprintf(ptr, "Lorem ipsum, dolor sit amet consectetur adipisicing elit. In quod perspiciatis cumque, temporibus dolor perferendis laboriosam cum! Magni, eos. Distinctio, doloribus illum. Atque laudantium nulla recusandae, nobis ipsam natus aperiam labore tempora a aliquam cupiditate facere eum eveniet facilis odit itaque, commodi sed, ullam nesciunt exercitationem nemo animi. Debitis eum quam, voluptas blanditiis distinctio porro. Quas, ab quis? Sunt voluptas modi architecto, odit illum doloremque nam aspernatur.");

    //***2nd method***
    char out[2000]="Lorem ipsum, dolor sit amet consectetur adipisicing elit. In quod perspiciatis cumque, temporibus dolor perferendis laboriosam cum! Magni, eos. Distinctio, doloribus illum. Atque laudantium nulla recusandae, nobis ipsam natus aperiam labore tempora a aliquam cupiditate facere eum eveniet facilis odit itaque, commodi sed, ullam nesciunt exercitationem nemo animi. Debitis eum quam, voluptas blanditiis distinctio porro. Quas, ab quis? Sunt voluptas modi architecto, odit illum doloremque nam aspernatur.";
    fprintf(ptr, "%s", out);
    fclose(ptr);
    return 0;
}