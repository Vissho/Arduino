#include <iostream>
#include <bitset>
#include <unistd.h>

int main()
{
    int flag = 0;
    while(1){
        flag++;
        flag %= 3;
        std::cout << flag << std::endl;
        sleep(1);
    }
    // std::cout << std::bitset<8>{(1 << 5)} << std::endl;
    return 0;
}