#include "DataProcessing.h"




DataProcessing::DataProcessing(const char* _filename, const char _word_delimiter, const char _symbol_end_file)
{
	filename = new char[strlen(_filename)+1];
	strcpy(filename, _filename);
	symbol_end_file = _symbol_end_file;
	delimiter = "";
	delimiter += _word_delimiter;
	delimiter += '\n';
	file_data = 0;
	before_delimiter = 0;
	after_delimiter = 0;
	number_lines = number_letters = 0;
}
DataProcessing::~DataProcessing()
{
	delete[]file_data;
	delete[]filename;
	for (int i = 0; i < number_lines; i++)
		delete[]before_delimiter[i];
	delete[]before_delimiter;
	for (int i = 0; i < number_lines; i++)
		delete[]after_delimiter[i];
	delete[]after_delimiter;
}
void DataProcessing::CalculationFileData(fstream& file)
{
	file.seekg(ios::beg);
	char buff[1000];
	int i;
	while (!file.eof())
	{
		i = 0;
		file.getline(buff, 1000);
		while (buff[i] != 0)
		{
			number_letters++;
			i++;
		}
		number_lines++;
	}
	file.clear();
	file.seekg(ios::beg);
	number_letters += number_lines;
}
void DataProcessing::DataCollection(fstream& file)
{
	file.seekg(ios::beg);
	file.getline(file_data, number_letters, symbol_end_file);
	char* word = strtok(file_data, delimiter.c_str());
	for (int i = 0; i < number_lines; i++)
	{
		WriteData(i, before_delimiter, word);
		WriteData(i, after_delimiter, word);
	}
}
void DataProcessing::SetSizeStorages()
{
	file_data = new char[number_letters];
	before_delimiter = new char* [number_lines];
	after_delimiter = new char* [number_lines];
}
void DataProcessing::Read()
{
	fstream file;
	file.open(filename, ios::out | ios::in | ios::app);
	CalculationFileData(file);
	SetSizeStorages();
	DataCollection(file);
	file.close();
}
void DataProcessing::WriteData(int index, char** destination, char*& pointer_strtok)
{
	destination[index] = new char[strlen(pointer_strtok) + 1];
	strcpy(destination[index], pointer_strtok);
	pointer_strtok = strtok(0, delimiter.c_str());
}

bool IsEmpty(fstream& file)
{
	file.seekg(ios::beg);
	bool fact = (file.peek() == std::fstream::traits_type::eof());
	file.clear();
	file.seekg(ios::beg);
	return fact;
}

