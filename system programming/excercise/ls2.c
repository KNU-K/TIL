#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <sys/stat.h>
#include <unistd.h>
void do_ls(char *);
void do_stat(char *);
void print_file_state(char *, struct stat *);
void mode_to_string(char *, int);
char *uid_to_string(uid_t);
char *gid_to_string(gid_t);
int main(int argc, char * argv[]){
    if(argc == 1) {
        do_ls(".");
    }else{
        while(--argc){
            printf("%s : \n", *++argv);
            if(chdir(*argv) == 0){
                char cwd[4096] = "";
                getcwd(cwd, sizeof(cwd));
                do_ls(cwd);
            }
        }
    }
}
void do_ls(char * cur_dir){
    DIR * dir_p;
    struct dirent * dirent_p;

    if((dir_p = opendir(cur_dir))==NULL){
        //err
    }

    while((dirent_p = readdir(dir_p))!= NULL){
        do_stat(dirent_p->d_name);
    }
    closedir(dir_p);
}
void do_stat(char * d_name){
    struct stat info;

    if(stat(d_name, &info)== -1){
        //err
    }else{
        print_file_state(d_name,&info);
    }   
}
void print_file_state(char * d_name, struct stat * info){

    char mode[11];
    mode_to_string(mode, info->st_mode);

    printf("%.11s ", mode);
    printf("%4d ", (int)info->st_nlink);
    printf("%11.11s ",uid_to_string(info->st_uid));
    printf("%11.11s ",gid_to_string(info->st_gid));
    printf("%5ld ", (long)info->st_size);
    printf("%12.12s ",(char *)ctime(&info->st_mtime) +4);
    printf("%s \n", d_name);
}
char * uid_to_string(uid_t uid){
    static char uidchar[10];
    struct passwd * pwd;
    if((pwd=getpwuid(uid)) == NULL){
        sprintf(uidchar, "%d",uid);
    }
        return pwd->pw_name;
}
char * gid_to_string(gid_t gid){

    static char gidchar[10];
    struct group * grp;
    if((grp=getgrgid(gid)) == NULL){
        sprintf(gidchar, "%d",gid);
    }
        return grp->gr_name;
}
void mode_to_string(char * mode, int st_mode){
    strcpy(mode,"----------");
    if(S_ISDIR(st_mode)) mode[0] = 'd';  
    if(S_ISCHR(st_mode)) mode[0] = 'c';
    if(S_ISBLK(st_mode)) mode[0] = 'b';

    if(st_mode & S_IRUSR) mode[1] = 'r';
    if(st_mode & S_IWUSR) mode[2] = 'w';
    if(st_mode & S_IXUSR) mode[3] = 'x';

    
    if(st_mode & S_IRGRP) mode[3] = 'r';
    if(st_mode & S_IWGRP) mode[4] = 'w';
    if(st_mode & S_IXGRP) mode[6] = 'x';
    
    if(st_mode & S_IROTH) mode[7] = 'r';
    if(st_mode & S_IWOTH) mode[8] = 'w';
    if(st_mode & S_IXOTH) mode[9] = 'x';
}