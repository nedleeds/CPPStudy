#include <iostream>
#include <limits>

void nullCharacter()
{
    /*
    '\0' 은 null charter 로, 문자열의 끝에 있다.
    문자열의 종료를 뜻하므로, '\0' 이 출력 버퍼에서 인식되면
    문자열이 끝난 것으로 파악하고 출력을 종료한다.
    */
    using namespace std;

    char myString[] = "hello world this is lee.";

    cout << "\noriginal : " << myString << endl;
    
    // null character
    myString[4] = '\0'; 

    cout << "changed : " << myString << endl << endl;
}

void copyStr()
{
    char src[] = "source char[].";
    char dst[50] = "";

    std::cout << "src: " << src << std::endl;
    std::cout << "dst: " << dst << std::endl << std::endl;

    // copy string
    std::cout << "strcpy(dst, stc);" << std::endl;
    std::strcpy(dst, src);
    std::cout << "dst: " << dst << std::endl << std::endl;

    // strcpy 주의사항 !! 
    // 이건 원래 에러가 떠야돼...
    // -> The behavior is undefined if the dest array 
    //    is not large enough. The behavior is undefined 
    //    if the strings overlap.
    // -> 대상 배열이 충분히 크지 않으면 동작이 정의되지 않습니다. 
    //    문자열이 겹치면 동작이 정의되지 않습니다.
    // test_dst 크기가 char * 3 인데, src 크기는 더 크잖아
    
    // 근데 내가 봤을 때, 자체적으로 이걸 바꿔주는 것 같아
    // 어쨌든 위험하다 .. 심각한 segmentation 오류를 발생시킬 가능성이 커
    char test_src[100] = "123123123123";
    char test_dst[3] = "12";
    std::strcpy(test_dst, test_src);
    std::cout << "test_dst: " << test_dst << std::endl;
}

void strCompare()
{
    // 원래 함수 자체는
    // 문자열이 같으면 문자열 시작 위치의 인덱스를 출력한다
    // 다르면 -1 을 출력하고
    // 근데 vscode 는 -1 대신 쓰레기 값이 출력되네
    // 이게 m1 이라서 그런건가 싶기도하고 ?

    char src[] = "hello I'm lee";
    char dst1[] = "hello I'm kim";
    char dst2[] = "hello I'm lee";
    char dst3[] = "Hi, I'm lee";
    char dst4[] = "      hello, I'm lee";
    
    std::cout << strcmp(src, dst1) << std::endl;
    std::cout << strcmp(src, dst2) << std::endl;
    std::cout << strcmp(src, dst3) << std::endl;
    std::cout << strcmp(src, dst4) << std::endl;
}