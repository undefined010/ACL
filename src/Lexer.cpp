#include "../include/Lexer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace ACL;

std::vector<Tokenizer::Token> Tokenizer::tokenize(const std::string& fileContents) {

    if (!fileContents.length()) {
        std::cerr << "There no contents in the ACL file !\n";
        return {};
    }

    std::string buffer;
    std::vector<Token> tokens;

    for (
        int index {0} ; 
        index < fileContents.length() ;
        ++index
        ) 
    
    {
        
        char c {fileContents[index]};
        
        if (std::isspace(c)) continue;


        if (std::isalpha(c)) {
            buffer.push_back(c);

            index ++;
            
            if (std::isalnum(buffer[index])) {
                
                while (std::isalnum(buffer[index])) {
                    buffer.push_back(c);
                    index++;
                }

            }
            if (buffer == "return") {
                tokens.push_back({.type = TokenType::return_t , .val = "return"});
                buffer.clear();
                continue;
            }


            --index;

            
        }

        if (std::isdigit(c)) {
            buffer.push_back(c);
            ++index;

            if (std::isdigit(index)) {
                buffer.push_back(c);
                ++index;
            }

            --index;

            tokens.push_back({.type = TokenType::num_t , .val = buffer});
            buffer.clear();
        }

        if (c == ';') {
            buffer.push_back(c);
            tokens.push_back({.type = TokenType::semi_t , .val = ";" });
            buffer.clear();
        }
    }

    return tokens;
}

std::string Tokenizer::tokenesToAsm(const std::vector<Tokenizer::Token>& toks) {

    if (!toks.size()) return "";

    std::stringstream ostream;
    ostream << "section .text\n    global _start\n\n_start:\n\n";

    for (
        int index {0}       ;
        index < toks.size() ;
        ++ index            
    ) 

    {
        const Token& token = toks[index];

        if (token.type == TokenType::return_t) {
            if (index + 1 < toks.size() && toks[index + 1].type == TokenType::num_t) {
                if (index + 2 < toks.size() && toks[index + 2].type == TokenType::semi_t) {
                    ostream << "    mov rax, 60\n";
                    ostream << "    mov rdi, " << toks[index+1].val.value() << '\n';
                    ostream << "    syscall";
                }
            }
        }

    }


    return ostream.str();
}

void Tokenizer::compile(const std::string &input_asm) {
    if (!input_asm.length()) return;

    std::fstream file("out/acl.asm" , std::ios::out);
    
    if (!file.is_open()) std::cerr << "Fuck\n";

    file << input_asm;


}