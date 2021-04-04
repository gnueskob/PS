#include <iostream>
#include <tuple>

namespace GNUES
{
	// just template
	inline char getChar() {char c; if ((std::cin>>std::noskipws>>c)) return c; return 0;}
	inline void writeChar(char c) {std::cout<<c;}

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
		if (end) std::cout << end;
	}

	inline void writeWord(const char *s, char end = 0) {
		while (*s) writeChar(*s++);
		if (end) std::cout << end;
	}

	inline void writeWord(const std::string& s, char end = 0) {
		for (const char c : s) writeChar(c);
		if (end) std::cout << end;
	}
}
using namespace GNUES;

int main() {
	int n = readInt();
	writeInt(n, '\n');

	auto [n1, n2, n3] = readInts<int, int, int>();
	writeInts(' ', '\n', n1, n2, n3);

	writeWord("string\n");

	char char_str[100];
	readWord(char_str);
	writeWord(char_str);

	auto str = readWord();
	writeWord(str);

	return 0;
}