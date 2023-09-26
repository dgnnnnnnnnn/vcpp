#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
using namespace std;

#define UP 72;

// 함수: 화살표 키를 화살표 기호로 변환
string GetArrowSymbol(char inputKey) {
    if (inputKey == 72) {
        return "↑"; // 위쪽 화살표 키 (↑)
    }
    else if (inputKey == 80) {
        return "↓"; // 아래쪽 화살표 키 (↓)
    }
    else if (inputKey == 75) {
        return "←"; // 왼쪽 화살표 키 (←)
    }
    else if (inputKey == 77) {
        return "→"; // 오른쪽 화살표 키 (→)
    }
    else
        return ""; // 다른 키인 경우 빈 문자열 반환
}

// inputkey(char) >> command(string) >> inputBuffer(array)
int main() {
    vector<char> inputBuffer;
    string command;

    while (true) {
        char inputKey = _getch(); // 키 입력을 읽음

        // 0.3초(300ms) 동안 입력을 쌓음
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        // 입력을 버퍼에 추가
        inputBuffer.push_back(inputKey);
        command += GetArrowSymbol(inputKey); // 화살표 키를 화살표 기호로 변환하여 커맨드에 추가

        // 이후 화살표 키 처리 로직 추가
        if (inputKey == 27) { // ESC 키를 누르면 프로그램 종료
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        }

        // 화면을 지우고 현재 입력된 커맨드를 표시
        system("cls");
        std::cout << "command> " << command;
    }

    return 0;
}
