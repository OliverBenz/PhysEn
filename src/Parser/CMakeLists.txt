add_library(Parser SHARED
	LexMessages.hpp
	Type.hpp   Type.cpp
	Lexer.hpp  Lexer.cpp

	Tree.hpp   Tree.cpp
	Parser.hpp Parser.cpp
)