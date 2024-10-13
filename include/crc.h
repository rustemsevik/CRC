/**
 * @file crc.h
 * @brief 16 and 32 bit crc 
 * @author M. Rustem Sevik
 * @date
*/

#ifndef CRC_H_
#define CRC_H_

#include <stdint.h>
#include "crc_util.h"

/**
 * @brief Calculates the 16-bit CRC of the given data using the specified polynomial and initial value.
 * @param [in] data Pointer to the data array
 * @param [in] d_length Length of the data array
 * @param [in] d_poly Polynomial used for CRC calculation
 * @param [in] crc_init Initial value of the CRC
 * @return Calculated 16-bit CRC value 
*/
uint16_t crc16(uint8_t *data, uint32_t d_length, uint16_t d_poly, uint16_t crc_init);


/**
 * @brief Calculates the 32-bit CRC of the given data using the specified polynomial and initial value.
 * @param [in] data Pointer to the data array
 * @param [in] d_length Length of the data array
 * @param [in] d_poly Polynomial used for CRC calculation
 * @param [in] crc_init Initial value of the CRC
 * @return Calculated 32-bit CRC value
*/
uint32_t crc32(uint8_t *data, uint32_t d_length, uint32_t d_poly, uint32_t crc_init);

/**
 * @brief Calculates the parity of the input data.
 * @param [in] src_data Pointer to the source data array
 * @param [in] src_length Length of the source data array
 * @param [inout] parity_data Pointer to the parity data array
 * @remark parity data is 1 # of high bits is odd else parity data is 0
 * @return 0 if successful, error code otherwise
*/
_Bool parity(const uint8_t *src_data, const uint32_t src_length, _Bool *parity_data);

#endif //CRC_H_
