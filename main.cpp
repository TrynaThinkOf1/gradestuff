#include <stdexcept>
#include <map>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>

std::string gpaConverter(int type, float gpa);
float rigorCalc(int numOfAP, int numOfHonors, int numOfAPOffered);
float calculateGPA(int type, std::list<float> grades);

float calculateGPA(int type, std::list<float> grades) {
    float gpa = 0;
    for (auto grade : grades) {
        gpa += grade;
    }
    if (type == 4) {
        gpa /= grades.size();
        gpaConverter(4, gpa);
    }
    else if (type == 100) {
        gpa /= 100;
    }
}

float rigorCalc(int numOfAP, int numOfHonors, int numOfAPOffered) {
    float weightedHonors = numOfHonors * 1.5f;
    float APs = (numOfAP/numOfAPOffered) * 3.0f;

    if (weightedHonors != 0 && APs != 0) {
        return weightedHonors + APs;
    }
    else {
        throw std::invalid_argument("Invalid number of APs or Honors");
    }
}

std::string gpaConverter(int type, float gpa) {
    if (type == 4) {
        std::map<float, float> conversionTable;
        conversionTable[100] = 4.0;
        conversionTable[93] = 4.0;
        conversionTable[90] = 3.7;
        conversionTable[87] = 3.3;
        conversionTable[83] = 3.0;
        conversionTable[80] = 2.7;
        conversionTable[77] = 2.3;
        conversionTable[73] = 2.0;
        conversionTable[70] = 1.7;
        conversionTable[67] = 1.3;
        conversionTable[63] = 1.0;
        conversionTable[60] = 0.7;
        conversionTable[57] = 0.3;
        conversionTable[53] = 0.0;
        if (conversionTable[gpa]) {
            std::ostringstream result;
            result << "The 4 point scale GPA for " << gpa << " is " << conversionTable[gpa] << std::endl;
            return result.str();
        }
        else {
            std::ostringstream result;
            result << "(GPA Not Found on Conversion Table) The 4 point scale GPA for " << gpa << " is " << gpa/25 << std::endl;
            return result.str();
            }
        }
    else if (type == 100) {
        std::ostringstream result;
        result << "The 100 point scale GPA for " << gpa << " is " << gpa*25 << std::endl;
        return result.str();
    }
}

int main() {
    std::cout << "Welcome to GPA Converter!" << std::endl << "Convert from 100-pt to 4-pt (4) or from 4-pt to 100-pt (100)? ";
    std::string choice;
    std::cin >> choice;

    if (choice == "4") {
        std::cout << "Enter your GPA: ";
        float gpa;
        std::cin >> gpa;
        std::cout << gpaConverter(4, gpa);
    }
    else if (choice == "100") {
        std::cout << "Enter your 4-pt GPA: ";
        float gpa;
        std::cin >> gpa;
        std::cout << gpaConverter(100, gpa);
    }
    else {
        std::cout << "Invalid choice. Please try again." << std::system("clear");
        main();
    }
    return 0;
}