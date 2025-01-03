#include "scanner.h"

void initScanner(Scanner* scanner, const char* source) {
	scanner->line = 1;
	scanner->start = source;
	scanner->current = source;
}

Token scanToken(Scanner* scanner) {
	
}