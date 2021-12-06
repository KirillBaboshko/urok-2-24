#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <initializer_list>
using namespace std;
double getSum(double x)
{
	return x;
}
template<class ... Args>
double getSum(double x,  Args... args)
{
	return x+getSum(args...);
}
//int getSum(int count, int first, ...)
//{
//	int sum = 0;
//	int* p = &first;
//	while (count--)
//	{
//		sum += *p;
//		p++;
//
//	}
//	return sum;
//}
//template<class ... Types>
//void func(Types...parameters)
//{
//
//
//}
//void print()
//{}
//template<class First,class ...Other>
//void print(const First& first, const Other& ... other)
//{
//	cout << first;
//	print(other...);
//}
//template<class ... Args>
//void println(const Args& ... args)
//{
//	print(args...);
//	cout << endl;
//}
//struct Point 
//{
//	int x;
//	int y;
//	friend ostream& operator<<(ostream& output, const Point& p)
//	{
//		output << "(" << p.x << "," << p.y << ")";
//		return output;
//	}
//};
template<class T>
class IntArray
{
private:
	int lenght;
	T* data;
public:
	IntArray() :lenght(0), data(nullptr) 
	{

	}
	IntArray(int lenght) :lenght(lenght)
	{
		data = new T[lenght];
	}
	IntArray(const initializer_list<T>& list) :IntArray(list.size())
	{
		int i = 0;
		for (auto& element : list)
		{
			data[i] = element;
			i++;
		}
	}
	~IntArray()
	{
		delete[] data;
	}
	T& operator[](int index)
	{
		return data[index];
	}
	int getLength() const
	{
		return lenght;
	}
};
struct Point
{
		int x;
		int y;
		friend ostream& operator<<(ostream& output, const Point& p)
		{
			output << "(" << p.x << "," << p.y << ")";
			return output;
		}
};
int main()
{
	setlocale(0, "rus");

	//int sum = getSum(5,0,4,2,7,5);
	//cout << sum;
	//println("hello world");
	//println("Pi= ",3.14,'\n',2,"*",2,"=",2*2);
	//Point point{ 12,2 };
	//println("Point: ",point);

	IntArray<Point> array{ Point{1,1},Point{1,1},Point{6,1},Point{18,7} };
	for (int i = 0; i < array.getLength(); i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;

	return 0;
}