#pragma once
#include "Window.h"
#include "Other.h"
#include "FileDataProcessing.h"

class Statistic
{
public:
	Statistic(const char* _filename);
	~Statistic() { delete[]filename; }
	bool CheckData(const char* source, int source_number, Window& win, int indent_left = 0);
	void WriteRightAnswers();
	void ReadRightAnswers();
	void SetFileName(const char* _filename);
	void RemoveAll() { right_answers.RemoveAll(); }
	void ResetNumberAnswers(){ number_wrong_answers = number_right_answers = 0; }
	int GetCount() { return right_answers.GetCount(); }
	int GetNumberWrongAnswers() { return number_wrong_answers; }
	int GetNumberRightAnswers() { return number_right_answers; }
	List<int>& GetRightAnswers() { return right_answers; }

protected:
	char* filename;
	int number_wrong_answers,
		number_right_answers;
	List<int> right_answers;
};

class Display
{
public:
	Display(FileDataProcessing* _file_data, const char* _path_right_answers);
	~Display() { delete random; }
	void Show(bool reverse = false);
	bool ShowData(const char* first_mas, const char* second_mas);	
	void ShowStatistic();
	void SetPathRightAnswers(const char* _path_right_answers);
protected:
	char* path_right_answers;
	Statistic* statistic;
	FileDataProcessing* file_data;
	RandomNumber* random;

	void ShowPreparation();
};

