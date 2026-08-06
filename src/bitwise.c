#include <stdio.h>
#define BIT_SET(var.pos) ((var) |=(1UL<<(pos)))
int main(int argc, char const *argv[])
{
    unit32_t data=0x12345678;
    BIT_SET(data,0);

    ((data)) |=(1UL<<(0));
    return 0;
}
