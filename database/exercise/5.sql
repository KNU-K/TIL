use db_learn_prac;

# table 생성
create table test_student(
    st_id char(100) not null,
    st_name char(100) not null,
    st_depart char(100) not null,
    PRIMARY key(st_id)
);

# insert
insert into test_student values('s2021428507','강태현', '컴퓨터학부');

# 컬럼 추가
alter table test_student add column st_grade int(4);

# 컬럼 1개 수정
update test_student set st_grade = 3 where st_id = 's2021428507'

# 컬럼 제거
alter table test_student drop column st_grade;

#개체 집합 삭제
TRUNCATE test_student;

# table 삭제
drop table test_student;

#select 확인
select * from test_student;
#table 확인
show tables;