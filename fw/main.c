#include "xparameters.h"
#include "sleep.h"
#include "stdio.h"
#include "xiomodule.h"


XIOModule uart;

void send_str(char* pstr) {
    usleep(1000);
    while (*pstr != 0) {
        u32 bytes_sent = XIOModule_Send(&uart, (u8*)pstr, 1);
        pstr += bytes_sent;
        usleep(1000);
    }
}

void recv_str(char* pstr, u32 n) {
    XIOModule_Recv(&uart, (u8*)pstr, n);
}

int main() {
    XIOModule_Initialize(&uart, XPAR_CONTROLLER_IOMODULE_0_BASEADDR);
    char str[256];

    while (1) {
        usleep(1000000);
        recv_str(str, 10);
        send_str(str);
    }
}