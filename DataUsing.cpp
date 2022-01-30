#include "DataUsing.h"



Display::Display(FileDataProcessing* _file_data, const char* path_right_answers)
{
	SetPathRightAnswers(path_right_answers);
	file_data = _file_data;
	file_data->Read();
	random = new RandomNumber(file_data->GetNumberLines());
}
void Display::ShowPreparation()
{
	random->Reset();
	statistic->ResetNumberAnswers();
	for (int i = 0; i < statistic->GetCount(); i++)
		random->PreFill(statistic->GetRightAnswers()[i]);
}
void Display::Show(bool reverse)
{
	if (reverse)
		statistic = new Statistic((string("reverse_") + path_right_answers).c_str());
	else
		statistic = new Statistic(path_right_answers);
	statistic->ReadRightAnswers();
	ShowPreparation();
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
	statistic->WriteRightAnswers();
	ShowStatistic();
	delete statistic;
}
bool Display::ShowData(const char* first_mas, const char* second_mas)
{
	cls();
	int	indent_left = 3,
		first_mas_size = strlen(first_mas),
		second_mas_size = strlen(second_mas),
		width = max(first_mas_size, second_mas_size) + indent_left * 2;

	Window win(width, 2, CenterTop, 10, 10);	
	win.DrawFrame();
	win.FillLine(first_mas, (width - first_mas_size) / 2);
	return statistic->CheckData(second_mas, random->GetCurrentNumber(), win, indent_left);
}
void Display::ShowStatistic()
{
	cls();
	int indent_left = 6;
	Table table(42, 1, CenterTop, 3, 0,0,10);
	table.AddHeadline("Right Answers");
	table.AddHeadline("Wrong Answers");
	table.AddHeadline("Total Questions");
	table.DrawTable();
	table.DrawHeadlines();
	table.WriteLine(statistic->GetNumberRightAnswers(), indent_left);
	table.WriteLine(statistic->GetNumberWrongAnswers(), indent_left + table.GetSizeCol());
	table.WriteLine(file_data->GetNumberLines() - statistic->GetCount() + statistic->GetNumberRightAnswers(),
					indent_left + table.GetSizeCol()*2);
	getch();
	cls();
}
void Display::SetPathRightAnswers(const char* _path_right_answers)
{
	if (path_right_answers)delete[]path_right_answers;
	path_right_answers = new char[strlen(_path_right_answers) + 1];
	strcpy(path_right_answers, _path_right_answers);
}





Statistic::Statistic(const char* _filename)
{
	SetFileName(_filename);
	number_wrong_answers = number_right_answers = 0;
}
void Statistic::SetFileName(const char* _filename)
{
	if (filename)delete[]filename;
	filename = new char[strlen(_filename) + 1];
	strcpy(filename, _filename);
}
bool Statistic::CheckData(const char* source, int source_number, Window& win, int indent_left)
{
	Input Cin;
	char* answer = new char[win.GetWidth() + 1];
	strcpy(answer, Cin.GetStr(win.GetWidth(), 1, win.GetX(), win.GetY() + 1, indent_left));
	cls();
	if (!Cin.Success())return false;
	if (!CompareStr(source, answer))
	{
		number_wrong_answers++;
		DrawSomething(string("Right answer is ") + source);
	}
	else
	{
		number_right_answers++;
		right_answers << source_number;
	}
	delete[]answer;
	return true;
}
void Statistic::WriteRightAnswers()
{
	fstream file;
	file.open(filename, ios::in | ios::out | ios::trunc | ios::binary);
	for (int i = 0; i < right_answers.GetCount(); i++)
	{
		file.write((char*)&right_answers[i], right_answers.GetSizeOfType());
	}
	file.close();
}
void Statistic::ReadRightAnswers()
{
	fstream file;
	file.open(filename, ios::in | ios::out | ios::app | ios::binary);
	int buff = 0;
	while (file.read((char*)&buff, sizeof(buff)))
		right_answers << buff;
	file.close();
}