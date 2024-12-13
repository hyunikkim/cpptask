#ifndef HEALTHMANAGER_H
#define HEALTHMANAGER_H

#include "HealthRecord.h"
#include <map>
#include <memory>

// 건강 관리 클래스
class HealthManager {
private:
    std::map<std::string, std::unique_ptr<HealthRecord>> records; // 건강 기록 맵

public:
    // 환자 추가
    void addPatient(const std::string& name, int age) {
        Patient* patient = new Patient(name, age);
        records[name] = std::make_unique<ConcreteHealthRecord>(patient);
    }

    // 건강 기록 추가
    void addHealthRecord(const std::string& name, const std::string& record) {
        if (records.find(name) != records.end()) {
            records[name]->addRecord(record);
        } else {
            throw std::runtime_error("환자를 찾을 수 없습니다.");
        }
    }

    // 모든 건강 기록 표시
    void displayAllRecords() const {
        for (const auto& entry : records) {
            entry.second->displayRecords();
        }
    }
};

#endif // HEALTHMANAGER_H
