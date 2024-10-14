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
        scores = new int[size];
    }

    // 복사 생성자: 깊은 복사 수행 (새로운 배열을 생성하고 값을 복사)
    Dept(const Dept& dept) {
        this->size = dept.size;
        scores = new int[size];
        for (int i = 0; i < size; i++) {
            this->scores[i] = dept.scores[i];
        }
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
        cin >> this->scores[i];
    }
}

// 특정 인덱스의 점수가 60점 이상이면 true 반환
bool Dept::isOver60(int index) {
    if (this->scores[index] > 60) return true;
    else return false;
}

// 60점 이상인 점수의 개수를 세는 함수
int countPass(Dept dept) {
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) count++;
    }
    return count;
}

int main() {
    Dept com(10);          // 10개의 점수를 담는 Dept 객체 생성
    com.read();            // 점수 입력받기
    int n = countPass(com); // 60점 이상인 점수의 개수 계산
    cout << "60점 이상은 " << n << "명";
}
