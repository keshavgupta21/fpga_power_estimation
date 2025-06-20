#include "xparameters.h"
#include "sleep.h"
#include "stdio.h"
#include "xiomodule.h"

XIOModule uart;

void print_str(char* pstr) {
    usleep(1000);
    while (*pstr != '\0') {
        XIOModule_Send(&uart, (u8*)pstr++, 1);
        usleep(1000);
    }
}

u8 get_ch() {
    u8 c;
    while (XIOModule_Recv(&uart, &c, 1) == 0) {}
    return c;
}

void set_pwr_en(u32 value) {
    XIOModule_DiscreteWrite(&uart, 1, value);
}

void set_opt_en(u32 value) {
    XIOModule_DiscreteWrite(&uart, 2, value);
}

int main() {
    XIOModule_Initialize(&uart, XPAR_CONTROLLER_IOMODULE_0_BASEADDR);
    while (1) {
        print_str("Press key:\n\r");
        print_str("    p: Power Enable\n\r");
        print_str("    o: Opt Enable\n\r");
        print_str("    d: Disable\n\r\n\r\n\r");
        u8 c = get_ch();
        switch (c) {
            case 'p':
                print_str("Power Enabled\n\r");
                set_pwr_en(0xffffffff);
                break;
            case 'o':
                print_str("Opt Enabled\n\r");
                set_opt_en(0xffffffff);
                break;
            case 'd':
                print_str("Disabled\n\r");
                set_pwr_en(0);
                set_opt_en(0);
                break;
            default:
                print_str("Unknown command\n\r");
        }
    }
    print_str("\n\r\n\r");
}