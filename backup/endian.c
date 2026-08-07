#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>

bool is little_endian();
uint32_t swap_endian(uint32_t);

int main(int argc, char const *argv[])





{
    uint32_t network_data=0x12345678;
    printf("=== Day 2: Endianness Conversion ===\r\n");
    printf("Received Data (Hex): 0x%08X\r\n",network_data);

    if(is_little_endian())
    {
        printf("[System Check] This system is Little Endian.\r\n");
        printf("-> Need to swap bytes to match Host Order.\r\n");
        uint32_t host_data= swap_endian(network_data);

        printf("Original(Network): %08x\r\n",network_data);
        printf("Converted(Host): %08x\r\n",host_data);

        uint8_t*ptr=(uint8_t*)&host_data;
        printf("Memory Dump:");

        for(int i=0;i<4;i++)
        {
            printf("[%02X]",ptr[i]);
        }
        printf("(Low Addr->High Addr)\n");


    }
    return 0;
}

bool is_little_endian()
{
    uint32_t num=0x01;
    uint8_t*first_byte=(uint8_t*)&num; 
    if(first_byte[0]==1)
        return true;

    return false;

}
uint32_t swap_endian(uint32_t val)

{
      return ((val & 0x000000FF) << 24) |
           ((val & 0x0000FF00) << 8)  |
           ((val & 0x00FF0000) >> 8)  |
           ((val & 0xFF000000) >> 24);

}
