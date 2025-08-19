#include <iostream>
using namespace std;

enum StatusIndex { HP = 0, MP = 1, ATK = 2, DEF = 3 };

// ���� ���� �ʱ�ȭ
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    if (p_HPPotion) *p_HPPotion = count;
    if (p_MPPotion) *p_MPPotion = count;
}

void printStatus(const int status[4], int hpPotion, int mpPotion) {
    cout << "\n==== ���� ���� ====\n";
    cout << "HP: " << status[HP]
        << " | MP: " << status[MP]
        << " | ���ݷ�: " << status[ATK]
        << " | ����: " << status[DEF] << "\n";
    cout << "HP ����: " << hpPotion << "�� | MP ����: " << mpPotion << "��\n";
    cout << "===================\n";
}

int main() {
    int status[4] = { 0, 0, 0, 0 }; // [0]=HP, [1]=MP, [2]=ATK, [3]=DEF

    // HP, MP �Է�
    while (true) {
        cout << "HP�� MP�� �Է��ϼ��� (�� �� 50 �ʰ�): ";
        cin >> status[HP] >> status[MP];
        if (!cin.fail() && status[HP] > 50 && status[MP] > 50) break;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
    }

    // ���ݷ� , ���� �Է�
    while (true) {
        cout << "���ݷ°� ������ �Է��ϼ��� (�� �� 0 �ʰ�): ";
        cin >> status[ATK] >> status[DEF];
        if (!cin.fail() && status[ATK] > 0 && status[DEF] > 0) break;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "���ݷ��̳� ������ ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
    }

    int hpPotion = 0, mpPotion = 0;
    setPotion(5, &hpPotion, &mpPotion);

    cout << "\n���� ���� �ý����� �����մϴ�.\n";
    printStatus(status, hpPotion, mpPotion);

    while (true) {
        cout << "\n<���� ���� �ý���>\n"
            << "1. HP ȸ�� (+20, HP����-1)\n"
            << "2. MP ȸ�� (+20, MP����-1)\n"
            << "3. HP ��ȭ (2�� ����)\n"
            << "4. MP ��ȭ (2�� ����)\n"
            << "5. ���� ��ų ��� (MP -50)\n"
            << "6. �ʻ�� ��� (MP�� 50% �Ҹ�)\n"
            << "7. ������\n"
            << "��ȣ�� �������ּ���: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "������ �Է����ּ���.\n";
            continue;
        }

        if (choice == 7) {
            cout << "���� ���� �ý����� �����մϴ�.\n";
            break;
        }

        switch (choice) {
        case 1: { // HP ȸ��
            if (hpPotion > 0) {
                status[HP] += 20;
                --hpPotion;
                cout << "HP�� 20 ȸ���Ǿ����ϴ�. \n";
				cout << "���� HP : " << status[HP] << "\n";
				cout << "���� ������ �� : " << hpPotion << "��\n";
            }
            else {
                cout << "HP ������ �����ϴ�!\n";
            }
            break;
        }
        case 2: { // MP ȸ��
            if (mpPotion > 0) {
                status[MP] += 20;
                --mpPotion;
                cout << "MP�� 20 ȸ���Ǿ����ϴ�. (MP���� -1)\n";
				cout << "���� MP : " << status[MP] << "\n";
				cout << "���� ������ �� : " << mpPotion << "��\n";
            }
            else {
                cout << "MP ������ �����ϴ�!\n";
            }
            break;
        }
        case 3: { // HP ��ȭ
            status[HP] *= 2;
            cout << "HP�� 2��� �����߽��ϴ�!\n";
            break;
        }
        case 4: { // MP ��ȭ
            status[MP] <<= 1;
            cout << "MP�� 2��� �����߽��ϴ�!\n";
            break;
        }
        case 5: { // ���� ��ų ���
            if (status[MP] >= 50) {
                status[MP] -= 50;
                cout << "���� ��ų ���! MP�� 50 �����߽��ϴ�.\n";
            }
            else {
                cout << "MP�� �����մϴ�! (�ʿ� MP: 50)\n";
            }
            break;
        }
        case 6: { // �ʻ�� ���
            if (status[MP] > 0) {
                int cost = status[MP] / 2;
                status[MP] -= cost;
                cout << "�ʻ�� ���! MP " << cost << " �Ҹ�Ǿ����ϴ�.\n";
            }
            else {
                cout << "MP�� �����մϴ�! (�ʿ� MP: ���� MP > 0)\n";
            }
            break;
        }
        default:
            cout << "�ùٸ� �޴��� �����ϼ���.\n";
            break;
        }

        printStatus(status, hpPotion, mpPotion);
    }

    return 0;
}