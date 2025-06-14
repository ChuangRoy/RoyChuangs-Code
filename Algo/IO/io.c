#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,avx")
#include <unistd.h>

#define BUF_SIZE 20000000
#define num_length 10

#define fast_get_char (ptr_buf_start == ptr_buf_end && (ptr_buf_end = (ptr_buf_start = buf) + read(0, buf, BUF_SIZE), ptr_buf_start == ptr_buf_end) ? -1 : *ptr_buf_start++)
#define fast_put_char(x) (vi[ptr_buf_out++] = (x))

static char buf[BUF_SIZE], vi[BUF_SIZE], *ptr_buf_start = buf, *ptr_buf_end = buf;
static int ptr_buf_out;

int readInt() {
    int re = 0, neg = 0;
    char c = fast_get_char;
    while (c == ' ' || c == '\n') c = fast_get_char;

    if (c == '-') neg = 1, c = fast_get_char;

    while (c >= '0' && c <= '9') {
        re = (re << 3) + (re << 1) + (c ^ '0'); 
        c = fast_get_char;
    }
    return neg ? -re : re;
}

unsigned readUInt() {
    int re = 0;
    char c = fast_get_char;
    while (c == ' ' || c == '\n') c = fast_get_char;

    while (c >= '0' && c <= '9') {
        re = (re << 3) + (re << 1) + (c ^ '0'); 
        c = fast_get_char;
    }
    return re;
}

void outInt(int x) {
    char str[num_length];
    int p = 0;

    if (x < 0) {
        fast_put_char('-');
        x = -x;
    }

    do {
        str[p++] = '0' ^ (x % 10);
        x /= 10;
    } while (x);

    while (p--) fast_put_char(str[p]);
    fast_put_char('\n');
}

void outUInt(unsigned x) {
    char str[num_length];
    int p = 0;

    do {
        str[p++] = '0' ^ (x % 10);
        x /= 10;
    } while (x);

    while (p--) fast_put_char(str[p]);
    fast_put_char('\n');
}

int main() {
    int a = readInt();
    int b = readInt();
    outInt(a + b);  // Example usage: prints sum of two integers
    write(1, vi, ptr_buf_out);
    return 0;
}