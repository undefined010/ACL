#pragma once 

#include <string>

#define ACL_VERSION "0.0.1"

namespace ACL 
{
    class Parser
    {
        public:

            /**
            * @brief showing the version ACL (Ahmad Compiled Language)
            *
            */

            static void printVersion();
            
            /** 
            * @brief reading ACL (Ahmad Compiled Languge) files
            * @param fileName
            */
            
            static const std::string readFromFile(const std::string& fileName);

        private:
        /**
        * @brief to cheak file if it is ACL (Ahmad Compiled Languge)
        * @param fileName
        */
            static bool isACL(const std::string& fileName);

    };
}