#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <time.h>
#define NULLUT (struct utmp *) NULL

int utmp_open(char *);
void utmp_close();
void err_handler(const char * msg);
void print_utmp(struct utmp * );
char * time_to_string(long);
int main(){
    struct utmp * utmp, * utmp_next();
    if(utmp_open(UTMP_FILE)==-1){
        err_handler("utmp open err");
    }

    while((utmp = utmp_next()) != NULLUT){
        print_utmp(utmp);
    }

    utmp_close();
    
}
void print_utmp(struct utmp * info){
    if(info->ut_type != USER_PROCESS){
        return;
    }

    printf("%12.12s ", info->ut_user);
    printf("%12.12s ", info->ut_line);
    printf("%12.12s\n", time_to_string(info->ut_time)+4);
}

char * time_to_string(long timeval){
    return ctime(&timeval);
}

void err_handler(const char * msg){
    fprintf(stderr,"%s\n",msg);
    exit(1);
}