#include <iostream>
#include <string>
using namespace std;

class Dept {
    int size;          // ���� �迭�� ũ��
    int* scores;       // �������� �Ҵ�� ���� �迭
public:
    // ������: size ũ���� �迭�� �������� �Ҵ�
    Dept(int size) {
        this->size = size;
        scores = new int[size]; // ���� �迭 �Ҵ�
    }

    // �Ҹ���: �������� �Ҵ�� �迭�� �����Ͽ� �޸� ���� ����
    ~Dept() { delete[] scores; }

    // �迭 ũ�⸦ ��ȯ�ϴ� �Լ�
    int getSize() { return size; }

    // ������ �Է¹޴� �Լ�
    void read();

    // Ư�� �ε����� ������ 60�� �̻����� Ȯ���ϴ� �Լ�
    bool isOver60(int index);
};

// ������ �Է¹޴� �Լ� ����
void Dept::read() {
    cout << size << "�� ���� �Է�>> ";
    for (int i = 0; i < this->size; i++) {
        cin >> this->scores[i]; // ���� �Է�
    }
}

// Ư�� �ε����� ������ 60�� �̻��̸� true ��ȯ
bool Dept::isOver60(int index) {
    return this->scores[index] > 60; // 60�� �̻��̸� true ��ȯ
}

// 60�� �̻��� ������ ������ ���� �Լ�
int countPass(Dept&dept) { // dept ��ü�� ������ ����
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) count++; // 60�� �̻� ī��Ʈ
    }
    return count;
}

int main() {
    Dept com(10);          // 10���� ������ ��� Dept ��ü ����
    com.read();            // ���� �Է¹ޱ�
    int n = countPass(com); // 60�� �̻��� ������ ���� ���
    cout << "60�� �̻��� " << n << "��";
}
