#include <iostream>

class IErrorLog
{
public:
	virtual bool openLog(const char* fileName) = 0;
	virtual bool closeLog() = 0;
	virtual bool writeError(const char* errorMessage) = 0;

	virtual ~IErrorLog() {};
};

int main()
{

}