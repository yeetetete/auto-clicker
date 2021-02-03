#include <iostream>
#include <windows.h>

using std::cin;
using std::cout;

void click()
{
    INPUT Input = {0};

    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
}

int main()
{
    unsigned int amt, delay;
    unsigned int timesClicked = 1;

    cout << "\nAmount of times to click: ";
    cin >> amt;
    cout << "\nDelay between each click in milliseconds: ";
    cin >> delay;
    cout << "\nThe clicker will begin in 5 seconds";
    Sleep(5000);

    for (int i = 0; i < amt; i++)
    {
        cout << "\nTimes clicked: " << timesClicked;
        click();
        Sleep(delay);
        timesClicked++;
    }
    return 0;
}