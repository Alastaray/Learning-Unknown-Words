#include "Display.h"



Display::Display(FileDataProcessing* _file_data)
{
	file_data = _file_data;
	file_data->Read();
	random = new RandomNumber(file_data->GetNumberLines());
}
Display::~Display()
{
	delete random;
}
bool Display::Show(bool reverse)
{
	while (true)
	{
		int number = random->GetRandomNumber();
		if (number == -1)return false;
		if (reverse)
		{
			if (!DisplayData(file_data->GetDataAfterDelimiter(number), file_data->GetDataBeforeDelimiter(number)))
				return false;
		}			
		else
		{
			if (!DisplayData(file_data->GetDataBeforeDelimiter(number), file_data->GetDataAfterDelimiter(number)))
				return false;
		}
			
	};
	
	return true;
}
bool Display::DisplayData(char* first_mas, char* second_mas)
{
	cls();
	int	indent_left = 3,
		borders = 2,
		first_mas_size = strlen(first_mas),
		second_mas_size = strlen(second_mas),
		width = max(first_mas_size, second_mas_size) + indent_left * 2 + borders;

	Window win(width, 4, CenterTop, 10, 10);	
	win.DrawFrame();
	win.FillLine(first_mas, (width - borders - first_mas_size) / 2);

	Input Cin;
	char* answer = new char[width - borders + 1];
	strcpy(answer, Cin.GetRuStr(width - borders, 1, win.GetX(), win.GetY() + 1, indent_left));
	if (!Cin.Success())return false;
	if (CompareStr(second_mas, answer))DrawSomething("Right!");
	else DrawSomething("Wrong!");
	delete[]answer;
	return true;
}