#pragma once

#include <optional>
#include <string>
#include <vector>

namespace ACL 
{
    class Tokenizer 
    {
        public:

            enum TokenType
            {
                return_t,
                num_t,
                semi_t
            };

            struct Token 
            {
                TokenType type;
                std::optional<std::string> val;
            };

        public:
            /**
            * @brief The Tokenize function will assign the file contents with the expected types
            * @param fileContents The contents of the ACL file
            */
            
            static std::vector<Token> tokenize (const std::string& fileContents);


            /**
            * @brief Turn Tokenes to x86_64 asm
            * @param
            */

            static std::string tokenesToAsm(const std::vector<Token>& vec);


            /**
            * @brief Writing an x86_64 asm then run it
            * @param input_asm
            **/

            static void compile(const std::string& input_asm);

    };
}