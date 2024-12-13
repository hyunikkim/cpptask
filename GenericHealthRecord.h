#ifndef GENERICHEALTHRECORD_H
#define GENERICHEALTHRECORD_H

#include "HealthRecord.h"

// 제네릭 건강 기록 클래스
template <typename T>
class GenericHealthRecord : public HealthRecord {
private:
    T additionalInfo; // 추가 정보

public:
    GenericHealthRecord(Patient* p, T info) : HealthRecord(p), additionalInfo(info) {}

    // 건강 기록 표시 구현
    void displayRecords() const override {
        std::cout << "Health Records for " << patient->getName() << ":\n";
        for (const auto& record : records) {
            std::cout << "- " << record << std::endl;
        }
        std::cout << "Additional Info: " << additionalInfo << std::endl; // 추가 정보 표시
    }
};

#endif // GENERICHEALTHRECORD_H
