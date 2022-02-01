#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "List.h"
#pragma warning(disable: 4996)
using namespace std;


class FileDataProcessing
{
public:
	FileDataProcessing(const char* _filename, const char _delimiter);
	~FileDataProcessing();
	void Read();
	int GetNumberLines() { return number_lines; }
	int GetNumberLetters() { return number_letters; }
	char* GetDataBeforeDelimiter(int index) { return data_before_delimiter[index]; }
	char* GetDataAfterDelimiter(int index) { return data_after_delimiter[index]; }
	void SetFileName(const char* _filename);
	void SetDelimiter(const char _delimiter);
	void Write(List<string>& data);

protected:
	string delim;
	char symbol_end_file,
				delimiter;
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
	void RecordData(int, char**, char*&);
};


bool IsEmpty(fstream&);