#pragma once
#include "Window.h"
#include "Other.h"
#include "FileDataProcessing.h"

class Display
{
public:
	Display(FileDataProcessing* _file_data);
	~Display();
	bool Show(bool reverse = false);
	bool DisplayData(char* first_mas, char* second_mas);
protected:
	FileDataProcessing* file_data;
	RandomNumber* random;
};

