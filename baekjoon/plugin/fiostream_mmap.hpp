/**
 * Linux OS based memory mapping code to read input very fast.
 */
/**
 * Normally used form of stat & mmap
 * But can not declare struct stat.
 * struct stat buf; fstat(0, &buf);
 * char* s = (char*) mmap(0, buf.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, 0, 0), *c = s;
 */
/**
 * After read all about input, the memory (*c: used to store input with mmap) is not used anymore.
 * So, we use this memory to store output characters what we write with 'write' function of linux.
 * When reading input is done, the starting memory address(sma) of mmap should be set to c again.
 * This is why we should use resetBuf() function (c = s) before write characters.
 * After assign all of output characters to c, then, c-s will be the length of output characters.
 * if 'write(1, s, c-s)' is called, the characters what we stored to write in 'c' will be output to stdout.
 * Notice: Writing with 'c' should be done only when the number of output characters is fewer than input length.
 */
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int buf[36];
char* out_s = (char*) mmap(0, buf[12], 3, 2, 0, fstat(0, (struct stat*)buf)), *in_s = out_s;
inline void resetBuf() { in_s = out_s; }
inline char getChar() { return *in_s++; }
inline void writeChar(char x) {
	static bool rs = false;
	if (rs == false) { resetBuf(), rs = true; }
	*in_s++ = x;
}
struct Flusher {
  	~Flusher() { write(1, out_s, in_s-out_s); }
} flusher;