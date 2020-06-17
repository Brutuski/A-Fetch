#if !defined (BRYTE_H)
#define BRYTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

#define AUTHOR "Adhiraj Sirohi"
#define VERSION "v1.5"
#define GIT "https://github.com/Brutuski/A-Fetch"
#define LOGO "Vasundhara Sharma (https://www.behance.net/vasundhsharma)"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[33m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

#define BOLD "\033[1m"
#define ITALIC "'\033[3m'"
#define UNDERLINE "'\033[4m'"
#define NOBOLD "\033[22m"

#endif

void help() {
    printf(BOLD YELLOW"A-Fetch: " NOBOLD RESET );
    printf(BOLD YELLOW"\tA" NOBOLD RESET);
    printf("nother "BOLD YELLOW"Fetch"NOBOLD RESET);
    printf(" program to display minimal system information \n");
    printf("\t \tWritten in C.\n\n");
    printf(BOLD"Usage:"NOBOLD ITALIC"\t$a-fetch"RESET);
    printf(BOLD"\n\nInfo fetched:"NOBOLD);
    printf("\tOS Name\n");
    printf("\t\tUser\n");
    printf("\t\tHostname\n");
    printf("\t\tKernel Version\n");
    printf("\t\tOS Version\n");
    printf("\t\tNo. of Packages\n");
    printf("\t\tRoot Drive Usage\n");
    printf("\t\tShell\n");
    printf("\t\tUp Time\n");
    printf("\t\tDesktop Environment\n");
}

void version() {
    printf(BOLD"Author:\t \t " NOBOLD);
    printf(AUTHOR);
    printf("\n");
    printf(BOLD"Version:\t " NOBOLD);
    printf(VERSION);
    printf("\n");
    printf(BOLD"Git Link:\t " NOBOLD);
    printf(GIT);
    printf("\n");
    printf(BOLD"Logo courtesy:\t " NOBOLD);
    printf(LOGO);
    printf("\n");
}