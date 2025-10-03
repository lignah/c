// variadic arguments
#include <stdarg.h>

#include <windows.h>

void __printf(const char* format, ...) {  // variadic arguments
    char buffer[1024];  // buffer for output
    int pos = 0;        // position to write in buffer

    va_list args;           // variadic argument list
    va_start(args, format); // start reading arguments after format

    // iterate through format string character by character
    for (int i = 0; format[i]; i++) {
        // when %d is found
        if (format[i] == '%' && format[i + 1] == 'd') {
            int num = va_arg(args, int);  // extract next argument as int

            char temp[20];  // temporary array for number to string conversion
            int len = 0;
            int n = num;

            if (n == 0) {
                temp[len++] = '0';  // if 0, just put '0'
            }
            else {
                if (n < 0) {
                    buffer[pos++] = '-';  // add '-' for negative numbers
                    n = -n;
                }
                // 123 → stored as '3', '2', '1'
                while (n > 0) {
                    temp[len++] = (n % 10) + '0';  // extract ones digit
                    n /= 10;
                }
                // reverse and copy to buffer ('1', '2', '3')
                for (int j = len - 1; j >= 0; j--) {
                    buffer[pos++] = temp[j];
                }
            }
            i++;  // increment i for two characters %d
        }
        // when \n is found
        else if (format[i] == '\\' && format[i + 1] == 'n') {
            buffer[pos++] = '\r';  // Windows requires \r\n
            buffer[pos++] = '\n';
            i++;
        }
        // copy regular characters as is
        else {
            buffer[pos++] = format[i];
        }
    }

    va_end(args);  // finish variadic argument processing

    // output to Windows console
    DWORD written;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // stdout handle
    
    // kernel is software that directly controls hardware and manages memory and processes
    WriteConsoleA(hConsole, buffer, pos, &written, NULL);
}

int main(int argc, char** argv) {
    int x, y, z;

    while (1) {
        x = 0;
        y = 1;
        do {
            __printf("%d\n", x);

            z = x + y;
            x = y;
            y = z;
        } while (x < 255);
    }
}