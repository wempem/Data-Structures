#include "html-parser.hpp"
#include <vector>
#include <string>
#include <fstream>
HTMLParser::HTMLParser() {
}

HTMLParser::~HTMLParser() {
}

void HTMLParser::parse(std::string filename) {

	int i = 0;
	std::string line;
	std::string temp;
	std::ifstream file(filename.c_str());

	while(std::getline(file, line)){
        	while(line[i] != '\0'){
                	if(line[i] == '<'){
				i++;
				while(line[i] != '>'){
					temp += line[i];
					i++;
				}
				mParser.push_back(temp);	
			}
			i++;
		}
		line = "";
		temp = "";
		i = 0;
	}
}
bool HTMLParser::isBalanced(std::string filename) {
	if(mParser.size() % 2 == 1){
		return false;
	}
	
	int middle = mParser.size() / 2;
	std::string temp = "";
	std::vector<std::string>::iterator p = mParser.end();
	std::vector<std::string>::iterator i = mParser.begin();
	std::vector<std::string>::iterator mid = mParser.begin() + middle - 1;
	bool balance = false;
	
	while(i != mid){
		temp = '/' + *i;
		if(temp == *(i+1)){
			balance = true;
			i++;
		}
		else if(temp == *p){
			balance = true;
		}
		else{
			return false;
		}
		i++;
		p--;
		temp = "";
	}
	return balance;
}

int HTMLParser::pageVisitAmount(std::string filename) {
	int i = 0;
	int pages = 0;
	std::string temp = "";
	std::string line = "";
	std::ifstream file(filename.c_str());	
	while(std::getline(file, line)){
        	while(line[i] != '\0'){
                	if(line[i] == '<'){
                         	i++;
                        	while(line[i] != '\0'){
                                	i++;
					if(line[i] == '='){
						i++;
						while(line[i] != '>'){
							temp += line[i];	
							i++;
						}
						pages++;
						pages += pageVisitAmount(temp);	
                 			} 
				}
              
          		}
			i++;
	       }
	  line = "";
          temp = "";
          i = 0;
  	}
	return pages;
}
