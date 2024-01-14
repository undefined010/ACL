#include "../include/Parser.hpp"

#include <cstdlib>
#include <iostream> 
#include <fstream>
#include <string>


void ACL::Parser::printVersion() {
    std::cout << "ACL : " << ACL_VERSION << '\n';
}


bool ACL::Parser::isACL(const std::string& fileName) {
    
    std::string res {};
    
    for (
        std::size_t index = fileName.length() - 1; 
        index >= fileName.length() - 4 ;
        --index
        ) 
    
    {
        res.push_back(fileName.at(index));
    }

    return res == "lca.";
}

const std::string ACL::Parser::readFromFile(const std::string& fileName) {
        
    if (fileName.length() == 0) {
        std::cerr << "There are no file to update \nenter an ACL file\n";
        exit(EXIT_FAILURE);
    }

    if (!ACL::Parser::isACL(fileName)) {
        std::cerr << "This is not an acl file ! \n";
        exit(EXIT_FAILURE);
    }

    std::string result;
    std::string lines;
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "An error accured while opening " << fileName << '\n';
        exit(EXIT_FAILURE);
    }

    while (std::getline(file , lines)) 
    {
        if (lines == "\n") {
            std::cout << "SPACE\n";
        }
        
        result+=lines;
    }

    file.close();

    return result;

}