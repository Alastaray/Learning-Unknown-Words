#include "DataUsing.h"



DataUsing::DataUsing(FileDataProcessing* _file_data)
{
	file_data = _file_data;
	file_data->Read();
	random = new RandomNumber(file_data->GetNumberLines());
	wrong_answers = right_answers = 0;
}
DataUsing::~DataUsing()
{
	delete random;
}
void DataUsing::UseData(bool reverse)
{
	while (true)
	{
		int number = random->GetRandomNumber();
		if (number == -1)break;
		if (reverse)
		{
			if (!ShowData(file_data->GetDataAfterDelimiter(number), file_data->GetDataBeforeDelimiter(number)))
				break;
		}			
		else
		{
			if (!ShowData(file_data->GetDataBeforeDelimiter(number), file_data->GetDataAfterDelimiter(number)))
				break;
		}
	};
	GetStatistics();
}
bool DataUsing::ShowData(const char* first_mas, const char* second_mas)
{
	cls();
	int	indent_left = 3,
		first_mas_size = strlen(first_mas),
		second_mas_size = strlen(second_mas),
		width = max(first_mas_size, second_mas_size) + indent_left * 2;

	Window win(width, 2, CenterTop, 10, 10);	
	win.DrawFrame();
	win.FillLine(first_mas, (width - first_mas_size) / 2);
	return CheckData(second_mas, win, indent_left);
}
bool DataUsing::CheckData(const char* source, Window& win, int indent_left)
{
	Input Cin;
	char* answer = new char[win.GetWidth() + 1];
	strcpy(answer, Cin.GetStr(win.GetWidth(), 1, win.GetX(), win.GetY() + 1, indent_left));
	cls();
	if (!Cin.Success())return false;
	if (!CompareStr(source, answer))
	{
		wrong_answers++;
		DrawSomething(string("Right answer is ") + source);
	}
	else right_answers++;
	delete[]answer;
	return true;
}
void DataUsing::GetStatistics()
{
	cls();
	int indent_left = 6;
	Table table(42, 1, CenterTop, 3, 0,0,10);
	table.AddHeadline("Right Answers");
	table.AddHeadline("Wrong Answers");
	table.AddHeadline("Total Questions");
	table.DrawTable();
	table.DrawHeadlines();
	table.WriteLine(right_answers, indent_left);
	table.WriteLine(wrong_answers, indent_left + table.GetSizeCol());
	table.WriteLine(file_data->GetNumberLines(), indent_left + table.GetSizeCol()*2);
	getch();
	cls();
}
