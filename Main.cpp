#include "Other.h"
#include "DataProcessing.h"


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	FileDataProcessing data_proc(filename,'*','$');
	data_proc.Read();
	RandomNumber num(data_proc.GetNumberLines());
	int index = 0;
	while (true)
	{
		index = num.GetRandomNumber();
		if (index == -1)break;
		cout<< data_proc.GetDataBeforeDelimiter(index) <<" - " << data_proc.GetDataAfterDelimiter(index) << endl;
	}
}