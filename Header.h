#pragma once
#define SIZE 6

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include <conio.h>
#include <string>


char _Lock[2][6]{ {'V',' ',' ',' ',' ',' '},{'A','*','*','*','*','*'} };

std::string password;
bool UnlockingMechanism();
void PrintLock();
void PasswordCheck();