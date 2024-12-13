/* 과제 설명

컴퓨터프로그래밍 및 실습 평가과제(25점)
학과: 컴퓨터전자시스템공학부
학번: 201701102
이름: 김현익
주제: 환자의 건강 기록을 미래 병원에서 효과적으로 관리할 수 있는 프로그램 개발.
수업에서 배웠던 내용과 평가 내용에서 제시된 클래스나 포인터, 다형성을 모두 활용할 수 있는 프로그램 작성
*/

#include <iostream>
#include <fstream>
#include "HealthManager.h"
#include "GenericHealthRecord.h"

int main() {
    HealthManager manager;

    // 파일에서 환자 불러오기
    std::ifstream inFile("C:\\Users\\01hyu\\Desktop\\patients.txt");
    if (inFile.is_open()) {
        while (true) {
            Patient* patient = Patient::loadFromFile(inFile);
            if (!patient) break;
            manager.addPatient(patient->getName(), patient->getAge());
        }
        inFile.close();
    } else {
        std::cerr << "파일을 여는 데 오류가 발생했습니다." << std::endl; // 파일 오류
    }

    // 건강 기록 추가
    try {
        manager.addHealthRecord("Chulsu Kim", "Annual check-up: Healthy");
        manager.addHealthRecord("Yeonghee Park", "Blood test: Normal");

        // 제네릭 건강 기록 추가
        Patient* genericPatient = new Patient("Mijeong Jung", 30); // 객체 새로 만들기
        GenericHealthRecord<std::string> genericRecord(genericPatient, "No allergies"); // 제네릭 객체 생성
        genericRecord.addRecord("Routine check-up: Good");
        genericRecord.displayRecords();
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl; // 예외
    }
    
    // 모든 환자 기록 표시
    manager.displayAllRecords();

    return 0;
}
