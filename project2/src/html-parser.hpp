#ifndef HTML_PARSER_HPP
#define HTML_PARSER_HPP
#include <fstream>
#include <string>
#include <vector>
class HTMLParser {
    private:
    	std::vector<std::string> mParser;
    	std::vector<std::string> mPages;
    public:
        HTMLParser();
        ~HTMLParser();
        void parse(std::string filename);
        bool isBalanced(std::string filename);
        int pageVisitAmount(std::string filename);
};

#endif
