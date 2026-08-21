# C++ 템플릿(Template) 기초 완벽 가이드

C++를 공부하면서 템플릿을 처음 접하는 초보자를 위한 설명서입니다.  
C++ 입문서인 《C++ Primer Plus》의 설명 방식처럼 탄생 배경부터 핵심 개념, 그리고 특수화(Specialization)까지 쉬운 비유로 정돈되어 있습니다.

---

## 1. 템플릿이 존재하게 된 이유 (Why?)

템플릿이 도입되기 전, 두 변수의 값을 서로 교환하는 `swap` 함수를 작성한다고 가정해 봅시다.

```cpp
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```

잘 작동하지만, `double` 타입이나 `std::string` 타입 변수를 교환하고 싶다면 C++의 **함수 오버로딩(Function Overloading)** 기능을 이용해 똑같은 함수를 타입별로 계속 만들어야 했습니다.

```cpp
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

void swap(std::string& a, std::string& b) {
    std::string temp = a;
    a = b;
    b = temp;
}
```

### 🔴 기존 방식의 문제점
1. **코드 중복**: 로직(알고리즘)은 100% 동일한데 오직 **자료형(Type)**이 다르다는 이유로 동일한 코드를 복사-붙여넣기 해야 함.
2. **유지보수 고통**: 로직에 수정 사항이 생기면 만든 모든 오버로딩 함수를 찾아가서 고쳐야 함.

### 🟢 C++ 설계자들의 해결책
> *"값을 함수 매개변수로 전달하듯이, **타입(Type) 자체를 매개변수**로 전달받아 코드를 찍어내는 틀을 만들자!"*  
> 👉 이것이 바로 **템플릿(Template)**의 탄생 목적입니다.

---

## 2. 템플릿의 핵심 개념: "붕어빵 틀"

템플릿(Template)의 본래 뜻은 **'모형', '청사진', '설계도'**입니다.

* **일반 함수 / 클래스**: 실제 구워져 나온 **붕어빵** (메모리에 실제로 생성되는 실행 코드)
* **템플릿**: 붕어빵을 찍어내는 **붕어빵 틀** (코드를 만들기 위한 설계도)

```cpp
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

* `T`: 어떤 타입이 올지 지정하지 않은 **타입 매개변수(Type Parameter)**입니다.
* 소스코드에서 `swap(x, y)`를 호출할 때 `x`, `y`가 `int` 타입이라면, **컴파일러가 조용히 `T`에 `int`를 대입하여 `int` 전용 함수를 자동으로 찍어냅니다.**
* 이 자동 생성 과정을 **구체화 (Instantiation)**라고 부릅니다.

---

## 3. 용어 개념 비교

| 개념 | 설명 | 비유 |
| :--- | :--- | :--- |
| **오버로딩 (Overloading)** | 사람이 직접 타입별로 같은 이름의 함수를 여러 개 작성함 | 수제작으로 모양만 조금씩 다른 장난감 만들기 |
| **템플릿 (Template)** | 틀 1개만 작성하면, 컴파일러가 필요한 타입별 함수를 자동으로 찍어냄 | 공장의 찍어내는 금형 틀 |
| **오버라이딩 (Overriding)** | 상속 관계에서 부모 클래스의 메서드를 자식이 재정의함 | (템플릿과 무관한 객체지향 상속 개념) |

---

## 4. 실습 코드로 이해하는 '템플릿 특수화(Specialization)'

템플릿이라는 붕어빵 틀로 대부분의 재료는 잘 구워지지만, **특정 재료는 일반 틀로 구우면 고장 나는 경우**가 생깁니다.  
이때 **"특정 타입에 대해서만 예외적으로 전용 수제 코드를 사용하라"**고 지정하는 것이 **특수화(Specialization)**입니다.

### ① 완전 특수화 (Full Specialization)
> **참고 파일**: `template_full_specialization.cpp`

```cpp
// [1. 일반 템플릿 - 기본 틀]
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// [2. const char* 전용 완전 특수화 - 수제 예외 틀]
template <>
const char* maxValue<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}
```
* **이유**: `const char*`(C 스타일 문자열 포인터)에 일반 템플릿을 적용하면 문자열 내용이 아닌 **메모리 주소값 비교(`a > b`)**가 일어나 원하는 결과를 얻을 수 없습니다.
* **해결**: `const char*` 타입이 들어올 때만 `std::strcmp`를 사용하도록 특수화된 예외 처리 함수를 따로 정의합니다.

### ② 부분 특수화 (Partial Specialization)
> **참고 파일**: `template_partial_specialization.cpp`

템플릿 매개변수가 여러 개일 때, 일부 매개변수만 특정 타입으로 고정하거나 특정 패턴(예: 포인터 타입)에 반응하도록 지정하는 방식입니다.

```cpp
// [1. 기본 클래스 템플릿]
template <typename T, typename U>
class PairPrinter { ... };

// [2. 부분 특수화: 두 번째 타입이 int인 경우]
template <typename T>
class PairPrinter<T, int> { ... };

// [3. 부분 특수화: 두 타입 모두 포인터 타입인 경우]
template <typename T, typename U>
class PairPrinter<T*, U*> { ... };
```

---

## 5. 핵심 요약

1. **템플릿 왜 쓰는가?**: 동일한 알고리즘을 타입마다 반복해서 작성하는 **코드 중복을 제거**하기 위함.
2. **템플릿은 무엇인가?**: 실행 코드가 아니라 컴파일러가 코드를 자동 생성하도록 돕는 **청사진(틀)**.
3. **특수화는 왜 필요한가?**: 기본 틀로는 올바르게 동작하지 않는 **특수 타입(예: 문자열, 포인터)에 대한 예외 처리 코드를 제공**하기 위함.
