#include "../include/Parser.hpp"
#include "../include/Lexer.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

/**
*=====================================================
*=                 @author Ahmad Odeh               *=
*=                 @date 13th Jan , 2024            *=
*=               --Ahmad Compiled Language--        *=
*=====================================================
**/

int main(int argc , char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "no enough arguments\n";
        exit(EXIT_FAILURE);
    }


    std::string parser= ACL::Parser::readFromFile(argv[1]) ;

    std::vector<ACL::Tokenizer::Token> v =  ACL::Tokenizer::tokenize(parser);
    
    std::string asm_content = ACL::Tokenizer::tokenesToAsm(v);

    //std::cout << asm_content << '\n';


    ACL::Tokenizer::compile(asm_content);
    system("nasm -f elf64 out/acl.asm -o out/acl.o && ld out/acl.o -o out/ah");

    return EXIT_SUCCESS;
}