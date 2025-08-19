#include <iostream>
using namespace std;

enum StatusIndex { HP = 0, MP = 1, ATK = 2, DEF = 3 };

// 포션 개수 초기화
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    if (p_HPPotion) *p_HPPotion = count;
    if (p_MPPotion) *p_MPPotion = count;
}

void printStatus(const int status[4], int hpPotion, int mpPotion) {
    cout << "\n==== 현재 스탯 ====\n";
    cout << "HP: " << status[HP]
        << " | MP: " << status[MP]
        << " | 공격력: " << status[ATK]
        << " | 방어력: " << status[DEF] << "\n";
    cout << "HP 포션: " << hpPotion << "개 | MP 포션: " << mpPotion << "개\n";
    cout << "===================\n";
}

int main() {
    int status[4] = { 0, 0, 0, 0 }; // [0]=HP, [1]=MP, [2]=ATK, [3]=DEF

    // HP, MP 입력
    while (true) {
        cout << "HP와 MP를 입력하세요 (둘 다 50 초과): ";
        cin >> status[HP] >> status[MP];
        if (!cin.fail() && status[HP] > 50 && status[MP] > 50) break;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    // 공격력 , 방어력 입력
    while (true) {
        cout << "공격력과 방어력을 입력하세요 (둘 다 0 초과): ";
        cin >> status[ATK] >> status[DEF];
        if (!cin.fail() && status[ATK] > 0 && status[DEF] > 0) break;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n";
    }

    int hpPotion = 0, mpPotion = 0;
    setPotion(5, &hpPotion, &mpPotion);

    cout << "\n스탯 관리 시스템을 시작합니다.\n";
    printStatus(status, hpPotion, mpPotion);

    while (true) {
        cout << "\n<스텟 관리 시스템>\n"
            << "1. HP 회복 (+20, HP포션-1)\n"
            << "2. MP 회복 (+20, MP포션-1)\n"
            << "3. HP 강화 (2배 증가)\n"
            << "4. MP 강화 (2배 증가)\n"
            << "5. 공격 스킬 사용 (MP -50)\n"
            << "6. 필살기 사용 (MP의 50% 소모)\n"
            << "7. 나가기\n"
            << "번호를 선택해주세요: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "정수를 입력해주세요.\n";
            continue;
        }

        if (choice == 7) {
            cout << "스텟 관리 시스템을 종료합니다.\n";
            break;
        }

        switch (choice) {
        case 1: { // HP 회복
            if (hpPotion > 0) {
                status[HP] += 20;
                --hpPotion;
                cout << "HP가 20 회복되었습니다. \n";
				cout << "현재 HP : " << status[HP] << "\n";
				cout << "남은 포션의 수 : " << hpPotion << "개\n";
            }
            else {
                cout << "HP 포션이 없습니다!\n";
            }
            break;
        }
        case 2: { // MP 회복
            if (mpPotion > 0) {
                status[MP] += 20;
                --mpPotion;
                cout << "MP가 20 회복되었습니다. (MP포션 -1)\n";
				cout << "현재 MP : " << status[MP] << "\n";
				cout << "남은 포션의 수 : " << mpPotion << "개\n";
            }
            else {
                cout << "MP 포션이 없습니다!\n";
            }
            break;
        }
        case 3: { // HP 강화
            status[HP] *= 2;
            cout << "HP가 2배로 증가했습니다!\n";
            break;
        }
        case 4: { // MP 강화
            status[MP] <<= 1;
            cout << "MP가 2배로 증가했습니다!\n";
            break;
        }
        case 5: { // 공격 스킬 사용
            if (status[MP] >= 50) {
                status[MP] -= 50;
                cout << "공격 스킬 사용! MP가 50 감소했습니다.\n";
            }
            else {
                cout << "MP가 부족합니다! (필요 MP: 50)\n";
            }
            break;
        }
        case 6: { // 필살기 사용
            if (status[MP] > 0) {
                int cost = status[MP] / 2;
                status[MP] -= cost;
                cout << "필살기 사용! MP " << cost << " 소모되었습니다.\n";
            }
            else {
                cout << "MP가 부족합니다! (필요 MP: 현재 MP > 0)\n";
            }
            break;
        }
        default:
            cout << "올바른 메뉴를 선택하세요.\n";
            break;
        }

        printStatus(status, hpPotion, mpPotion);
    }

    return 0;
}