# DI (Dependency Injection) - 의존성에 역전을 말한다.

이것이 왜 필요한지 의아한 사람도 있을 것이고, 굳이 필요없지않을까? 라고 생각할 수 있다.

DI 는 SOLID 원칙의 D에 해당한다. SOLID 원칙은 OOP 개발에서의 안정성을 높이기 위해서 고안된 아키텍처이다.

`A--(use by creating object instance)--> B`라는 상황이 있다고 가정하자. B를 변경하면 A의 내용 또한 변경될수도 있다. 이를 막기 위해서 B의 의존성을 C에 주입을 하고 A는 그 C를 통해서 접근하는 방법을 사용하게 된다.

`A--(use created object instance)--> C --(use by creating object instance)--> B` 결국 C가 모든 의존을 받게 되고 A와 B간에 의존성은 낮아지게 된다.

이는 나중에 Testcase를 작성할 때도 유용하게 쓰일 수 있으며, 다른 모듈을 이식할 때도 추가적인 변경없이 필요한 부분만 변경할 수 있기 때문에 객체 지향의 대표적인 특정인 높은 결합도에 낮은 응집도를 갖출 수 있다.
