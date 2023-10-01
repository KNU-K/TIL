use db_learn_prac;
# table 생성
create table test_student(
    st_id char(100) not null,
    st_name char(100) not null,
    st_depart char(100) not null
);

-- primary key 만들기
alter table test_student add primary key(st_id);

-- index 상태 보기 Key_name이 primary로 바뀐걸 볼 수 있음 s_id
show index from test_student;

-- 일반 인덱스 생성
alter table test_student add index index_st_name(st_name);


-- 고유 인덱스 생성
alter table test_student add unique index index_st_depart(st_depart);

-- index 상태 보기 Key_name이 primary로 바뀐걸 볼 수 있음 s_id


alter table test_student add index index_two_column(st_name, st_depart);

show index from test_student;

--alter table [table_name] drop primary key
alter table test_student drop primary key;

--alter table [table_name] drop index [index_name]
alter table test_student drop index index_two_column;


