#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#pragma warning(disable: 4996)
using namespace std;


class FileDataProcessing
{
public:
	FileDataProcessing(const char*, const char, const char);
	~FileDataProcessing();
	void Read();
	int GetNumberLines() { return number_lines; }
	int GetNumberLetters() { return number_letters; }
	char* GetDataBeforeDelimiter(int index) { return before_delimiter[index]; }
	char* GetDataAfterDelimiter(int index) { return after_delimiter[index]; }
protected:
	char symbol_end_file;
	string delimiter;
	char* file_data,
		* filename;
	char** before_delimiter,
		** after_delimiter;
	int number_lines,
		number_letters;

	void CalculationFileData(fstream&);
	void DataCollection(fstream&);
	void SetSizeStorages();	
	void WriteData(int, char**, char*&);
};


bool IsEmpty(fstream&);