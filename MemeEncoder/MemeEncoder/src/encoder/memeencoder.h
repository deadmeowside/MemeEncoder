#pragma once
#include <string>
#include <vector>

#include "token/token.h"

class MemeEncoder
{
private:
	std::vector<Token> tokens;
	void registerToken(const Token& token);

	void initialize();

public:
	MemeEncoder();

	std::string encode(const std::string& text);
};
