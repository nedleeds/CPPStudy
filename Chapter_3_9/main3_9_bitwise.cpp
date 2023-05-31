#include <iostream>
#include <bitset>

template <int digit_size>
void printBit(const int & a);

int main()
{
    // option 설정
    const int opt0 = 1 << 0;
    const int opt1 = 1 << 1;
    const int opt2 = 1 << 2;
    const int opt3 = 1 << 3;
    const int opt4 = 1 << 4;
    const int opt5 = 1 << 5;
    const int opt6 = 1 << 6;
    const int opt7 = 1 << 7;
    printBit<8>(opt6);

    // items_flag 설정 
    // 8개의 item - 8 bit (1 byte)로 표현
    unsigned char items_flag = 0;
    printBit<8>(items_flag);

    // opt0 획득 시
    items_flag |= opt0;
    std::cout << "opt0 obtained : ";
    printBit<8>(items_flag);

    // opt2가 있는지 확인
    if (items_flag & opt2){ std::cout << "opt2 obtained" << std::endl; }
    else 
    { 
        items_flag |= opt2;
        std::cout << "no opt2. add opt2." << std::endl; 
        printBit<8>(items_flag);
    }

    // opt4, opt5 획득
    items_flag |= ( opt4 | opt5 );
    std::cout << "opt4, opt5 obtained" << std::endl;
    printBit<8>(items_flag);

    // opt4, opt5 obtained again, then remove it
    items_flag ^= ( opt4 | opt5 );
    printBit<8>(items_flag);

    // opt2 있고, opt1 가 없을 때, opt1 추가
    if ((items_flag & opt2) && !(items_flag & opt1))
    {
        std::cout << "opt2 obainted but no opt1 so got opt1." << std::endl;
        items_flag |= opt1;
        printBit<8>(items_flag);
    }

    /*
        특히, Graphics 같은 경우,
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        이런 식으로,
        지우는 대상의 flag 들을 bitwise 연산을 통해서 동작시킨다
    */

    // 그래픽스 컬러코드 예제 - 비트 마스크
    const unsigned int mask_r = 0xFF0000;   // 0x00FF0000 에서 앞의 00 생략.
    const unsigned int mask_g = 0x00FF00;  // 0x0000FF00 에서 앞의 00 생략.
    const unsigned int mask_b = 0x0000FF; // 0x000000FF 에서 앞의 00 생략.
    // 한칸에 16가지 값 (0~F:15)
    // 1bit -> 0 or 1
    // 16가지 -> 4 bits 
    // 한칸 -> 4 bits를 의미
    // 두칸이 컬러마스크 -> 8 bits -> 1byte 
    // 3칸 필요(RGB) -> 3 bytes 
    // 앞의 한칸은 공백 -> 총 4 bytes (32 bits) -> unsigned int 로 표현 가능
    printBit<32>(mask_r);
    printBit<32>(mask_g);
    printBit<32>(mask_b);

    unsigned int pixel_color = 0xDAA520;
    const unsigned int extract_r = (pixel_color & mask_r);
    const unsigned int extract_g = (pixel_color & mask_g);
    const unsigned int extract_b = (pixel_color & mask_b);
    
    printBit<32>(pixel_color);
    printBit<32>(extract_r);
    printBit<32>(extract_g);
    printBit<32>(extract_b);

    return 0;
}

template <int digit_size>
void printBit(const int & a)
{
    std::cout << std::bitset<digit_size>(a) << std::endl << std::endl;
}