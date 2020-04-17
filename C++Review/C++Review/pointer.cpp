#include <iostream>

using namespace std;

struct _tagStudent
{
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
};
int main()
{
    /*
    포인터 : 가리키다.
    일반 변수는 일반적인 값을 저장하게 되지만 포인터 변수는 메모리 주소를 저장하게 된다.
    모든 변수타입은 포인터 타입을 선언할 수 있다.
    int변수의 주소는 int 포인터 변수에 저장을 해야한다.
    포인터는 메모리 주소를 담아놓는 변수이기 때문에
    x86으로 개발할때는 무조건 4byte가 나온다.
    x64일때는 8byte가 나온다.

    포인터는 자기 스스로 아무런 일도 할 수 없다.
    반드시 다른 변수의 메모리 주소를 가지고 있어야 일을 할 수 있는데
    가지고 있는 그 메모리 주소에 접근해서 값을 제어 할 수 있다.

    형태 : 변수타입 * 변수명: 의 형태로 선언한다.
    */
    int iNumber = 100;

    // 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
    // 변수 앞에 &을 붙여주면 해당 변수의 메모리 주소가 된다.
    // pNum은 iNumber변수의 메모리 주소를 값으로 갖게 됐다.
    // 그러므로 pNum을 이용해서 iNumber의 값을 제어할 수 있게 된 것이다.
    int* pNum = &iNumber;

    // 자료형 포인터는 x86의 경우 size가 4bite로 지정된다.
    // ex) char*, double* 또한 4bite
    cout << sizeof(int*) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(double*) << endl;

    // pNum을 이용해서 iNumber의 값을 제어해보자.
    // 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
    // 역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
    cout << *pNum << endl;
    *pNum = 1234;

    cout << "iNUmber Value : " << iNumber << endl;
    cout << "iNumber Address : " << &iNumber << endl;
    cout << "pNum Value" << pNum << endl;
    cout << "pNum Address : " << &pNum << endl;

    /*
    포인터와 배열의 관계 : 배열명은 포인터다. 배열명 자체가 해당 배열의 메모리에서의 시작점 주소를 의미한다.
    */
    int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

    cout << "Array Address : " << iArray << endl;
    cout << "Array Address : " << &iArray[0] << endl;

    int* pArray = iArray;
    cout << pArray[2] << endl;
    cout << iArray[2] << endl;

    /*
    포인터 연산 : +, - 연산을 제공한다.
    ++,-- 도 가능한데 1을 증가하게 되면 단순히 메모리 주소 값이 1 증가하는 것이 아니다.
    int 포인터의 경우 int 타입의 메모리 주소를 갖게 되는데 메모리 주소에 1을 더해주면
    1증가가 아닌 가리키는 해당 포인터 타입의 변수타입 크기만큼 증가하게 된다.
    int 포인터이므로 int의 크기인 4만큼 값이 증가하게 되는것이다.
    */
    cout << pArray << endl;
    cout << pArray + 2 << endl;
    cout << *pArray << endl;
    cout << *(pArray + 2) << endl;
    cout << *pArray + 100 << endl; // 이때는 101이 출력된다. 왜냐하면, 연산자 우선순위 때문이다. * 먼저 + 나중
    cout << endl;



    /* 문자열 포인터 */

    // char pText[] = "테스트 문자열";
    // 의 경우 {"테", "스", "트", " ", "문", "자", 열","\0"} 으로 저장
    // 하지만 아래같은 경우는, [테스트 문자열\0]
    const char* pText = "테스트 문자열";

    cout << pText << endl;              // 테스트 문자열 출력, *****정수배열이였을경우 포인트 변수를 입력하면 주소가 출력*****
    cout << (int*)pText << endl;        // 00FB9B94 -> 00BD9B94 : pText[0]의 주소와같다.
    cout << endl;

    pText = "abcd";
    cout << pText << endl;
    cout << (int*)pText << endl;        // 00FB9C40 -> 00BD9C40 : 문자열이 바뀌면 다른 주소에 저장된다.
    cout << endl;

    pText = "abcdefg";
    cout << pText << endl;
    cout << (int*)pText << endl;        // 00BD9C48 : 문자열이 바뀌면 다른 주소에 저장된다.
    cout << endl;

    char str[8] = "abcdefg";            // 문자열 배열로 abcdefg가 저장되었기에 포인터 문자열 배열 abcdefg와 다른 주소가 저장된다.
    cout << str << endl;                // abcdefg 출력
    for (int i = 0; i <= 8; ++i)         // str[8] = "abcdefg" 의 경우 {"a", "b", "c", "d", "e", "f", "g"}로 저장
    {
        cout << str[i] << endl;
    }
    cout << (int*)str << endl;          // str[0]의 주소와 동일
    cout << (int*)&str[0] << endl;
    cout << endl;



    /* 구조체 포인터 */

    _tagStudent tStudent = {};

    tStudent.iKor = 100;

    _tagStudent* pStudent = &tStudent;

    // 연산자 우선순위 때문에 .을 먼저 인식하게 된다.
    // 메모리주소.은 잘못된 문법이다.
    // 그러므로, *pStudent를 괄호로 감싸준 후에 .을 이용해서
    // 가리키는 대상의 맴버변수에 접근해야한다.
    (*pStudent).iKor = 50; // 100이 50으로 바뀜
    cout << tStudent.iKor << endl;
    cout << endl;

    // 메모리주소 -> 을 이용해서 가리키는 대상의 멤버에 접근할 수 있다.
    pStudent->iKor = 80; // 50이 80으로 바뀜
    cout << tStudent.iKor << endl;
    cout << endl;



    /* void 포인터 */

    /*
    void : 타입이 없다.
    void의 포인터 타입을 활용할 수 있다.
    void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장가능하다. 단,
    역참조가 불가능하고 메모리 주소만 저장 가능하다. (메모리 주소를 저장하기 위한 버퍼로 사용)
    */
    void* pVoid = &iNumber;
    cout << "iNumber Address : " << pVoid << endl;

    // 굳이 void포인터에 변수를 넣고 싶으면 다음과 같이 해야한다.
    int* pConvert = (int*)pVoid; // void포인트를 int point형변환 시킨다. // iNumber의 주소를 pCovert 포인터가 받는다.
    *pConvert = 10101010;        // pConvert를 역참조해서 정수를 대입한다.

    *((int*)pVoid) = 99;         // 또는, 왼쪽과 같은 방법으로 (따로 별개의 포인터변수선언없이) int point로 형변환시켜서 바로 역참조한다.

    cout << iNumber << endl;

    pVoid = &tStudent;
    cout << "iNumber Address : " << pVoid << endl;
    cout << endl;


    /* 이중 포인터 */

    /*
    이중 포인터 : *을 2개 붙인다.
    일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수라면,
    이중 포인터는 포인터의 포인터이다.
    즉, 이중 포인터는 포인터 변수의 메모리 주소를 저장하는 포인터이다.
    */
    int iNumber1 = 1111;
    int iNubmer = 2222;

    // 위에서 int* pNum = &iNumber; 이므로, pNum은 포인터변수이다.
    pNum = &iNumber;
    // 포인터변수 pNUm의 메모리 주소를 이중 포인터 변수 ppNum이 받는다.
    int** ppNum = &pNum;
    // pNum의 역참조값(2222)를 3333으로 바꾼다.
    *pNum = 3333;

    cout << "iNumber : " << iNumber << endl;        // iNumber의 바뀐값 3333이 인쇄된다.
    cout << "iNumber Addr : " << &iNumber << endl;  // iNumber의 주소를 인쇄한다.
    cout << endl;
    cout << "*pNum : " << *pNum << endl;            // pNum을 역참조 값인  iNumber의 값이 인쇄된다.
    cout << "pNum Value : " << pNum << endl;        // pNum값 즉 iNumber의 주소가 인쇄된다.
    cout << "pNum Addr : " << &pNum << endl;        // pNum의 주소가 인쇄된다.
    cout << endl;
    cout << "*ppNum : " << *ppNum << endl;          // ppNum의 역참조 값인 pNum안에 들어있는 iNumber의 주소값이 인쇄된다.
    cout << "**ppNum : " << **ppNum << endl;        // 위에서 이어 생각하여, iNumber값이 출력된다.
    cout << "ppNum : " << ppNum << endl;            // ppNum은 pNum의 주소를 가지고 있으므로, pNum주소가 인쇄된다.
    cout << "ppNum Addr : " << &ppNum << endl;      // ppNum의 주소가 인쇄된다.

    return 0;
}
