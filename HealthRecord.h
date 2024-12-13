#ifndef HEALTHRECORD_H
#define HEALTHRECORD_H

#include "Patient.h"
#include <vector>
#include <string>

// 건강 기록의 추상 클래스
class HealthRecord {
protected:
    Patient* patient; // 환자 포인터
    std::vector<std::string> records; // 건강 기록

public:
    HealthRecord(Patient* p) : patient(p) {}
    virtual ~HealthRecord() { delete patient; } // 소멸자

    // 건강 기록 추가
    void addRecord(const std::string& record) {
        records.push_back(record);
    }

    // 건강 기록 표시
    virtual void displayRecords() const = 0; // 순수 가상 함수
};

// 구체적인 건강 기록 클래스
class ConcreteHealthRecord : public HealthRecord {
public:
    ConcreteHealthRecord(Patient* p) : HealthRecord(p) {}

    // 건강 기록 표시 구현
    void displayRecords() const override {
        std::cout << "Health Records for " << patient->getName() << ":\n";
        for (const auto& record : records) {
            std::cout << "- " << record << std::endl;
        }
    }
};

#endif // HEALTHRECORD_H
