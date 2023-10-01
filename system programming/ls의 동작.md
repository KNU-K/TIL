## [ls 기본 동작](./excercise/ls1.c)

아래의 매커니즘이 ls 의 기본 매커니즘이다.

```
[default 매커니즘]

 DIR_P = opendir(file_path)
 dirent_p = readdir(DIR_P) <--------------------┐
    dirent_p->d_name 을 stat로 상세히 보기       │
    display                                     │
     └------------------------------------------┘
```

## [ls -l (상세 리스트화)](./excercise/ls2.c)

ls의 경우 **-l** 옵션이 존재하는데, 이는 조금 더 상세화(listed)해서 화면 상에 표시 해준다.

기본 매커니즘과 같지만, display 를 조금 더 세분화하여, 내용을 도식화하게 된다.

즉 "같은 기능"이며, display 로 user 가 보게되는 ui 부분만 조금 더 상세할 분 동일 기능이라고 봐도 무방하다.

[파일 유형][USER|GROUP|OTHER 권한] [link 수] [UID] [GID] [파일 크기] [날짜] [파일 명]

- 파일 유형
  - 'b' (block file) : S_ISBLK(st_mode)
  - 'c' (char file) : S_ISCHR(st_mode)
  - 'd' (directory file) : S_ISDIR(st_mode)
  - '-' (default file) : S_ISREG(st_mode)

위의 파일 유형은 **sys/stat.h** 에 정의되어있는 매크로 변수로 판별 가능 하다.

- 권한

  - rwx 로 판별 되며, 이는 8진수로 구분 가능 하다.

    rwx((OCT)111 : (DEC)7) 각 8진수 자릿수당 r(read),w(write),x(execute)와 대응 된다.

    > 권한이 없는 자리는 '-'이 들어 간다.

    > 이를 확인하기 위해서 bitmasking 을 진행하여 r w x 와 대응되는지 여부를 판별한다.

- 특수 권한 ( 나중에 정리 )

  - set-uid
  - set-gid
  - sticky-bit

- link 수

  현재 파일을 링크하고 있는 링크파일의 수를 말한다.

- UID
  파일을 소유하고있는 USER 를 표기한다.

- GID
  파일을 소유하고있는 GROUP 을 표기한다.

ls의 명령어를 구현할 때는 파일의 위치를 고려해야한다. argv 값에 절대 경로를 넣어주게 되더라도 상대경로로 인식하기 때문에 chdir 로 폴더의 경로를 변경한 뒤에 getcwd(buf, sz) 로 buf 에 path 값을 불러온 이후 ls 를 진행 해야한다.

> 경로를 변경하지 않으면, 경로상의 절대경로와 상대경로가 모호에 에러가 발생할 가능성이 높다.
