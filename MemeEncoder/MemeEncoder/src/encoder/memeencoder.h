#pragma once
#include <string>
#include <unordered_map>

class MemeEncoder
{
private:
	std::unordered_map<char, std::string> tokens;
	void registerToken(char symbol, const std::string& replacement);

	void initialize();

public:
	MemeEncoder();

	std::string encode(const std::string& text);
};
