#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define NULLUT (struct utmp *) NULL
#define BUF_SZ 4
#define UTMP_SZ sizeof(struct utmp)
char buf[BUF_SZ * UTMP_SZ];
int utmp_reload();

int utmp_fd;
int cur, num;
int utmp_open(char * utmp_path){
    utmp_fd = open(utmp_path, O_RDONLY);
    cur = num = 0;
    return utmp_fd;
}

struct utmp * utmp_next(){
    struct utmp * rtn_utmp;
    if(utmp_fd == -1) return NULLUT;
    
    if(cur == num && utmp_reload() == 0){
        return NULLUT;
    }
    rtn_utmp = (struct utmp *)&buf[cur * UTMP_SZ];
    cur ++;
    return rtn_utmp;
    
}


int utmp_reload(){
    int read_num;
    read_num = read(utmp_fd, buf, BUF_SZ * UTMP_SZ);
    
    num = read_num/ UTMP_SZ;
    cur =0;
    return num;
}
void utmp_close(){
    close(utmp_fd);
}