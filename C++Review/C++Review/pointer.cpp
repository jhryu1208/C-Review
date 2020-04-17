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
    ������ : ����Ű��.
    �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������ ������ ������ �޸� �ּҸ� �����ϰ� �ȴ�.
    ��� ����Ÿ���� ������ Ÿ���� ������ �� �ִ�.
    int������ �ּҴ� int ������ ������ ������ �ؾ��Ѵ�.
    �����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������
    x86���� �����Ҷ��� ������ 4byte�� ���´�.
    x64�϶��� 8byte�� ���´�.

    �����ʹ� �ڱ� ������ �ƹ��� �ϵ� �� �� ����.
    �ݵ�� �ٸ� ������ �޸� �ּҸ� ������ �־�� ���� �� �� �ִµ�
    ������ �ִ� �� �޸� �ּҿ� �����ؼ� ���� ���� �� �� �ִ�.

    ���� : ����Ÿ�� * ������: �� ���·� �����Ѵ�.
    */
    int iNumber = 100;

    // ���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�.
    // ���� �տ� &�� �ٿ��ָ� �ش� ������ �޸� �ּҰ� �ȴ�.
    // pNum�� iNumber������ �޸� �ּҸ� ������ ���� �ƴ�.
    // �׷��Ƿ� pNum�� �̿��ؼ� iNumber�� ���� ������ �� �ְ� �� ���̴�.
    int* pNum = &iNumber;

    // �ڷ��� �����ʹ� x86�� ��� size�� 4bite�� �����ȴ�.
    // ex) char*, double* ���� 4bite
    cout << sizeof(int*) << endl;
    cout << sizeof(char*) << endl;
    cout << sizeof(double*) << endl;

    // pNum�� �̿��ؼ� iNumber�� ���� �����غ���.
    // �������� �̿��ؼ� ���� �����ų� ������ �� �ִ�.
    // �������� ������ ���� �տ� *�� ���̰� �Ǹ� �������� �ȴ�.
    cout << *pNum << endl;
    *pNum = 1234;

    cout << "iNUmber Value : " << iNumber << endl;
    cout << "iNumber Address : " << &iNumber << endl;
    cout << "pNum Value" << pNum << endl;
    cout << "pNum Address : " << &pNum << endl;

    /*
    �����Ϳ� �迭�� ���� : �迭���� �����ʹ�. �迭�� ��ü�� �ش� �迭�� �޸𸮿����� ������ �ּҸ� �ǹ��Ѵ�.
    */
    int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

    cout << "Array Address : " << iArray << endl;
    cout << "Array Address : " << &iArray[0] << endl;

    int* pArray = iArray;
    cout << pArray[2] << endl;
    cout << iArray[2] << endl;

    /*
    ������ ���� : +, - ������ �����Ѵ�.
    ++,-- �� �����ѵ� 1�� �����ϰ� �Ǹ� �ܼ��� �޸� �ּ� ���� 1 �����ϴ� ���� �ƴϴ�.
    int �������� ��� int Ÿ���� �޸� �ּҸ� ���� �Ǵµ� �޸� �ּҿ� 1�� �����ָ�
    1������ �ƴ� ����Ű�� �ش� ������ Ÿ���� ����Ÿ�� ũ�⸸ŭ �����ϰ� �ȴ�.
    int �������̹Ƿ� int�� ũ���� 4��ŭ ���� �����ϰ� �Ǵ°��̴�.
    */
    cout << pArray << endl;
    cout << pArray + 2 << endl;
    cout << *pArray << endl;
    cout << *(pArray + 2) << endl;
    cout << *pArray + 100 << endl; // �̶��� 101�� ��µȴ�. �ֳ��ϸ�, ������ �켱���� �����̴�. * ���� + ����
    cout << endl;



    /* ���ڿ� ������ */

    // char pText[] = "�׽�Ʈ ���ڿ�";
    // �� ��� {"��", "��", "Ʈ", " ", "��", "��", ��","\0"} ���� ����
    // ������ �Ʒ����� ����, [�׽�Ʈ ���ڿ�\0]
    const char* pText = "�׽�Ʈ ���ڿ�";

    cout << pText << endl;              // �׽�Ʈ ���ڿ� ���, *****�����迭�̿������ ����Ʈ ������ �Է��ϸ� �ּҰ� ���*****
    cout << (int*)pText << endl;        // 00FB9B94 -> 00BD9B94 : pText[0]�� �ּҿͰ���.
    cout << endl;

    pText = "abcd";
    cout << pText << endl;
    cout << (int*)pText << endl;        // 00FB9C40 -> 00BD9C40 : ���ڿ��� �ٲ�� �ٸ� �ּҿ� ����ȴ�.
    cout << endl;

    pText = "abcdefg";
    cout << pText << endl;
    cout << (int*)pText << endl;        // 00BD9C48 : ���ڿ��� �ٲ�� �ٸ� �ּҿ� ����ȴ�.
    cout << endl;

    char str[8] = "abcdefg";            // ���ڿ� �迭�� abcdefg�� ����Ǿ��⿡ ������ ���ڿ� �迭 abcdefg�� �ٸ� �ּҰ� ����ȴ�.
    cout << str << endl;                // abcdefg ���
    for (int i = 0; i <= 8; ++i)         // str[8] = "abcdefg" �� ��� {"a", "b", "c", "d", "e", "f", "g"}�� ����
    {
        cout << str[i] << endl;
    }
    cout << (int*)str << endl;          // str[0]�� �ּҿ� ����
    cout << (int*)&str[0] << endl;
    cout << endl;



    /* ����ü ������ */

    _tagStudent tStudent = {};

    tStudent.iKor = 100;

    _tagStudent* pStudent = &tStudent;

    // ������ �켱���� ������ .�� ���� �ν��ϰ� �ȴ�.
    // �޸��ּ�.�� �߸��� �����̴�.
    // �׷��Ƿ�, *pStudent�� ��ȣ�� ������ �Ŀ� .�� �̿��ؼ�
    // ����Ű�� ����� �ɹ������� �����ؾ��Ѵ�.
    (*pStudent).iKor = 50; // 100�� 50���� �ٲ�
    cout << tStudent.iKor << endl;
    cout << endl;

    // �޸��ּ� -> �� �̿��ؼ� ����Ű�� ����� ����� ������ �� �ִ�.
    pStudent->iKor = 80; // 50�� 80���� �ٲ�
    cout << tStudent.iKor << endl;
    cout << endl;



    /* void ������ */

    /*
    void : Ÿ���� ����.
    void�� ������ Ÿ���� Ȱ���� �� �ִ�.
    void* ������ �����ϰ� �Ǹ� �� ������ � Ÿ���� �޸� �ּҵ� ��� ���尡���ϴ�. ��,
    �������� �Ұ����ϰ� �޸� �ּҸ� ���� �����ϴ�. (�޸� �ּҸ� �����ϱ� ���� ���۷� ���)
    */
    void* pVoid = &iNumber;
    cout << "iNumber Address : " << pVoid << endl;

    // ���� void�����Ϳ� ������ �ְ� ������ ������ ���� �ؾ��Ѵ�.
    int* pConvert = (int*)pVoid; // void����Ʈ�� int point����ȯ ��Ų��. // iNumber�� �ּҸ� pCovert �����Ͱ� �޴´�.
    *pConvert = 10101010;        // pConvert�� �������ؼ� ������ �����Ѵ�.

    *((int*)pVoid) = 99;         // �Ǵ�, ���ʰ� ���� ������� (���� ������ �����ͺ����������) int point�� ����ȯ���Ѽ� �ٷ� �������Ѵ�.

    cout << iNumber << endl;

    pVoid = &tStudent;
    cout << "iNumber Address : " << pVoid << endl;
    cout << endl;


    /* ���� ������ */

    /*
    ���� ������ : *�� 2�� ���δ�.
    �Ϲ� ������ ������ �Ϲ� ������ �޸� �ּҸ� �����ϴ� �������,
    ���� �����ʹ� �������� �������̴�.
    ��, ���� �����ʹ� ������ ������ �޸� �ּҸ� �����ϴ� �������̴�.
    */
    int iNumber1 = 1111;
    int iNubmer = 2222;

    // ������ int* pNum = &iNumber; �̹Ƿ�, pNum�� �����ͺ����̴�.
    pNum = &iNumber;
    // �����ͺ��� pNUm�� �޸� �ּҸ� ���� ������ ���� ppNum�� �޴´�.
    int** ppNum = &pNum;
    // pNum�� ��������(2222)�� 3333���� �ٲ۴�.
    *pNum = 3333;

    cout << "iNumber : " << iNumber << endl;        // iNumber�� �ٲﰪ 3333�� �μ�ȴ�.
    cout << "iNumber Addr : " << &iNumber << endl;  // iNumber�� �ּҸ� �μ��Ѵ�.
    cout << endl;
    cout << "*pNum : " << *pNum << endl;            // pNum�� ������ ����  iNumber�� ���� �μ�ȴ�.
    cout << "pNum Value : " << pNum << endl;        // pNum�� �� iNumber�� �ּҰ� �μ�ȴ�.
    cout << "pNum Addr : " << &pNum << endl;        // pNum�� �ּҰ� �μ�ȴ�.
    cout << endl;
    cout << "*ppNum : " << *ppNum << endl;          // ppNum�� ������ ���� pNum�ȿ� ����ִ� iNumber�� �ּҰ��� �μ�ȴ�.
    cout << "**ppNum : " << **ppNum << endl;        // ������ �̾� �����Ͽ�, iNumber���� ��µȴ�.
    cout << "ppNum : " << ppNum << endl;            // ppNum�� pNum�� �ּҸ� ������ �����Ƿ�, pNum�ּҰ� �μ�ȴ�.
    cout << "ppNum Addr : " << &ppNum << endl;      // ppNum�� �ּҰ� �μ�ȴ�.

    return 0;
}
