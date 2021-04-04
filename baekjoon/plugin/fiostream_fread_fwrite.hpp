#include<iostream>

static const int rbuf_size = 1 << 18;
inline int getChar() {
    static char buf[rbuf_size];
    static int len = 0, pos = 0;
    if (pos == len) pos = 0, len = fread(buf, 1, rbuf_size, stdin);
    if (pos == len) return -1;
    return buf[pos++];
}

static const int wbuf_size = 1 << 18;
static int write_pos = 0;
static char write_buf[wbuf_size];
inline void writeChar(int x) {
    if (write_pos == wbuf_size)
        fwrite(write_buf, 1, wbuf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

struct Flusher {
    ~Flusher() {
        if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
    }
} flusher;