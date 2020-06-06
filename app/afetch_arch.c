#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AUTHOR "Adhiraj Sirohi"
#define VERSION "v0.5 BETA"
#define GIT "https://github.com/Brutuski/A-Fetch"

#define OS "Arch Linux"

#define RED "\033[34m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define NOBOLD "\033[22m"

void help() {
    printf(YELLOW"A-Fetch"RESET ": ");
    printf(BOLD YELLOW"A" NOBOLD RESET);
    printf("nother simple ");
    printf(BOLD YELLOW"Fetch"NOBOLD RESET);
    printf(" program to display minimal system information \n");
    printf("Usage: $a-fetch \n");
    printf("Following information is displayed: \n");
    printf("\t \t OS Name: \n");
    printf("\t \t OS Kernel Version: \n");
    printf("\t \t Up Time: \n");
    printf("\t \t Shell: \n");
    printf("\t \t Packages: \n");
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
}

void user() {
    char *user_name;
    user_name=(char *)malloc(10*sizeof(char));
    user_name = getlogin();
    printf(RED"=============" OS "=============" RESET"\n\n");
    printf(BOLD MAGENTA"  User:      "RESET NOBOLD); 
    printf(GREEN"%s", user_name, RESET);
    printf("\n");
}
void host(char* HOST) {
    char host_name[50];
    FILE *fp = popen(HOST, "r");
    fscanf(fp, "%s", host_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Hostname:  "RESET NOBOLD); 
    printf(GREEN"%s", host_name, RESET);
    printf("\n");
}

void kernel(char* KERNEL) {
    char kernel_name[50];
    FILE *fp = popen(KERNEL, "r");
    fscanf(fp, "%[^\n]", kernel_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Kernel:    "RESET NOBOLD);
    printf(GREEN"%s", kernel_name, RESET);
    printf("\n");
}

void packages(char* PACKAGES) {
    int pacman;
    FILE *fp = popen(PACKAGES, "r");
    fscanf(fp, "%d", &pacman);
    pclose(fp);
    printf(BOLD MAGENTA"  Packages:  "RESET NOBOLD);
    printf(GREEN"%d", pacman, RESET);
    printf("\n");
}

void shell(char* SHELL) {
    char shell_name[50];
    FILE *fp = popen(SHELL, "r");
    fscanf(fp, "%s", shell_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Shell:     "RESET NOBOLD);
    printf(GREEN"%s", shell_name, RESET);
    printf("\n");
}

void uptime(char* UPTIME) {
    char * up = malloc(100) ;
    FILE *fp = popen(UPTIME, "r");
    fscanf(fp, "%[^\n]", up);
    pclose(fp);
    printf(BOLD MAGENTA"  Uptime:    "RESET NOBOLD);
    printf(GREEN"%s", up, RESET);
    printf("\n");
}

void desktop_env(char* DE) {
    char de[50] ;
    FILE *fp = popen(DE, "r");
    fscanf(fp, "%s", &de);
    pclose(fp);
    printf(BOLD MAGENTA"  DE:        "RESET NOBOLD);
    printf(GREEN"%s", de, RESET);
    printf(RED"\n\n===================================="RESET);
    printf("\n");

}

int main (int argc, char *argv[]) { 
    char *HOST = "cat /etc/hostname";
    char *KERNEL = "uname -rs";
    char *PACKAGES = "pacman -Q | wc -l";
    char *SHELL = "basename \"$SHELL\"";
    char *UPTIME = "uptime -p | sed 's/up //'";
    char *DE = "echo $XDG_CURRENT_DESKTOP  ";

    if  (argc == 1) {
        user();
        host(HOST);
        kernel(KERNEL);
        packages(PACKAGES);
        shell(SHELL);
        uptime(UPTIME);
        desktop_env(DE);
    }

    if (argc >= 2) {
        if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h") == 0)){
            help();
        }

        else if ((strcmp(argv[1], "--version") == 0 ) || (strcmp(argv[1], "-v") == 0)) {
            version();
        }

        else {
            printf(RED"Error! not a recognized command\n"RESET);
            printf(YELLOW"See --help for more options\n"RESET);
        }
    }
}