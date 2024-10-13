#include <stdio.h>
#include <stdint.h>
#include "crc.h"

int main(){
    uint8_t DATA[13] = {0x84, 0x12, 0xF7, 0x64, 0x18, 0x02, 0x05, 0x00, 0xBB, 0x32, 0xE7, 0x64, 0x08};
    uint32_t D_LENGTH = 13;

    uint16_t DIVIDING_POLY = 0X1021;
    uint16_t CRC_INIT = 0xFFFF;

    uint32_t DIVIDING_POLY32 = 0xEDB88320;
    uint32_t CRC_INIT32 = 0xFFFFFFFF;

    printf("Data: {");
    for (uint32_t i = 0; i < D_LENGTH; i++)
    {
        printBinary(DATA[i], 7);
        printf(" ");
    }
    printf("}\n");    

    uint16_t crc1 = crc16(DATA, D_LENGTH, DIVIDING_POLY, CRC_INIT);
    printf("CRC16: 0x%x \n", crc1);
    uint32_t crc2 = crc32(DATA, D_LENGTH, DIVIDING_POLY32, CRC_INIT32);
    printf("CRC32: 0x%x \n", crc2);
    
    _Bool DATA_PARITY[13];
    parity(DATA, D_LENGTH, DATA_PARITY);

    printf("Data Parity : {");
    
    for (uint32_t i = 0; i < D_LENGTH; i++)
    {
        printf("%d ", DATA_PARITY[i]);
    }
    printf("}\n");
    
    return 0;
}