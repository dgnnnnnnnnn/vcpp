#include <iostream>
#include <conio.h>
#pragma warning(disable:4996)

using namespace std;

int main() {
    // 입력 쌓을 배열
    char input_buffer[4];
    int input_index = 0;

    // 키보드 입력 받기
    while (true) {
        // 0.3초마다 입력을 쌓는다.
        _sleep(6000);

        // 키보드 입력을 받는다.
        char input = _getch();

        // 입력을 쌓는다.
        if (input != 0) {
            input_buffer[input_index] = input;
            input_index++;
        }

        // ↓↘→a 순으로 입력이 됐는지 확인한다.
        if (input_buffer[0] == '↓' && input_buffer[2] == '→' && input_buffer[3] == 'a') {
            cout << "아도겐! =o" << endl;
            break;
        }
        else {
            cout << "false";
        }
    }

    return 0;
}