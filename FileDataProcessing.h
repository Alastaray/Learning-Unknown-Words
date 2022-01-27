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
	char* GetDataBeforeDelimiter(int index) { return data_before_delimiter[index]; }
	char* GetDataAfterDelimiter(int index) { return data_after_delimiter[index]; }
	void SetFileName(const char*);
	void SetDelimiter(const char);
	void SetSymbolEndFile(const char);
protected:
	char symbol_end_file;
	string delimiter;
	char* file_data,
		* filename;
	char** data_before_delimiter,
		** data_after_delimiter;
	int number_lines,
		number_letters;

	void DeleteDataAfterDelimiter();
	void DeleteDataBeforeDelimiter();
	void CalculationFileData(fstream&);
	void SortData(fstream&);
	void SetSizeStorages();	
	void WriteData(int, char**, char*&);
};


bool IsEmpty(fstream&);