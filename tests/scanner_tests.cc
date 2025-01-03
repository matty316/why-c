#include <gtest/gtest.h>

extern "C" {
#include "scanner.h"
}

extern "C" Token scanToken(Scanner* scanner);
extern "C" void initScanner(Scanner* scanner, const char *source);

TEST(ScannerTest, TestScanToken) {
	const char source[] = "{}";
	Scanner scanner;
	initScanner(&scanner, source);
	Token expTokens[2] = {
		{ .literal = "{", .line = 1, .type = LBRACE },
		{ .literal = "}", .line = 1, .type = RBRACE },
	};
	
	for (int i = 0; i < 2; i++) {
		Token token = scanToken(&scanner);
		Token expToken = expTokens[i];
		ASSERT_EQ(token.line, expToken.line);
		ASSERT_EQ(token.literal, expToken.literal);
		ASSERT_EQ(token.type, expToken.type);
	}
}