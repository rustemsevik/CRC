#include <stdint.h>
#include "crc.h"
#include "crc_util.h"
#include "crc_err.h"

uint16_t crc16(uint8_t *data, uint32_t d_length, uint16_t d_poly, uint16_t crc_init){
    if (!data)
    {
        return NULLITY_ERROR;
    }
    
    if (d_length < 1)
    {
        return LENGTH_ERROR;
    }


    uint16_t crc = crc_init;
    uint8_t *bytes = (uint8_t *)data;

    for (uint32_t i = 0; i < d_length; i++) // Loop through the data points in the array
    {
        uint8_t data_point =  bytes[i];
    
        crc = crc ^ (data_point << 8); // Since the input data will be in the uint8_t format the data is shifted 8 bits.

        for (int j = 0; j < 8; j++)  // Since the input data will be in the uint8_t format the loop is executed 8 times.
        {
            _Bool overflowed = crc >= 0x8000; 

            crc = (crc << 1) & 0xFFFF; // Shift one bit left and filter to stay in 16 bits.

            if (overflowed)
            {
                crc = crc ^ d_poly;
            }
        }
    }
    
    return crc;
}

uint32_t crc32(uint8_t *data, uint32_t d_length, uint32_t d_poly, uint32_t crc_init){
    if (!data)
    {
        return NULLITY_ERROR;
    }
    
    if (d_length < 1)
    {
        return LENGTH_ERROR;
    }

    uint32_t crc = crc_init;
    uint8_t *bytes = (uint8_t *)data;

    for (uint32_t i = 0; i < d_length; i++)
    {
        uint8_t data_point =  bytes[i];
    
        crc ^= data_point;

        for (int j = 0; j < 8; j++)  // Since the input data will be in the uint8_t format the loop is executed 8 times.
        {
            if (crc & 1)
            {
                crc = (crc >> 1) ^ d_poly;
            }
            else
            {
                crc >>= 1;
            }

        }
    }
    crc = crc ^ 0xFFFFFFFF;
    
    return crc;
}

_Bool parity(const uint8_t *src_data, const uint32_t src_length, _Bool *parity_data){
    uint8_t *bytes = (uint8_t *)src_data;
    _Bool bit = 0;

    for (uint32_t i = 0; i < src_length; i++)
    {
        for (uint8_t j = 0; j < 8; j++)
        {
            bit ^= ((bytes[i] >> j) & 1);
        }
        
        parity_data[i] = bit;
    }
    
    return 0;
}