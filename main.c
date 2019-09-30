#include <stdio.h>

#define _POSIX_C_SOURCE 199309L

#include <signal.h>
#include <stdlib.h>

void my_handler(int sig, siginfo_t *info, ucontext_t *ucontext)
{
    ucontext_t *l_ucontext = ucontext;
}

char *caller()
{
    char *volume = "";
    volume[0] = '\0'; // deliberately wrong
    return volume;
}

int main()
{
    printf("Hello, World!\n");

    struct sigaction act = {0};
    act.sa_sigaction = my_handler;
    act.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &act, NULL);

    char *c = caller();
    printf("%s", c);
    return 0;
}