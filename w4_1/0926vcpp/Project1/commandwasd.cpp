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
    if (inputKey == 224) {
        inputBuffer.push_back(inputKey);
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


/*
    WinMain 진입점 함수
    int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);

    * hInstance : 인스턴스에 대한 핸들 이거나 모듈에 대한 핸들입니다. 
                  운영 체제는 이 값을 사용하여 메모리에 로드될 때 실행 파일 또는 EXE를 식별합니다.
    * hPrevInstance : 의미 X, 16비트 Windows에서 사용되었지만 이제는 항상 0입니다.
    * pCmdLine : 명령줄 인수(main 함수에 전달 할 인수) 가 유니코드 문자열로 포함
    * nCmdShow : 기본 애플리케이션 창 크기 조절
*/
