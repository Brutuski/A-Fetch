#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AUTHOR "Adhiraj Sirohi"
#define VERSION "v1.0"
#define GIT "https://github.com/Brutuski/A-Fetch"

#define OS "NixOS"

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
    printf("nother simple "BOLD YELLOW"Fetch"NOBOLD RESET);
    printf(" program to display minimal system information \n\n");
    printf(BOLD"Usage:"NOBOLD "$a-fetch \n\n");
    printf(BOLD"Information displayed: \n"NOBOLD);
    printf("\t\t\tOS Name\n");
    printf("\t\t\tUser\n");
    printf("\t\t\tHostname\n");
    printf("\t\t\tKernel Version\n");
    printf("\t\t\tPackages\n");
    printf("\t\t\tRoot Drive Usage\n");
    printf("\t\t\tShell\n");
    printf("\t\t\tUp Time\n");
    printf("\t\t\tDesktop Environment\n");
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
    printf(RED"===============" OS "=================" RESET"\n\n");
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

void space(char* USED_SPACE, char* TOTAL_SPACE) {
    char used[50];
    char total[50];
    FILE *fp = popen(USED_SPACE, "r");
    fscanf(fp, "%[^\n]", used);
    pclose(fp);
    FILE *fp2 = popen(TOTAL_SPACE, "r");
    fscanf(fp2, "%[^\n]", total);
    pclose(fp2);
    printf(BOLD MAGENTA"  Root:      "RESET NOBOLD);
    printf(GREEN"%s / %s", used, total,  RESET);
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
    system("clear");
    char *OS_VERSION = "nixos-version";
    char *HOST = "cat /etc/hostname";
    char *KERNEL = "uname -rs";
    char *PACKAGES = "ls /nix/store/* | wc -l";
    char *USED_SPACE = "df -h / | tail -1 | awk '{print $3}' ";
    char *TOTAL_SPACE = "df -h / | tail -1 | awk '{print $2}' ";
    char *SHELL = "basename \"$SHELL\"";
    char *UPTIME = "uptime | awk -F, '{sub(\".*up \",x,$1);print $1}' | sed -e 's/^[ \t]*//'";
    char *DE = "echo $XDG_CURRENT_DESKTOP";

    if  (argc == 1) {
        user();
        host(HOST);
        kernel(KERNEL);
        packages(PACKAGES);
        space(USED_SPACE, TOTAL_SPACE);
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