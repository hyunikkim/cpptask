#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <iostream>
#include <fstream>

// 환자 클래스
class Patient {
private:
    std::string name; // 환자 이름
    int age; // 환자 나이

public:
    Patient(const std::string& name, int age) : name(name), age(age) {} // 생성자  

    // 이름
    std::string getName() const { return name; }

    // 나이
    int getAge() const { return age; }

    // 환자 정보 저장
    void saveToFile(std::ofstream& outFile) const {
        outFile << name << "," << age << std::endl;
    }

    // 파일에서 환자 정보 불러오기
    static Patient* loadFromFile(std::ifstream& inFile) {
        std::string name;
        int age;
        char comma;
        if (inFile >> name >> comma >> age) {
            return new Patient(name, age); // 새 객체 동적으로 생성해서 반환
        }
        return nullptr;
    }
};

#endif // PATIENT_H
