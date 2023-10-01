#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <utmp.h>
#include <time.h>
#include <unistd.h>
void err_handler(const char *);
void print_utmp(struct utmp * info);
char * time_to_string(long);
int main(){

    struct utmp utmp_buf;
    int utmp_fd;
    if((utmp_fd=open(UTMP_FILE, O_RDONLY))== -1){
        err_handler("utmp file open err !");
    }
    int utmp_buf_sz = sizeof(utmp_buf);
    while(read(utmp_fd, &utmp_buf, utmp_buf_sz) == utmp_buf_sz){
        print_utmp(&utmp_buf);
    }
    close(utmp_fd);
    
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