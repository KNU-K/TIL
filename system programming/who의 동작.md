## utmp 파일이란?

- user의 로그인, 로그아웃에 대한 정보를 담고 있다. (user history 로 보면 편하다.)

## 단일 buffer 와 buffering 구현 방식을 통한 WHO 구현

- [buffer 방식](./excercise/who1.c)

  단순하게 'struct utmp'를 1개 씩 읽어오는 형태이다.

  이 방식의 경우에는 user-level 과 kernel-level 간의 resource 교류가 많이 일어 나게 되며, 이는 시스템 성능 저하를 일으킬 수 있다. ( 속도가 느려짐 )

  일반적으로 System call function을 수행하면, kernel-level에서 수행해서 user-level로 보여주게 되는데 이 작업이 높은 COST 를 가지게 된다. 이를 막기 위해서 버퍼의 집합인 **'buffering method'** 형태로 운용을 하게 된다.

- [buffering 방식](./excercise/who2.c)

  보통 계란박스를 생각하면 편하다.

  example)

  let. 계란을 가지고 오려고한다.

        method1. 한개씩 가지고 온다.
        method2. n개의 계란을 담을 수 있는 바구니에 담아서 가지고온다.

  위의 방식으로 비유하면, method1의 방식의 경우에는 왔다갔다하는 행동을 많이 해야하는 반면에 method2는 method1에 비해 덜 왔다갔다해도 된다.

  이는 좀 더 상세히 말하면 resource 교류양을 줄임으로써, 최적화 시킨 형태인 것이다.

  자료구조에서 linked list 를 순회하는 것과 비슷한 매커니즘으로 진행된다. 이는 [utmplib.c](./excercise/utmplib.c)를 참조하면 된다.
