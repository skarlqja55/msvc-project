#include <stdio.h>
#include <stdint.h>

#define BIT_SET(var, pos)     ((var) |=  (1UL << (pos)))
#define BIT_CLEAR(var, pos)   ((var) &= ~(1UL << (pos)))
#define BIT_TOGGLE(var, pos)  ((var) ^=  (1UL << (pos)))
#define BIT_CHECK(var, pos)   (((var) >> (pos)) & 1UL)

void print_binary(uint32_t data)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%u", (data >> i) & 1U);

        // 4비트마다 공백
        if (i % 4 == 0 && i != 0)
        {
            printf(" ");
        }
    }
}

int main(void)
{
    uint32_t data = 0x12345678;

    printf("=== Day 1: Bitwise Macro Test ===\n");

    printf("[Init]   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");

    printf("[SET]    Target: Bit 0\n");
    BIT_SET(data, 0);
    printf("Result   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");

    printf("[CLEAR]  Target: Bit 4\n");
    BIT_CLEAR(data, 4);
    printf("Result   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");

    printf("[TOGGLE] Target: Bit 3\n");
    BIT_TOGGLE(data, 3);
    printf("Result   Hex: 0x%08X | Bin: ", data);
    print_binary(data);
    printf("\n\n");

    printf("[CHECK]  Bit 3 is currently: %u\n",
           (unsigned int)BIT_CHECK(data, 3));

    return 0;
}