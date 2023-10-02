#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define COPYMODE 0664
#define BUF_SZ 4096

void err_handler(const char *);
char * getfilename(char *);
// a and b is same file.
// if type of b is path 
// same file with a in b  

int main(int argc, char * argv[]){
    if(argc != 3){
        //err;
    }
    struct stat info;
    char buf[BUF_SZ];
    char * file1 = argv[1];
    char * file2 = argv[2];
    int in_fd, out_fd;
    int read_len =0;

    if((in_fd=open(file1, O_RDONLY))== -1){
        //err;
        err_handler("open err");
    }
    
    if(strcmp(file1, file2) == 0){
        if(close(in_fd) == -1){
            err_handler("close err");
        }
        err_handler("same file err");
    }

    if(stat(file2, &info)!= -1 && S_ISDIR(info.st_mode)){
        if(chdir(file2)==0){
            strcpy(file2,getfilename(file1));
        }
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
char * getfilename(char * file_path){
    int len = strlen(file_path);
    int i=0,cnt =0;
    for(i= len-1; i>=0; i--){
        if(file_path[i] == '/'){
            break;       
        }else{
            cnt ++;
        }
    }
    char *rtn_file_path = (char *)malloc(cnt + 1); // +1 for the null-terminator
    if (rtn_file_path == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    strncpy(rtn_file_path, &file_path[i + 1], cnt);
    rtn_file_path[cnt] = '\0'; // Null-terminate the string

    return rtn_file_path;
    
}
void err_handler(const char * msg){
    fprintf(stderr,"%s\n", msg);
    exit(1);
}