/*file "1.cpp*/
#include <iostream>
#include "Header.h"
using namespace std;


//employee methods implementation
employee* employees[10000];
int employee::maxNum = 0;

void employee::setNum(int Num)
{
	this->Num = Num;
}
int employee::getNum()
{
	return Num;
}
int employee::calLevel(float sal)
{
	if (sal == 100)
	{
		Level = 1;
		return 1;
	}
	if (sal == 200) 
	{
		Level = 2;
		return 2;
	}
	else
	{
		Level = 0;
		return 0;
	}
}
int employee::getLevel()
{
	return Level;
}
void employee::setSalary(double sal)
{
	Salary = (float)sal;
}
float employee::getSalary()
{
	return Salary;
}
void employee::setName(const char* name)
{
	Name = name;
}
const char*  employee::getName()
{
	return Name;
}
int employee::getMaxNum()
{
	return maxNum;
}


//PTSalesman methods implementation
float PTSalesman::getSalary()
{
	return Sale * 0.04;
}

float PTSalesman::getSale()
{
	return Sale;
}
PTSalesman::PTSalesman(const char* name,  float Sale) 
{
	setName(name);
	this->Sale = Sale;
	setSalary(getSalary());
	calLevel(getSalary());
	employees[maxNum] = this;
	maxNum++;
	setNum(maxNum);
}
PTSalesman::PTSalesman()
{
	employees[maxNum] = this;
	maxNum++;
}
PTSalesman::~PTSalesman()
{
	maxNum--;
}


//PTTechnician methods implemetation
float PTTechnician :: getSalary()
{
	setSalary(WorkHour * 100.0);
	return WorkHour * 100.0;
}
PTTechnician::PTTechnician(const char* name, int level, int WorkHour)
{
	this->WorkHour = WorkHour;
	setName(name);
	setSalary(getSalary());
	calLevel(getSalary());
	employees[maxNum] = this;
	maxNum++;
	setNum(maxNum);
}
PTTechnician::~PTTechnician()
{
	maxNum--;
}


//SaleManager methods implementation
int SaleManager::num = 0;
float SaleManager::getSalary()
{
	float s = 0;
	for (int i = 0; i <num; ++i)
	{
		s = s + salesmen[i].getSale();
	}
	departmentSale = s;
	return fixedSal + 0.05*s;
}
SaleManager::SaleManager(const char* name, float fixedSalary, int sz = 50):salesmen(sz)
{
	setName(name);
	fixedSal = fixedSalary;
	setSalary(getSalary());
}
SaleManager::~SaleManager()
{
	maxNum--;
}
void SaleManager::addSalesmen(PTSalesman& s)
{
	salesmen[num] = s;
	num++;
}
void SaleManager::deleteSalesmen(PTSalesman& s)
{
	for (int i = 0; i < num; i++)
	{
		if (salesmen[i].getNum() == s.getNum())
		{
			for (int j = i; j < num-1; j++)
			{
				salesmen[j] = salesmen[j + 1];
			}
			num--;
			return;
		}
	}
}

int SaleManager::getSalesmenNum()
{
	return num;
}

//Manager methods implementation
Manager::Manager()
{
	setSalary(8000);
	employees[maxNum] = this;
	maxNum++;
}
Manager::~Manager()
{
	maxNum--;
}


//Array Implementations
Array::Array(int sz)
{
	size = sz;
	list = new PTSalesman[sz];
}
Array::~Array()
{
	delete[]list;
}
int Array::getsize()
{
	return size;
}
PTSalesman& Array::operator[](int i)
{
	return list[i];
}
int main()
{
	PTSalesman a("o", 30000);
	PTSalesman b("u", 3000);
	PTSalesman c("x", 43000);
	SaleManager x("y", 30000, 4);
	x.addSalesmen(a);
	x.addSalesmen(b);
	cout << a.getSalary() << " " << a.getNum() << endl;
	cout << b.getSalary() << " " << b.getNum() << endl;
	cout << x.getSalary() << " " << x.getSalesmenNum() << endl;
	x.deleteSalesmen(a);
	cout << x.getSalary() << endl;
	system("pause");
}
