#ifndef MinimumOverlap_HPP
#define MinimumOverlap_HPP

#include <string>
#include <vector>
#include <set>
#include <map>
class Student{
	public:
		int id;
		std::vector<int> myGroups;
		void student(int studentId);
};

class MinimumOverlap {
    private: 
	std::vector<Student> studentVector;
    	std::vector<int> theGroups;
	std::map<int, std::vector<int> > studentMap;
	public:

        // Passes in a string pointing to the set/group file.
        // Make sure you store all the sets/groups!
        MinimumOverlap(const std::string &setFile);
	int convertToInt(char number);
        // Returns the minimum number of overlaps possible given a cover.
        // If print is true, it prints the set(s).
        unsigned int findMinimumOverlap(std::set<int> gGroups, const std::vector<int> &cover, const bool &print);
	unsigned int findMinimumOverlap(const std::vector<int> &cover, const bool &print);
};


#endif
