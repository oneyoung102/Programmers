# 결과출력파일   

> 본 파일은 **프로그래머스** 코딩테스트의 테스트케이스 실행 결과를 출력하기 위해 만들어졌습니다.

- 결과출력파일
  - MainFunctionFile.cpp
  - PrintFunctionReturn.cpp

    

## MainFunctionFile.cpp

> 사용자가 변경해야 할 부분이 포함된 파일입니다.

   
### 파일 사용 방법

- #### 준비과정

  1. **프로그래머스** 코딩테스트의 함수 복사하여 붙여넣기
  ```c++
  //현재는 예시입니다. solution 함수를 수정하세요
  int solution(int n, vector<int> v)
  {
      return n+v[0];
  }
  ```   
     
  2. 필요한 라이브러리 추가하기
  ```c++
  #include <vector>
  #include <string>
  ```   
     
  3. 매게변수의 자료형 작성하기   
  `int solution(int n, vector<int> v)`에서 `int`와 `vector<int>`를 복사하여 `,`으로 연결하여   
  `#define TYPE_OF_ARGUMENTS` 옆에 한 칸 이상의 공백을 두고 작성합니다.
  
  ```c++
  #define TYPE_OF_ARGUMENTS        int,vector<int>
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ```


  
- #### 테스트케이스 인수 전달하기   

  두 괄호 쌍 `((`, `))` 안에, 앞서 작성한 매게변수 타입과 맞는 인수들을 `,`으로 연결하여 입력합니다.   
  ```c++
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  #define ARGUMENTS                ((  5,[1,2,3,4] )) // <- 괄호 두 쌍 안에 인수 입력하기
  ```
  > 두 괄호 옆 공백은 가독성을 위한 것입니다.
  
  > **프로그래머스**에서는 벡터를 표시하기 위해 `[ ... ]`를 사용합니다. 그러나 c++에서는 그렇지 않습니다.
  > **PrintFunctionReturn.cpp**는 이를 고려하여 인수 입력 시에, `[ ... ]`, `{ ... }` 모두를 사용할 수 있게 만들어졌습니다.   
  
- #### 실행하기  

  **PrintFunctionReturn.cpp**를 같은 프로젝트에 두고 **MainFunctionFile.cpp**를 실행하여 결과를 확인합니다.
  ```c++
  answer : 6
  ```
  > 현재 출력은 예시 solution일 떄의 결과값입니다.
  > 구체적인 출력을 보시려면 [여기](https://github.com/oneyoung102/Programmers/blob/main/결과출력파일/README.md#출력-예시)를 클릭하세요.


- #### 함수명 변경하기 **(불필요)**

  **프로그래머스**에서는 함수명은 항상 `solution`입니다. 그러나 다른 용도로 사용할 경우,   
  
  `FunctionReturnPrint<TYPE_OF_ARGUMENTS>(solution,TO_STRING(ARGUMENTS))`에서 `solution`을 **값을 출력하고자 하는 함수명**으로 변경하세요.
  ```c++
  #include "PrintFunctionReturn.cpp"
  int main()
  {
      FunctionReturnPrint<TYPE_OF_ARGUMENTS>(solution,TO_STRING(ARGUMENTS));
      return 0;
  }
  ```

## PrintFunctionReturn.cpp   

> 사용자가 절대로 변경하면 안 되는 파일입니다.

본 파일에서는 `bool`, `int`, `long long`, `double`, `char`, `string`과 이들을 원소로 갖는 `vector<>`, `vector<vector<>>`의 출력을 지원합니다.

매게변수 타입의 경우도 마찬가지입니다.

> `float`, `unsigned int`, `array<>`, `vector<vector<vector<>>>` 등 **프로그래머스**에서 잘 사용되지 않는 자료형은 지원하지 않습니다.

### 출력 예시

- `bool` 
  ```c++
  answer : true
  ```
- `int`, `long long`
  ```c++
  answer : 102
  ```
- `double` 
  ```c++
  answer : 102.102102
  ```
- `char` 
  ```c++
  answer : 'w'
  ```
- `string`
  ```c++
  answer : "Hello!"
  ```
- `vector<int>`
  ```c++
  answer : 1,2,5,2
  ```
- `vector<vector<string>>`
  ```c++
  answer : "Hello","~",
           "World","!"
  ```





