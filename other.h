#pragma once
#include <conio.h>
#include <iostream>
#include "fun_console.h"
#include <stdlib.h>
#include <ctime>
#include "Window.h"
using namespace std;
#pragma warning(disable: 4996)


bool CompareStr(const char* value, const char* source);
void Move(char& key, int& x, int& y, int how_change_x = 0, int how_change_y = 0);


class Input
{
public:
	Input() { buff = 0; }
	~Input() { delete buff; }
	char* GetRuStr(int max_len, int min_len = 0, int px = 0, int py = 0, int indent_letf = 0, int indent_top = 0);
	char* GetEngStr(int max_len, int min_len = 0, int px = 0, int py = 0, int indent_letf = 0, int indent_top = 0);
	char* GetStr(int max_len, int min_len = 0, int px = 0, int py = 0, int indent_letf = 0, int indent_top = 0);
	bool Success() { return buff[0]; }
private:
	char* buff;
	enum Keys
	{
		Esc = 27,
		Enter = 13,
		Backspace = 8,
		Space = 32,
		a_eng = 'a',
		z_eng = 'z',
		a_ru = 224,
		ya_ru = 255,
		Comma = ','
	};
	bool Ñomplement(int key,int &iter, int min_len);
	void DataPreparation(int max_len, int& px, int& py, int indent_letf = 0, int indent_top = 0);

};


class RandomNumber
{
public:
	RandomNumber(int max, int min = 0);
	~RandomNumber() { delete[]mas; }
	int GetRandomNumber();
	int GetCurrentNumber() { return mas[counter - 1]; }
protected:
	int	max,
		min,
		counter,
		* mas;
};

