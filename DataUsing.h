#pragma once
#include "Window.h"
#include "Other.h"
#include "FileDataProcessing.h"

class DataUsing
{
public:
	DataUsing(FileDataProcessing* _file_data);
	~DataUsing();
	bool UseData(bool reverse = false);
	bool ShowData(const char* first_mas, const char* second_mas);
	bool CheckData(const char* source, Window& win, int indent_left = 0);
	void GetStatistics();
protected:
	FileDataProcessing* file_data;
	RandomNumber* random;
	int wrong_answers,
		right_answers;
};

