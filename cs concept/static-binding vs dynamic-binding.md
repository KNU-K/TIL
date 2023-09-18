# Static Binding VS Dynamic Binding

> 정적 바인딩과 동적 바인딩의 예시가 모두 존재하는 JAVA를 기반으로 설명하겠다.

## What is "Binding"?

바인딩은 함수 호출 시 호출된 부분을 해당 함수의 정의와 연결하는 것을 의미

> 함수의 정의가 위치한 메모리 주소로 연결

## Static Binding (Over-Loading)

- 컴파일 시간에 결정
- 프로그램이 실행돼도 변하지않음
- 무조건적으로 Dynamic Binding보다는 빠르지않지만, 1차원적으로 보면 빠르다고 생각할 수 있다.

## Dynamic Binding (Over-Riding)

- 실행 시간에 결정
- Java에서 다형성 및 상속이 가능한 이유
- 상속 및 다형성이 적용되므로, 코드 재사용이 가능하므로, 효율적으로 가능하다.
