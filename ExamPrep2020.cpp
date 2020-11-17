
#include <iostream>
#include "Header.h"
#include <fstream>
int main()
{
    if (UnlockingMechanism())
    {
        std::cout << "Unlocked! Welcome\n";
    }
}

bool UnlockingMechanism()
{
    int horizontal = 0;
    std::string current_password;
    std::fstream file("Password.txt");
    std::getline(file, password);
    if (password.length() == 0)
    {
        password = "ABCDEF";
    }
    PrintLock();
    do 
    {
        switch (_getch())
        {
        case KEY_UP :
            if (!((int)_Lock[1][horizontal] + 1 > 90))
            {
                _Lock[1][horizontal] = ((int)_Lock[1][horizontal] + 1);
                PrintLock();
            }
            break;
		case KEY_DOWN:
			if (!((int)_Lock[1][horizontal] -1 < 65))
			{
				_Lock[1][horizontal] = ((int)_Lock[1][horizontal] - 1);
				PrintLock();
			}
			break;
		case KEY_LEFT:
            if (!(horizontal - 1 < 0))
            {
                _Lock[0][horizontal] = ' ';
                horizontal--;
                _Lock[0][horizontal] = 'V';
                PrintLock();
            }
			break;
		case KEY_RIGHT:
			if (!(horizontal+ 1 >= SIZE))
			{
                _Lock[0][horizontal] = ' ';
				horizontal++;
                _Lock[0][horizontal] = 'V';

                //This is to initialize the spot if its the first time you have moved there
				if (_Lock[1][horizontal] == '*')
				{
                    _Lock[1][horizontal] = 65;
				}
                PrintLock();
			}
			break;
        default:
            break;
        }
		current_password = "";
		for (int x = 0; x < SIZE; x++)
		{
			current_password.push_back(_Lock[1][x]);
		}
		if (current_password == password)
		{
            return true;
		}
    } while (true);
}

void PrintLock()
{
    system("CLS");

    for (int y = 0; y < 2 ; y++)
    {
        std::cout << "\t\t";
		for (int x = 0; x < SIZE; x++)
		{
            std::cout << "[" << _Lock[y][x] << "]";
		}
        std::cout << std::endl;
    }
}
void PasswordCheck()
{
    
}