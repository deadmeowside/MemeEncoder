#include "memeencoder.h"

void MemeEncoder::registerToken(char symbol, const std::string& replacement) {
	tokens[symbol] = replacement;
}

void MemeEncoder::initialize() {
	const std::pair<char, const char*> symbolMap[] = {
		{'а', "a"}, 
		{'б', "6"},
		{'в', "B"},
		{'г', "r"},
		{'д', "D"},
		{'е', "e"},
		{'ё', "e"},
		{'ж', ">|<"}, 
		{'з', "3"},
		{'и', "u"},
		{'й', "u"},
		{'к', "K"},
		{'л', "JI"},
		{'м', "M"},
		{'н', "H"},
		{'о', "o"},
		{'п', "TT"},
		{'р', "p"},
		{'с', "c"}, 
		{'т', "T"},
		{'у', "y"}, 
		{'ф', "<|>"},
		{'х', "x"}, 
		{'ц', "Tc"},
		{'ч', "4"},
		{'ш', "LLI"},
		{'щ', "LLI"}, 
		{'ъ', "b"}, 
		{'ы', "bI"},
		{'ь', "b"},
		{'э', "3"},
		{'ю', "|O"}, 
		{'я', "9I"}
	};

	for (auto& [lower, repl] : symbolMap) {
		registerToken(lower, repl);

		wchar_t upper = std::toupper((unsigned char)lower);
		registerToken(upper, repl);
	}
}

MemeEncoder::MemeEncoder() {
	initialize();
}

std::string MemeEncoder::encode(const std::string& text) {
	std::string encoded;
	encoded.reserve(text.size() * 2);

	for (char c : text) {
		if (auto it = tokens.find(c); it != tokens.end())
			encoded += it->second;
		else
			encoded += c;
	}

	return encoded;
}
