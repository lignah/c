#define clamp(x, l, r) (max((l), min((x), (r))))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int main(void) {
    int a = -5;
    int b = clamp(a, 0, 10); // a < 0, b = 0
    int c = clamp(15, 0, 10); // 15 > 10, c =10
    int d = clamp(7, 0, 10); // 7 >= 0 && 7 <= 10, d = 7
    return 0;
}