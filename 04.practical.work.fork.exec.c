#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main() {
        int pid = fork();

        if(pid){
            wait(NULL);
            pid = fork();

            if(pid){
                wait(NULL);
            } else if(pid == 0){
                printf("Executing free -h...\n");
                char *arg[] = {"/usr/bin/free", "-h", NULL};
                execvp(arg[0], arg);
                }
            } else{
                printf("error forking\n");
        } else if(pid == 0){
            printf("Executing ps -ef...\n");
            char *arg[] = {"/bin/ps", "-ef", NULL};
            execvp(arg[0], arg);
        } else{
            printf("error forking\n");
        }

    return 0;
}
