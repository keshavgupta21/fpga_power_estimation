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

int main() {
    XIOModule_Initialize(&uart, XPAR_CONTROLLER_IOMODULE_0_BASEADDR);
    char str[256];

    while (1) {
        send_str("Press a to print hello world, b to print goodbye\n");
        getch(str);
        if (str[0] == 'a') {
            send_str("Hello World!\n");
        } else if (str[0] == 'b') {
            send_str("Goodbye!\n");
        } else {
            send_str("Unknown command\n");
        }
    }
}