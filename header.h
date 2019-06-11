/*file "Header.h"*/
class employee
{
private:
	int Num;
	int Level;
	float Salary;
	const char* Name;


public:	
	static int maxNum;
	void setNum(int);
	int getNum();
	int calLevel(float);
	int getLevel();
	void setSalary(double);
	virtual float getSalary() = 0;
	void setName(const char*);
	const char* getName();
	static int getMaxNum();
};

class PTTechnician : public employee
{
private:
	int WorkHour;
public:
	PTTechnician(const char*, int, int);
	~PTTechnician();
	float getSalary();
};

class SaleManager : public employee
{
private:
	float fixedSal;
	float departmentSale;
	static int num;
public:	
	Array salesmen;
	SaleManager(const char*, float, int);
	~SaleManager();
	float getSalary();
	void addSalesmen(PTSalesman*);
	void deleteSalesmen(PTSalesman*);
};

class PTSalesman : public employee
{
private:
	float Sale;
public:
	PTSalesman();
	PTSalesman(const char*, float);
	~PTSalesman();
	float getSalary();
	float getSale();
};

class Manager : public employee
{
public:
	Manager();
	~Manager();
};

class Array
{
private:
	PTSalesman* list;
	int size;
public:
	Array(int sz);
	~Array();
	int getsize();
	PTSalesman&  operator[](int);
};
