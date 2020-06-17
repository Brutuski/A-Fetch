#include "afetch.h"

#define OS "MacOS"


void user() {
    char *user_name;
    user_name=(char *)malloc(10*sizeof(char));
    user_name = getlogin();
    printf(RED"================" BOLD OS NOBOLD "=================" RESET"\n\n");
    printf(BOLD MAGENTA"  User:        "RESET NOBOLD); 
    printf(GREEN);
    printf("%s %s", user_name, RESET);
    printf("\n");
}

void host(char* HOST) {
    char host_name[50];
    FILE *fp = popen(HOST, "r");
    fscanf(fp, "%s", host_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Hostname:    "RESET NOBOLD); 
    printf(GREEN);
    printf("%s %s", host_name, RESET);
    printf("\n");
}

void kernel(char* KERNEL) {
    char kernel_name[50];
    FILE *fp = popen(KERNEL, "r");
    fscanf(fp, "%[^\n]", kernel_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Kernel:      "RESET NOBOLD);
    printf(GREEN);
    printf("%s %s", kernel_name, RESET);
    printf("\n");
}

void product_version(char* PROD_VERSION) {
    char prod_version[50];
    FILE *fp = popen(PROD_VERSION, "r");
    fscanf(fp, "%[^\n]", prod_version);
    pclose(fp);
    printf(BOLD MAGENTA"  OS Version:  "RESET NOBOLD); 
    printf(GREEN);
    printf("%s %s", prod_version, RESET);
    printf("\n");
}

void shell(char* SHELL) {
    char shell_name[50];
    FILE *fp = popen(SHELL, "r");
    fscanf(fp, "%s", shell_name);
    pclose(fp);
    printf(BOLD MAGENTA"  Shell:       "RESET NOBOLD);
    printf(GREEN);
    printf("%s %s", shell_name, RESET);
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
    printf(GREEN);
    printf("%s / %s %s", used, total,  RESET);
    printf("\n");
}

void uptime(char* UPTIME) {
    char * up = malloc(100) ;
    FILE *fp = popen(UPTIME, "r");
    fscanf(fp, "%[^\n]", up);
    pclose(fp);
    printf(BOLD MAGENTA"  Uptime:      "RESET NOBOLD);
    printf(GREEN);
    printf("%s %s", up, RESET);
    printf(RED"\n\n======================================"RESET);
    printf("\n");
}

int main (int argc, char *argv[]) { 
    system("clear");
    char *HOST = "hostname";
    char *KERNEL = "uname -rs";
    //char *PROD_NAME = "sw_vers -productName";
    char *PROD_VERSION = "sw_vers -productVersion";
    char *SHELL = "basename \"$SHELL\"";
    char *USED_SPACE = "df -h / | tail -1 | awk '{print $3}' ";
    char *TOTAL_SPACE = "df -h / | tail -1 | awk '{print $2}' ";
    char *UPTIME = "uptime | awk -F, '{sub(\".*up \",x,$1);print $1}' | sed -e 's/^[ \t]*//'";

    if  (argc == 1) {
        user();
        host(HOST);
        kernel(KERNEL);
        product_version(PROD_VERSION);
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