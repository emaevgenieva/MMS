#include <stdio.h>
#include <stdint.h>

unsigned countSetBits(uint64_t num){
    unsigned count = 0;
    while(num){
        count += num & 1;
        num >>= 1;
    }
    return count;
}

