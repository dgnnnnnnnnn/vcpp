#include <iostream>
#include <chrono>
#include <cmath>
#include <conio.h>

int main(void)
{
    std::chrono::system_clock::time_point start;
    std::chrono::duration<double> sec;
    bool checkTime = false;

    while (true)
    {
        char c;

        if (_kbhit()) {        //Ű���� �Է� Ȯ�� (true / false)
            if (checkTime == false)
            {
                checkTime = true;
                start = std::chrono::system_clock::now();
            }
            c = _getch();      // ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
            if (c == 27) {    // -32�� �ԷµǸ�
                exit(1);
            }
        }

        if (checkTime)
        {
            sec = std::chrono::system_clock::now() - start;
        }

        start = std::chrono::system_clock::now();

        sec = std::chrono::system_clock::now() - start;
        std::cout << "for���� �����µ� �ɸ��� �ð�(��) : " << sec.count() << "seconds" << std::endl;
    }


    return 0;
}