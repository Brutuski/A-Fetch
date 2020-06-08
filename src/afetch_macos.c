#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AUTHOR "Adhiraj Sirohi"
#define VERSION "v1.0"
#define GIT "https://github.com/Brutuski/A-Fetch"

#define OS "MacOS"

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
    printf(" program to display minimal system information \n\n");
    printf("Usage: $a-fetch \n\n");
    printf("Following information is displayed: \n");
    printf("\t \t OS Name \n");
    printf("\t \t OS Version \n");
    printf("\t \t Hostname \n");
    printf("\t \t Kernel \n");
    printf("\t \t Shell \n");
    printf("\t \t Root Drive Space \n");
    printf("\t \t Uptime \n");
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

void product_version(char* PROD_VERSION) {
    char prod_version[50];
    FILE *fp = popen(PROD_VERSION, "r");
    fscanf(fp, "%[^\n]", prod_version);
    pclose(fp);
    printf(RED"================" OS "=================" RESET"\n\n");
    printf(BOLD MAGENTA"  OS Version:        "RESET NOBOLD); 
    printf(GREEN"%s", prod_version, RESET);
    printf("\n");
}
void user() {
    char *user_name;
    user_name=(char *)malloc(10*sizeof(char));
    user_name = getlogin();
    printf(BOLD MAGENTA"  User:        "RESET NOBOLD); 
    printf(GREEN"%s", user_name, RESET);
    printf("\n");
}

void host(char* HOST) {
    char host_name[50];
    FILE *fp = popen(HOST, "r");
    fscanf(fp, "%s", host_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Hostname:    "RESET NOBOLD); 
    printf(GREEN"%s", host_name, RESET);
    printf("\n");
}

void kernel(char* KERNEL) {
    char kernel_name[50];
    FILE *fp = popen(KERNEL, "r");
    fscanf(fp, "%[^\n]", kernel_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Kernel:      "RESET NOBOLD);
    printf(GREEN"%s", kernel_name, RESET);
    printf("\n");
}

void shell(char* SHELL) {
    char shell_name[50];
    FILE *fp = popen(SHELL, "r");
    fscanf(fp, "%s", shell_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Shell:       "RESET NOBOLD);
    printf(GREEN"%s", shell_name, RESET);
    printf("\n");
}

void space(char* USED_SPACE, char* TOTAL_SPACE) {
    char used[50];
    char total[50];
    FILE *fp = popen(USED_SPACE, "r");
    fscanf(fp, "%[^\n]", used);
    pclose(fp);
    FILE *fp2 = popen(TOTAL_SPACE, "r");
    fscanf(fp2, "%[^\n]", total);
    pclose(fp2);
    printf(BOLD MAGENTA"  Root:        "RESET NOBOLD);
    printf(GREEN"%s / %s", used, total,  RESET);
    printf("\n");
}

void uptime(char* UPTIME) {
    char * up = malloc(100) ;
    FILE *fp = popen(UPTIME, "r");
    fscanf(fp, "%[^\n]", up);
    pclose(fp);
    printf(BOLD MAGENTA"  Uptime:      "RESET NOBOLD);
    printf(GREEN"%s", up, RESET);
    printf(RED"\n\n======================================"RESET);
    printf("\n");
}

int main (int argc, char *argv[]) { 
    system("clear");
    char *HOST = "hostname";
    char *KERNEL = "uname -rs";
    char *PROD_NAME = "sw_vers -productName";
    char *PROD_VERSION = "sw_vers -productVersion";
    char *SHELL = "basename \"$SHELL\"";
    char *USED_SPACE = "df -h / | tail -1 | awk '{print $3}' ";
    char *TOTAL_SPACE = "df -h / | tail -1 | awk '{print $2}' ";
    char *UPTIME = "uptime | awk -F, '{sub(\".*up \",x,$1);print $1}' | sed -e 's/^[ \t]*//'";

    if  (argc == 1) {
        product_version(PROD_VERSION);
        user();
        host(HOST);
        kernel(KERNEL);
        shell(SHELL);
        space(USED_SPACE, TOTAL_SPACE);
        uptime(UPTIME);
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