// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//     int pid, retnice;

//     printf("Press Ctrl+C to stop process\n");

//     pid = fork();

//     for(;;)
//     {
//         if(pid == 0)
//         {
//             retnice = nice(-5);
//             printf("Child gets higher CPU priority: %d\n", retnice);
//             sleep(1);
//         }
//         else
//         {
//             retnice = nice(4);                           
//             printf("Parent gets lower CPU priority: %d\n", retnice);
//             sleep(1);
//         }
//     }

//     return 0;
// }


#include<stdio.h>
#include<unistd.h>
int main(){
    int pid, retnice;

    pid = fork();
    for(;;){
        if(pid == 0){
            retnice = nice(-5);
            printf("Child process gets higher CPU priority : %d",retnice);
            sleep(1);
        } 
        else {
            retnice = nice(4);
            printf("Parent Process gets lower CPU priority :%d", retnice);
            sleep(1);
        }
    }

    return 0;
}