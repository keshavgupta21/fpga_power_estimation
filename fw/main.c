#include "xparameters.h"
#include "sleep.h"
#include "stdio.h"
#include "xiomodule.h"


XIOModule uart;

void send_str(char* pstr) {
    usleep(1000);
    while (*pstr != '\0') {
        XIOModule_Send(&uart, (u8*)pstr++, 1);
        usleep(1000);
    }
}

void getch(char* pstr) {
    while (XIOModule_Recv(&uart, (u8*)pstr, 1) == 0) {}
}

void set_gpio(u32 value) {
    XIOModule_DiscreteWrite(&uart, 1, value);
}

int main() {
    XIOModule_Initialize(&uart, XPAR_CONTROLLER_IOMODULE_0_BASEADDR);

    u32 i = 0;
    while (1) {
        set_gpio(i++);
        usleep(1000000);
    }
}