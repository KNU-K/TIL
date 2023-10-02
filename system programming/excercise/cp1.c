#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define COPYMODE 0664
#define BUF_SZ 4096

void err_handler(const char *);

int main(int argc, char * argv[]){
    if(argc != 3){
        //err;
    }

    char buf[BUF_SZ];
    char * file1 = argv[1];
    char * file2 = argv[2];
    int in_fd, out_fd;
    int read_len =0;

    if((in_fd=open(file1, O_RDONLY))== -1){
        //err;
        err_handler("open err");
    }
    
    if((out_fd=creat(file2, COPYMODE)) == -1){
        //err;
        
        err_handler("creat err");
    }

    while((read_len=read(in_fd,buf, BUF_SZ))> 0 ){
        write(out_fd, buf, read_len);
    }
    if(read_len == -1){
        err_handler("read err");
    }
    if(close(in_fd)==-1 || close(out_fd) == -1){
        //err;
        err_handler("close err");
    }   
}

void err_handler(const char * msg){
    fprintf(stderr,"%s\n", msg);
    exit(1);
}