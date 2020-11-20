#include <boost/crc.hpp>      // For CRC function
#include <iostream>   // for std::cout
#include <ostream>    // for std::endl


// Main function
int main()
{
    unsigned char crc16_Input[] = {0xBE, 0xEF, 0x42, 0x0C, 0x0C, 0x0A}; // CRC Input data
    boost::crc_ccitt_type result;
    result.process_bytes(crc16_Input, 6); // process the specified number of bytes in the input
    std::cout << "CRC16 Result= " << std::hex << result.checksum() << std::endl; // output result in hex form
}
