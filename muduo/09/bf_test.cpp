#include <iostream>
#include <boost/function.hpp>
#include <boost/bind.hpp>
using namespace std;
class Foo
{
public:
	void memberFunc(double d, int i, int j)
	{
		cout << d << endl;//打印0.5
		cout << i << endl;//打印100       
		cout << j << endl;//打印10
	}
};
int main()
{
	Foo foo;
    boost::function<void (int)> fp = boost::bind(&Foo::memberFunc, &foo, 0.5, _1, 10);
    // (&foo)->memberFunc(0.5, 100, 10);
    fp(100);
	boost::function<void (int, int)> fp1 = boost::bind(&Foo::memberFunc, &foo, 0.5, _1, _2);
	fp1(100, 200);
	boost::function<void (int, int)> fp2 = boost::bind(&Foo::memberFunc, boost::ref(foo), 0.5, _1, _2);
    // foo.memberFunc(0.5, 55, 66);
	fp2(55, 66);
	return 0;
}

