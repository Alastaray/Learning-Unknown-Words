#include "FileDataProcessing.h"




FileDataProcessing::FileDataProcessing(const char* _filename, const char _delimiter, const char _symbol_end_file)
{
	SetFileName(_filename);
	SetDelimiter(_delimiter);
	SetSymbolEndFile(_symbol_end_file);
	file_data = 0;
	data_before_delimiter = 0;
	data_after_delimiter = 0;
	number_lines = number_letters = 0;
}
FileDataProcessing::~FileDataProcessing()
{
	delete[]filename;
	delete[]file_data;
	DeleteDataBeforeDelimiter();
	DeleteDataAfterDelimiter();
}
void FileDataProcessing::CalculationFileData(fstream& file)
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
void FileDataProcessing::SortData(fstream& file)
{
	file.seekg(ios::beg);
	file.getline(file_data, number_letters, symbol_end_file);
	char* word = strtok(file_data, delimiter.c_str());
	for (int i = 0; i < number_lines; i++)
	{
		RecordData(i, data_before_delimiter, word);
		RecordData(i, data_after_delimiter, word);
	}
}
void FileDataProcessing::SetSizeStorages()
{
	file_data = new char[number_letters];
	data_before_delimiter = new char* [number_lines];
	data_after_delimiter = new char* [number_lines];
}
void FileDataProcessing::Read()
{
	if (file_data)delete[]file_data;
	if (data_before_delimiter)DeleteDataBeforeDelimiter();
	if (data_after_delimiter)DeleteDataAfterDelimiter();
	if (number_lines || number_letters)number_lines = number_letters = 0;
	fstream file;
	file.open(filename, ios::out | ios::in | ios::app);
	if (IsEmpty(file))
	{
		file.close();
		throw exception((string(this->filename) + " is empty!").c_str());
	}
	CalculationFileData(file);
	SetSizeStorages();
	SortData(file);
	file.close();
}
void FileDataProcessing::RecordData(int index, char** destination, char*& pointer_strtok)
{
	destination[index] = new char[strlen(pointer_strtok) + 1];
	strcpy(destination[index], pointer_strtok);
	if (destination[index][strlen(destination[index]) - 1] == ' ')
		destination[index][strlen(destination[index]) - 1] = '\0';
	while (destination[index][0] == ' ')
	{
		char* buff = new char[strlen(destination[index]) + 1];
		strcpy(buff, destination[index]);
		int i, j;
		for (i = 0, j = 1; j < strlen(buff); i++, j++)
		{
			destination[index][i] = buff[j];
		}
		destination[index][i] = '\0';
		delete[]buff;
	}
	pointer_strtok = strtok(0, delimiter.c_str());
}
void FileDataProcessing::DeleteDataAfterDelimiter()
{
	for (int i = 0; i < number_lines; i++)
		delete[]data_after_delimiter[i];
	delete[]data_after_delimiter;
}
void FileDataProcessing::DeleteDataBeforeDelimiter()
{
	for (int i = 0; i < number_lines; i++)
		delete[]data_before_delimiter[i];
	delete[]data_before_delimiter;
}
void FileDataProcessing::SetFileName(const char* _filename)
{
	if (filename)delete[]filename;
	filename = new char[strlen(_filename) + 1];
	strcpy(filename, _filename);
}
void FileDataProcessing::SetDelimiter(const char _delimiter)
{
	delimiter = "";
	delimiter += _delimiter;
	delimiter += '\n';
}
void FileDataProcessing::SetSymbolEndFile(const char _symbol_end_file)
{
	symbol_end_file = _symbol_end_file;
}

bool IsEmpty(fstream& file)
{
	file.seekg(ios::beg);
	bool fact = (file.peek() == std::fstream::traits_type::eof());
	file.clear();
	file.seekg(ios::beg);
	return fact;
}

