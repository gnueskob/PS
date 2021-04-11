// url
// #include<bits/stdc++.h>

#include <iostream>
#include <tuple>
namespace GNUES
{
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

	inline char readChar() {
		char c = getChar();
		while (c <= 32) c = getChar();
		return c;
	}

	template <class T = int>
	inline T readInt() {
		T x = 0; bool p = true; char c = readChar();
		if (c == '-') p = !p, c = getChar();
		while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
		return p ? x : -x;
	}

	template <typename... T>
	inline std::tuple<T...> readInts() { return { readInt<T>()... }; }

	inline int readWord(char* str) {
		char c; int len=0;
		while((c=getChar()) != '\n' && c != ' ' && c > 32) *str++=c, len++; *str=0;
		return len;
	}

	inline std::string readWord() {
		std::string str; char c;
		while((c=getChar()) != '\n' && c != ' ' && c > 32) str += c;
		return str;
	}

	template <class T>
	inline void writeInt(T x, char end = 0) {
		if (x < 0) writeChar('-'), x = -x;
		char s[24]; int n = 0;
		while (x || !n) s[n++] = '0' + x % 10, x /= 10;
		while (n--) writeChar(s[n]);
		if (end) writeChar(end);
	}

	template <typename... T>
	inline void writeInts(char delimiter, char end, T... ints)
	{
		( writeInt(ints, delimiter), ... );
		if (end) writeChar(end);
	}

	inline void writeWord(const char *s, char end = 0) {
		while (*s) writeChar(*s++);
		if (end) writeChar(end);
	}

	inline void writeWord(const std::string& s, char end = 0) {
		for (const char c : s) writeChar(c);
		if (end) writeChar(end);
	}
}

#ifdef GNUES_INPUT
	#include "plugin/fiostream.hpp"
	#include "_fileRead.hpp"
	GNUES::FileRead f("_test.txt");
#endif

int main() {
    // std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

    auto [a, b, c, d] = readInts<int, int, int, int>();

    std::cout << a << ' ' << b << ' ' << c << ' ' << d;

    return 0;
}