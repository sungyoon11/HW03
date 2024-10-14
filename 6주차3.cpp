#include <iostream>
#include <string>
using namespace std;

class Dept {
    int size;          // 점수 배열의 크기
    int* scores;       // 동적으로 할당된 점수 배열
public:
    // 생성자: size 크기의 배열을 동적으로 할당
    Dept(int size) {
        this->size = size;
        scores = new int[size]; // 동적 배열 할당
    }

    // 소멸자: 동적으로 할당된 배열을 해제하여 메모리 누수 방지
    ~Dept() { delete[] scores; }

    // 배열 크기를 반환하는 함수
    int getSize() { return size; }

    // 점수를 입력받는 함수
    void read();

    // 특정 인덱스의 점수가 60점 이상인지 확인하는 함수
    bool isOver60(int index);
};

// 점수를 입력받는 함수 구현
void Dept::read() {
    cout << size << "개 점수 입력>> ";
    for (int i = 0; i < this->size; i++) {
        cin >> this->scores[i]; // 점수 입력
    }
}

// 특정 인덱스의 점수가 60점 이상이면 true 반환
bool Dept::isOver60(int index) {
    return this->scores[index] > 60; // 60점 이상이면 true 반환
}

// 60점 이상인 점수의 개수를 세는 함수
int countPass(Dept&dept) { // dept 객체를 값으로 복사
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) count++; // 60점 이상 카운트
    }
    return count;
}

int main() {
    Dept com(10);          // 10개의 점수를 담는 Dept 객체 생성
    com.read();            // 점수 입력받기
    int n = countPass(com); // 60점 이상인 점수의 개수 계산
    cout << "60점 이상은 " << n << "명";
}
