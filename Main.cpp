#include "Other.h"
#include "DataProcessing.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	DataProcessing data_proc(filename,'*','$');
	data_proc.Read();
}