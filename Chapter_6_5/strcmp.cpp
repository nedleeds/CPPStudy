#include <iostream>
#include <cstring>

int main()
{
    char src[] = "Hello, world!";
    char dst[50];


    // copy - cStyle
    strcpy(dst, src);
    std::cout << dst << std::endl;
    
    // string compare 
    // - 똑같은 string 의 첫번째 index 반환
    // - 다르면 원래는 -1 반환, vscode 는 다른 값이 나오네 ..?
    std::cout << strcmp(dst, src) <<std::endl;

    // concatenate - from source to destination
    strcat(dst, src);
    std::cout << dst << std::endl;

    // - 다르면 원래는 -1 반환 
    std::cout << strcmp(dst, src) <<std::endl;

}
