#include <stdio.h>
#include <Windows.h>

int critical_int = 0;
int n = 100000;
void* mutex;

unsigned long __stdcall increase(void* p) {

    int i = 0;
    while (i < n) {
        WaitForSingleObject(mutex, INFINITE);
        critical_int += 1;
        ReleaseMutex(mutex);
        i++;
    }
    return 0;
}

DWORD CALLBACK decrease(LPVOID p) {

    int i = 0;
    while (i < n) {
        WaitForSingleObject(mutex, INFINITE);
        critical_int -= 1;
        ReleaseMutex(mutex);
        i++;
    }
    return 0;
}

int main(void) {

    mutex = CreateMutex(NULL, FALSE, NULL);
    if (mutex == NULL) return;

    void*  thread1 = CreateThread(NULL, 0, increase, NULL, 0, NULL);
    HANDLE thread2 = CreateThread(NULL, 0, decrease, NULL, 0, NULL);

    if (thread1 == NULL || thread2 == NULL) {
        printf_s("fail: %d\n", GetLastError());
        return 1;
    }

    puts("main thread is running...");

    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    CloseHandle(thread1);
    CloseHandle(thread2);
    CloseHandle(mutex);

    printf("%d\n", critical_int);

    return 0;
}