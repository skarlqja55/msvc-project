
#include "app.h"
#include "cli.h"
#include "uart_win.h"

void appInit(void)
{
   uartInit();
   cliInit();
}
void appMain(void)
{
     while(1)
    {
        cliMain();
    }
}
