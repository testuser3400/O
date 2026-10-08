#include<stdio.h>
int main() {
    int i, n, k, no, avail;
    int pages[50], frames[5];
    int count = 0, j = 0;

    printf("\nHow many pages :\n");
    scanf("%d",&n);
    
    printf("\nEnter Reference String :\n");
    for(i = 0; i < n; i++){
        scanf("%d",&pages[i]);
    }

    printf("\nHow many frames :\n");
    scanf("%d",&no);
    for(i = 0; i < no; i++){
        frames[i] = -1;
    }

    printf("\nRef_String       Frames\n");

    for(i = 0; i < n; i++) {
        avail = 0;
        //check page is already present
        for(k = 0; k < no; k++){
            if(frames[k] == pages[i]){
                avail =1;
                break;
            }
        }

        if(avail == 0){
            frames[j] = pages[i];
            j = (j+1) % no;
            count++;
        }
        printf("%d  ->\t\t ",pages[i]);
        for(k = 0; k < no; k++) {
            printf("%d ",frames[k]);
        }
        printf("\n");
    }
    printf("Page Fault :%d",count);
    return 0;
}

