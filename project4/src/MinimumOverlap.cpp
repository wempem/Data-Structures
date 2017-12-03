#include "MinimumOverlap.hpp"
#include <fstream>
#include <set>
// Well Dr.West, this project was tough. I didn't get it done because I was too behind. Poorly planned  on my part. Hopefully I will not have to see you again next semester in Data Structures, but in architecture. Anyways, happy holidays!
void Student::student(int studentId){
	id = studentId; 
}

MinimumOverlap::MinimumOverlap(const std::string &setFile) {
	
	int index = 0;
	int i = 0;
	int studentId = 0;
	bool found = false;

	std::string line;
	std::string temp;
	std::ifstream file(setFile.c_str());

	while(std::getline(file, line)){
		theGroups.push_back(index);
		while(line[i] != '\0'){
			if(line[i] == ' '){
				i++;
			}
			else{
				studentId = convertToInt(line[i]);
				for(int i = 0; i < studentVector.size(); i++){
					if(studentVector[i].id == studentId){
						found = true;
					}
				}
				if(found != true){
				Student *newStudent = new Student(); 
					studentVector.push_back(*newStudent);
				}
				studentVector[studentId].myGroups.push_back(index);
			}
			i++;
		
		}
		index++;
		studentId = 0;
		i = 0;
		found = false;
	}
        
}

unsigned int MinimumOverlap::findMinimumOverlap(const std::vector<int> &cover, const bool &print){
	std::set<int> gGroups;
	for(int i = 0; i < cover.size(); i++){
		for(typename std::vector<int>::iterator j; j < studentVector[i].myGroups.end(); j++){
			if(gGroups.count(studentVector[i].myGroups[*j]) == 0){
				gGroups.insert(studentVector[i].myGroups[*j]);
			}	
		}
	}
	return findMinimumOverlap(gGroups,cover,print);	
}	

unsigned int MinimumOverlap::findMinimumOverlap(std::set<int> gGroups, const std::vector<int> &cover, const bool &print)
{

//unsigned int min = UINT_MAX;


}
int MinimumOverlap::convertToInt(char number){
	char a = number;
	int ia = a - '0';
	return ia;
}

