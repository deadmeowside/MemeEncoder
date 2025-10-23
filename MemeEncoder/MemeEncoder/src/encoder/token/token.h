#pragma once
#include <string>

class Token
{
private:
	char symbol;
	std::string alternativeRepresentation;

public:
	Token(const char& symbol, const std::string& alternativeRepresentation) {
		this->symbol = symbol;
		this->alternativeRepresentation = alternativeRepresentation;
	}

	class Builder
	{
	private:
		char symbol;
		std::string alternativeRepresentation;

	public:
		Builder& setSymbol(const char& symbol) {
			this->symbol = symbol;
			return *this;
		}

		Builder& setAlternativeRepresentation(const std::string& alternativeRepresentation) {
			this->alternativeRepresentation = alternativeRepresentation;
			return *this;
		}

		Token build() {
			return Token(this->symbol, this->alternativeRepresentation);
		}
	};

	char getSymbol() const {
		return this->symbol;
	}

	std::string getAlternativeRepresentation() const {
		return this->alternativeRepresentation;
	}
};
