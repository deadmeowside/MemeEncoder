#include "memeencoder.h"

std::string mapSymbol(char c) {
	return std::string();
}

void MemeEncoder::registerToken(const Token& token) {
	tokens.push_back(token);
}

void MemeEncoder::initialize() {
	registerToken(Token('а', "a"));
	registerToken(Token('б', "6"));
	registerToken(Token('в', "B"));
	registerToken(Token('г', "r"));
	registerToken(Token('д', "D"));
	registerToken(Token('е', "e"));
	registerToken(Token('ё', "e"));
	registerToken(Token('ж', ">|<"));
	registerToken(Token('з', "3"));
	registerToken(Token('и', "u"));
	registerToken(Token('й', "u"));
	registerToken(Token('к', "K"));
	registerToken(Token('л', "JI"));
	registerToken(Token('м', "M"));
	registerToken(Token('н', "H"));
	registerToken(Token('о', "o"));
	registerToken(Token('п', "TT"));
	registerToken(Token('р', "p"));
	registerToken(Token('с', "c"));
	registerToken(Token('т', "T"));
	registerToken(Token('у', "y"));
	registerToken(Token('ф', "<|>"));
	registerToken(Token('х', "x"));
	registerToken(Token('ц', "Tc"));
	registerToken(Token('ч', "4"));
	registerToken(Token('ш', "LLI"));
	registerToken(Token('щ', "LLI"));
	registerToken(Token('ъ', "b"));
	registerToken(Token('ы', "bI"));
	registerToken(Token('ь', "b"));
	registerToken(Token('э', "3"));
	registerToken(Token('ю', "|O"));
	registerToken(Token('я', "9I"));

	registerToken(Token('А', "A"));
	registerToken(Token('Б', "6"));
	registerToken(Token('В', "B"));
	registerToken(Token('Г', "r"));
	registerToken(Token('Д', "D"));
	registerToken(Token('Е', "E"));
	registerToken(Token('Ё', "E"));
	registerToken(Token('Ж', ">|<"));
	registerToken(Token('З', "3"));
	registerToken(Token('И', "U"));
	registerToken(Token('Й', "U"));
	registerToken(Token('К', "K"));
	registerToken(Token('Л', "JI"));
	registerToken(Token('М', "M"));
	registerToken(Token('Н', "H"));
	registerToken(Token('О', "O"));
	registerToken(Token('П', "TT"));
	registerToken(Token('Р', "P"));
	registerToken(Token('С', "C"));
	registerToken(Token('Т', "T"));
	registerToken(Token('У', "Y"));
	registerToken(Token('Ф', "<|>"));
	registerToken(Token('Х', "X"));
	registerToken(Token('Ц', "Tc"));
	registerToken(Token('Ч', "4"));
	registerToken(Token('Ш', "LLI"));
	registerToken(Token('Щ', "LLI"));
	registerToken(Token('Ъ', "b"));
	registerToken(Token('Ы', "bI"));
	registerToken(Token('Ь', "b"));
	registerToken(Token('Э', "3"));
	registerToken(Token('Ю', "|O"));
	registerToken(Token('Я', "9I"));
}

MemeEncoder::MemeEncoder() {
	initialize();
}

std::string MemeEncoder::encode(const std::string& text) {
	std::string encodedText;

	for(const char& c : text) {
		bool found = false;

		for(const Token& token : tokens) {
			if(token.getSymbol() == c) {
				encodedText += token.getAlternativeRepresentation();
				found = true;

				break;
			}
		}

		if(!found) {
			encodedText += c;
		}

	}

	return encodedText;
}
