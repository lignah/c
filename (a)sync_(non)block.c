#include <stdio.h>
#include <Windows.h>

unsigned long __stdcall thread_1(void* p);
DWORD CALLBACK thread_2(LPVOID p);
unsigned long __stdcall thread_3(void* p);

int main(void) {

    /* async non block */
    void*  thread1 = CreateThread(NULL, 0, thread_1, NULL, 0, NULL);
    HANDLE thread2 = CreateThread(NULL, 0, thread_2, NULL, 0, NULL);
    void*  thread3 = CreateThread(NULL, 0, thread_3, NULL, 0, NULL);
    unsigned char sync_non_block = 0;

    if (thread1 == NULL || thread2 == NULL || thread3 == NULL) {
        printf_s("fail: %d\n", GetLastError());
        return 1;
    }

    puts("main thread is running...");

    /* sync non block */
    while (1) {
        unsigned long waiting = WaitForSingleObject(thread3, 500);
        if (waiting != WAIT_OBJECT_0) {
            puts("thread_3 is waiting...");
            sync_non_block++;
            continue;
        }   break;
    }

    /* sync block */
    /* WaitForSingleObject(): block the next task to run */
    WaitForSingleObject(thread1, INFINITE);
    WaitForSingleObject(thread2, INFINITE);

    CloseHandle(thread1);
    CloseHandle(thread2);
    CloseHandle(thread3);

    printf("\nsync_non_block: %d\n", sync_non_block);
    puts("thread_1, thread_2, thread_3 finish");

    return 0;
}

unsigned long __stdcall thread_1(void* p) {
    printf("thread_1: %d\n", 0);
    unsigned char i = 0;
    while (i < 3) {
        Sleep(1000);
        printf("thread_1: %d\n", i + 1);
        i = i + 1;
    }
    return 1;
}

DWORD CALLBACK thread_2(LPVOID p) {
    printf("thread_2: %d\n", 0);
    unsigned char i = 0;
    do {
        Sleep(1000);
        printf("thread_2: %d\n", i + 1);
        i++;
    } while (i < 3);
    return 2;
}

unsigned long __stdcall thread_3(void* p) {
    printf("thread_3: %d\n", 0);
    unsigned char i = 0;
    while (i < 3) {
        Sleep(1000);
        printf("thread_3: %d\n", i + 1);
        i = i + 1;
    }
    return 3;
}

/*
 * main thread is running...
 * thread_1: 0
 * thread_2: 0
 * thread_3: 0
 * thread_3 is waiting...
 * thread_3 is waiting...
 * thread_3: 1
 * thread_2: 1
 * thread_1: 1
 * thread_3 is waiting...
 * thread_2: 2
 * thread_3 is waiting...
 * thread_1: 2
 * thread_3: 2
 * thread_3 is waiting...
 * thread_3: 3
 * thread_3 is waiting...
 * thread_1: 3
 * thread_2: 3
 *
 * sync_non_block: 6
 * thread_1, thread_2, thread_3 finish
*/