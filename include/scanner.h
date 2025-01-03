#ifndef SCANNER
#define SCANNER

typedef enum TokenType {
	LBRACE, RBRACE
} TokenType;

typedef struct Token {
	const char* literal;
	int line;
	TokenType type;
} Token;

typedef struct Scanner {
	const char* start;
	const char* current;
	int line;
} Scanner;

void initScanner(Scanner* scanner, const char* source);
Token scanToken(Scanner* scanner);

#endif
