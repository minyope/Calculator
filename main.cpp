#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Student {
public:
    string name;
    int score1;
    int score2;

    // 생성자
    Student(string n, int s1, int s2) : name(n), score1(s1), score2(s2) {}

    // 총점 계산 함수
    int getTotal() const {
        return score1 + score2;
    }

    // 평균 계산 함수
    double getAverage() const {
        return static_cast<double>(getTotal()) / 2.0;
    }
};

// 학생 정보 출력 함수
void printStudent(const Student& s) {
    cout << setw(10) << s.name << setw(10) << s.score1 << setw(10) << s.score2 << setw(10) << s.getTotal() << setw(15) << fixed << setprecision(5) << s.getAverage() << endl;
}

// 정렬을 위한 비교 함수
bool compareTotal(const Student& a, const Student& b) {
    return a.getTotal() < b.getTotal();
}

// 검색을 위한 비교 함수
bool compareName(const Student& s, const string& name) {
    return s.name == name;
}

int main() {
    vector<Student> students;

    while (true) {
        cout << "code : (1.등록, 2. 정렬, 3.검색, 9종료)" << endl;
        int code;
        cin >> code;

        switch (code) {
            case 1: {
                cout << "학생 정보를 저장합니다." << endl;
                string name;
                int score1, score2;

                cout << "이름: ";
                cin >> name;
                cout << "점수1: ";
                cin >> score1;
                cout << "점수2: ";
                cin >> score2;

                students.push_back(Student(name, score1, score2));
                cout << name << " 정보 저장 완료" << endl;
                break;
            }
            case 2: {
                // 정렬
                sort(students.begin(), students.end(), compareTotal);

                // 결과 출력
                cout << "Student name score1 score2 total ave" << endl;
                for (const auto& student : students) {
                    printStudent(student);
                }
                break;
            }
            case 3: {
                // 검색
                string searchName;
                cout << "검색할 학생 이름: ";
                cin >> searchName;

                auto it = find_if(students.begin(), students.end(), bind(compareName, placeholders::_1, searchName));

                if (it != students.end()) {
                    cout << "Student name score1 score2 total ave" << endl;
                    printStudent(*it);
                } else {
                    cout << "검색된 학생이 없습니다." << endl;
                }
                break;
            }
            case 9: {
                // 종료
                return 0;
            }
            default:
                cout << "잘못된 코드입니다. 다시 입력하세요." << endl;
        }
    }

    return 0;
}
