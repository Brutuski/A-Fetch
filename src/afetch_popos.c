#include "afetch.h"

#define OS "Pop!_OS"

void user() {
    char *user_name;
    user_name=(char *)malloc(10*sizeof(char));
    user_name = getlogin();
    printf(RED"================" BOLD OS NOBOLD "================" RESET"\n\n");
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

void os_ver(char* OS_VER) {
    char ver[50];
    FILE *fp = popen(OS_VER, "r");
    fscanf(fp, "%[^\n]", ver);
    pclose(fp);
    printf(BOLD MAGENTA"  OS Version:  "RESET NOBOLD);
    printf(GREEN);
    printf("%s %s", ver, RESET);
    printf("\n");
}

void packages(char* PACKAGES) {
    int pacman;
    FILE *fp = popen(PACKAGES, "r");
    fscanf(fp, "%d", &pacman);
    pclose(fp);
    printf(BOLD MAGENTA"  Packages:    "RESET NOBOLD);
    printf(GREEN);
    printf("%d %s", pacman, RESET);
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

void uptime(char* UPTIME) {
    char * up = malloc(100) ;
    FILE *fp = popen(UPTIME, "r");
    fscanf(fp, "%[^\n]", up);
    pclose(fp);
    printf(BOLD MAGENTA"  Uptime:      "RESET NOBOLD);
    printf(GREEN);
    printf("%s %s", up, RESET);
    printf("\n");
}

void desktop_env(char* DE) {
    char de[50] ;
    FILE *fp = popen(DE, "r");
    fscanf(fp, "%s", de);
    pclose(fp);
    printf(BOLD MAGENTA"  DE:          "RESET NOBOLD);
    printf(GREEN);
    printf("%s %s", de, RESET);
    printf(RED"\n\n======================================"RESET);
    printf("\n");

}

int main (int argc, char *argv[]) { 
    system("clear");
    char *HOST = "hostname";
    char *KERNEL = "uname -rs";
    char *OS_VER = "lsb_release -r -s";
    char *PACKAGES = "dpkg -l | wc -l";
    char *USED_SPACE = "df -h / | tail -1 | awk '{print $3}' ";
    char *TOTAL_SPACE = "df -h / | tail -1 | awk '{print $2}' ";
    char *SHELL = "basename \"$SHELL\"";
    char *UPTIME = "uptime -p | sed 's/up //'";
    char *DE = "echo $XDG_CURRENT_DESKTOP";

    if  (argc == 1) {
        user();
        host(HOST);
        kernel(KERNEL);
        os_ver(OS_VER);
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