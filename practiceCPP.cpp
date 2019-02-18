#include "stdafx.h"
#include "Sales_data.h" //书店销售类
#include "date.h"		//日期格式化类
//#include "StrBlob.h"	//动态内存(shared_ptr,weak_ptr)
#include "MyStrBlob.h"
#include "HasPtr.h"
#include "String.h"

/***************************/
/*        C头文件           */
#include <cstdarg>			//可变参数
#include <ctime>			//随机数引擎
#include <cstdlib>			//系统库函数
#include <cstring>			//c 的原字符串操作

/***************************/
/*        流					*/
#include <iostream>			//输入输出流
#include <fstream>			//文件流
#include <sstream>			//字符串流

/***************************/
/*        顺序容器           */
#include <vector>			//向量
//#include <string>			//字符串
#include <basetyps.h>
#include <forward_list>		//单链表
#include <list>				//双链表
#include <deque>			//双端队列
/*        适配容器          */
#include <queue>			//单队列适配器
#include <stack>			//栈适配容器
/*        关联容器          */
#include <map>				//图 ：底层实现为”关联数组“
#include <set>				//集合
#include <unordered_map>	//无序 图 ：底层实现为“哈希映射的桶”
#include <unordered_set>	//无序 集合 :底层实现为”哈希映射的桶“

/*********算法泛型***********/		
#include <algorithm>		//算法 （泛型
#include <numeric>			//数值算法
#include <iterator>			//迭代器
#include <functional>		//bind,


#define Enter cout <<endl;
#define OUT_LINE cout << "Value of __LINE__ : " << __LINE__ << endl;
#define OUT_FILE cout << "Value of __FILE__ : " << __FILE__ << endl;
#define OUT_DATE cout << "Value of __DATE__ : " << __DATE__ << endl;
#define OUT_TIME cout << "Value of __TIME__ : " << __TIME__ << endl;

using namespace std;
using namespace placeholders;
// test.cpp : Defines the entry point for the console application.
//


/*#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

int main()
{
vector<int> src;

cout << "请输入整形数组：";
int temp;
while (cin >> temp)
{
src.push_back(temp);
}

cout << "include: " << cin.include() << endl;
cout << "eof: " << cin.eof() << endl;
cout << "fail: " << cin.fail() << endl;
cout << "bad: " << cin.bad() << endl;

cin.clear();
cin.sync();
cout << "include: " << cin.include() << endl;
cout << "eof: " << cin.eof() << endl;
cout << "fail: " << cin.fail() << endl;
cout << "bad: " << cin.bad() << endl;

int target;

cout << "请输入需查找数：";
cin >> target;
}*/

/*	include: 0
eof: 1
fail : 1
bad : 0

include : 1
eof : 0
fail : 0
bad : 0
*/


/*
int a = 3;
int b = 4;
decltype(a) c = a;
decltype((b)) d = b; //int &
++c;
++b;
cout << "a = " << a
	<< "b = " << b
	<< "c = " << c
	<< "d = " << d <<endl;
*/
/*

const	int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k2 = i;
cout << typeid(i).name() << endl;
cout << typeid(j).name() << endl;
cout << typeid(k).name() << endl;
cout << typeid(p).name() << endl;
cout << typeid(j2).name() << endl;
cout << typeid(k2).name() << endl;

*/
/*

int a = 3, b = 4;
decltype(a)  c = a;
decltype(a = b) d = a; // int &
cout << a << endl;
cout << c << endl;
++d;
cout << d << endl;
3return 0;
*/
/*

#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

class Sales_data
{
	//友元函数
	friend std::istream& operator >> (std::istream&, Sales_data&);
	//友元函数
	friend std::ostream& operator << (std::ostream&,const Sales_data&);
	//友元函数
	friend bool operator < (const Sales_data&, const Sales_data&);
	//友元函数
	friend bool operator == (const Sales_data&, const Sales_data&);
public:		//构造函数的三种形式
	Sales_data() = default;				//默认构造函数
	Sales_data(const std::string &book) : bookNo(book) { }//初始化列表，类中定义 ‘属性’的的顺序相同。
	Sales_data(std::istream &is) { is >> *this; }
public:
	Sales_data& operator +=(const Sales_data&); // 返回Sales_data& 节约内存,不能返回内部变量，可以返回 static，和指针
	string isbn() const { return bookNo; }
private:
	std::string bookNo;				//书籍编号,隐式初始化为空串；
	unsigned units_sold = 0;		//销售量，显式初始化为0
	double sellingprice = 0.0;		//原始价格,显示初始化为0.0
	double saleprice = 0.0;			//实售价格，显示初始化为0.0
	double discount = 0.0;			//折扣，显示初始化为0.0

};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs)
//友元函数
{
	return lhs.units_sold == rhs.units_sold
		&& lhs.sellingprice == rhs.sellingprice
		&& lhs.saleprice == rhs.saleprice
		&& lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);//基于运算符==给出！=的定义
}


Sales_data operator + (const Sales_data&, const Sales_data&);



Sales_data& Sales_data::operator +=(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold)
		/ (rhs.units_sold + units_sold);
	if (sellingprice != 0)
		discount = saleprice / sellingprice;
	return *this;

}

Sales_data operator +(const Sales_data &lhs, const Sales_data&rhs)
{
	Sales_data ret(lhs);	//把lhs的内容拷贝到临时变量ret中，这种做法便于运算
	ret += rhs;				//把rhs的内容加入到其中
	return ret;				//返回ret
}

std::istream& operator >> (std::istream& in, Sales_data& s)
//友元函数

{
	in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
	if (in && s.sellingprice != 0 )
	{
		s.discount = s.saleprice / s.sellingprice;
	}
	else
	{
		s = Sales_data();
	}

	return in;
}

std::ostream& operator << (std::ostream& out, const Sales_data & s)
//友元函数

{
	out << s.isbn() << " " << s.units_sold << " "
		<< s.sellingprice << " " << s.saleprice << " " << s.discount;
	return out;
}

bool operator < (const Sales_data &, const Sales_data &)
{
	return false;
}

int main()
{
	Sales_data book;
	std::cout << "请输入销售记录：" << std::endl;
	while (std::cin >> book){
		std::cout << "ISBN,售出价格，原始价格，实售价格，折扣为" << std::endl << book
			<< std::endl;
	}
	cin.clear();
	Sales_data trans1, trans2;
	std::cout << "请输入两条ISBN相同的销售记录：" << std::endl;
	std::cin >> trans1 >> trans2;
	if (compareIsbn(trans1, trans2)) {
		std::cout << "汇总信息：ISBN,售出本书，原始价格，实售价格，折扣为：" << endl
			<< trans1 + trans2 << std::endl;
	}
	else {
		std::cout << "两条销售记录的ISBN不同" << std::endl;
	}

	cin.clear();
	Sales_data  total, trans;
	if (std::cin >> total){
		while (std:: cin >> trans)
			if (compareIsbn(total,trans)){	//ISBN相同
				total = total + trans;
			}
			else{							//ISBN不同
				std::cout << "当前书籍ISBN不同" << std::endl;
				break;
			}
	}
	else {
		std::cout << "没有数据" << std::endl;
		return -1;
	}

	int num = 1;	//记录当前书籍的销售记录总数
	std::cout << "请输入若干销售记录:" << std::endl;
	if (std::cin >> trans1){
		while (std::cin >> trans2)
			if (compareIsbn(trans1, trans2)) {	//ISBN相同
				num++;
			}//if
			else { //ISBN不同
				std::cout << trans1.isbn() << "共有"
					<< num << "条销售记录" << std::endl;
				trans1 = trans2;
				num = 1;
			}//else
			std::cout << trans1.isbn() << "共有"
				<< num << "条销售记录" << std::endl;
	}//if
	else {
		std::cout << "没有数据" << std::endl;
		return -1;
	}
	return 0;
}*/

/*************************/
///2016-11-17 星期四////////
///第三章 字符串、向量和数组//
/*************************/

/*
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data
{
	friend istream& operator >> (istream&, Sales_data&);
	friend ostream& operator << (ostream&, const Sales_data&);
	friend bool operator < (const Sales_data&,const Sales_data&);
	friend bool operator == (const Sales_data&, const Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &book):bookNo(book) {}
	Sales_data(istream& is) { is >> *this; }
public:
	Sales_data& operator += (const Sales_data&);
	string isbn()const { return bookNo; }
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};

Sales_data operator +(const Sales_data&, const Sales_data&);
inline bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn ();
}
inline bool operator == (const Sales_data &lhs,const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn()
		&& lhs.bookNo == rhs.bookNo
		&& lhs.units_sold == rhs.units_sold
		&&lhs.sellingprice == rhs.sellingprice
		&&lhs.saleprice == rhs.saleprice;
}
Sales_data operator +(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data ret(lhs);
	ret += rhs;
	return ret;
}
istream& operator >> (istream &in, Sales_data& s)
{
	in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
	if (in && s.sellingprice){
		s.discount = (s.saleprice/s.sellingprice);
	}
	return in;
}
ostream& operator << (ostream&out,const Sales_data &s)
{
	out << s.bookNo <<" " << s.units_sold
		<< " " << s.sellingprice
		<< " " << s.saleprice
		<< " " << s.discount;
		return out;
}

Sales_data& Sales_data::  operator += (const Sales_data &s)
{
	units_sold += s.units_sold;
	saleprice = ((saleprice * units_sold + s.saleprice * s.units_sold)
		/ (units_sold + s.units_sold));
	if (sellingprice != 0) {
		discount = saleprice / sellingprice;
	}
	return *this;
}
int main()
{
	Sales_data book;
	cout << "请输入销售记录（ISBN,售出本书，原始价格，实售价格）：" << endl;
	while (cin >> book) {
		cout << "ISBN,售出本书，原始价格，实售价格，折扣为" << endl << book
			<< endl;
	}
	cin.clear();

	Sales_data trans1, trans2;
	cout << "请输入两条ISBN相同的销售记录（ISBN,售出本书，原始价格，实售价格）：" << endl;
	cin >> trans1 >> trans2;
	if (compareIsbn(trans1, trans2)) {
		std::cout << "汇总信息：ISBN,售出本书，原始价格，实售价格，折扣为：" << endl
			<< (trans1 + trans2) << endl;
	}
	else {
		cout << "两条销售记录的ISBN不同" << endl;
	}

	cin.clear();
	cin.sync();
	Sales_data  total, trans;
	if (std::cin >> total) {
		while (cin >> trans)
			if (compareIsbn(total, trans)) {	//ISBN相同
				total = total + trans;
			}
			else {							//ISBN不同
				cout << "当前书籍ISBN不同" << endl;
				break;
			}
	}
	else {
		cout << "没有数据" << endl;
		return -1;
	}

	int num = 1;	//记录当前书籍的销售记录总数
	cout << "请输入若干销售记录:" << endl;
	if (cin >> trans1) {
		while (cin >> trans2)
			if (compareIsbn(trans1, trans2)) {	//ISBN相同
				num++;
			}//if
			else { //ISBN不同
				cout << trans1.isbn() << "共有"
					<< num << "条销售记录" << endl;
				trans1 = trans2;
				num = 1;
			}//else
			std::cout << trans1.isbn() << "共有"
				<< num << "条销售记录" << endl;
	}//if
	else {
		cout << "没有数据" << endl;
		return -1;
	}
	return 0;
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{

	string line;
	cout << "请输入你的字符串，可以包含空格：" << endl;
	while (getline(cin,line)) {
		cout << line << endl;
	}

	string word;
	cout << "输入你的单词,不可包含空格!" << endl;
	while ( cin >> word){
		cout << word << endl;
	}
	return 0;

	string word, line;
	cout << "请选择读取 字符串打的方式：1表示逐词读取，2表示整行读取" << endl;
	char ch;
	cin >> ch;
	if (ch == '1') {
		cout << "请输入字符串： Welcome to c++ family！  " << endl;
		cin >> word;
		cout << "系统读取有效字符为：" << endl;
		cout << word << endl;
		return 0;
	}

	cout << "include: " << cin.include() << endl;
	cout << "eof: " << cin.eof() << endl;
	cout << "fail: " << cin.fail() << endl;
	cout << "bad: " << cin.bad() << endl;

	cin.clear();
	cin.sync();
	cout << "include: " << cin.include() << endl;
	cout << "eof: " << cin.eof() << endl;
	cout << "fail: " << cin.fail() << endl;
	cout << "bad: " << cin.bad() << endl;

	getchar();
	if (ch = '2') {
		cout << "请输入字符串：Welcome to c++ family！ " << endl;
		getline(cin,line);
		cout << "读取的有效字符串:" << endl;
		cout << line << endl;
		return 0;
	}
	cout << "你输入的字符有误！";
	return -1;
}*/

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cout << "请输入两个字符串:" << endl;
	cin >> s1 >> s2;
	if (s1 == s2 ) {
		cout << "两个字符串相等!" << endl;
	}
	else if (s1 > s2) {
		cout << s1 << "大于" << s2 << endl;
	}
	else cout << s2 << "大于" << s1 << endl;
	return 0;
}
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	auto len1 = s1.size();
	auto len2 = s2.size();
	if (len1 == len2) {
		cout << s1 << "和" << s2 << " 的长度都是" << len1 << endl;
	}
	else if (len1 > len2) {
		cout << s1 << "比" << s2 << " 的长度多" << len1 - len2 << endl;
	}
	else
		cout << s1 << "比" << s2 << " 的长度小" << len2 - len1 << endl;
	return 0;
}*/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char cont = 'y';
	string s, result;
	cout << "请输入一个字符串 " << endl;
	while (cin >> s) {
		if (result.size() == 0)
			result += s;
		else
			result = result + " " + s;
		cout << "是否继续(y or n)?" << endl;
		cin >> cont;
		if (cont == 'y' || cont == 'Y') {
			cout << "请输入一个字符串" << endl;
		}
		else break;

	}
	cout << "拼接后的字符串是：" << result << endl;
	return 0;
}*/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	//for (char &c : s)
	//{
	//	c = 'x';
	//}
	//int i = 0;
	//while(s[i] != '\0')
	//{
	//	s[i] = 'x';
	//	++i;
	//}cout << s << endl;
	for (int  i = 0; i < s.size(); i++)
	{
		s[i] = 'x';
	}
	cout << s << endl;
	return 0;
}*/
/*
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	for (auto c: s)
	{
		if (!ispunct(c)) {
			cout << c;
		}
	}
	cout << endl;
	for (int i = 0; i < s.size(); i++)
	{
		if (!ispunct(s[i])) {
			cout << s[i];
		}
	}
	cout << endl;
	unsigned i = 0;
	while (s[i] != '\0'){
		if (!ispunct(s[i])) {
			cout << s[i];
		}
		++i;
	}
	cout << endl;
	return 0;
}*/
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> vInt;
	string s;
	char cont = 'y';
	while (cin >> s)
	{
		vInt.push_back(s);
		cout << "are your continue?(yes or no)" << endl;
		cin >> cont;
		if (cont != 'y' && cont != 'Y')
		{
			break;
		}
	}
	for (auto mem:vInt) {
		cout << mem << " ";
	}
	cout << endl;
	return 0;
}
*/

/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4(10);
	vector<int> v5(10, 42);
	vector<string> v6(10);
	vector<string> v7(10, "hi");
	cout << "The number of V1 elements is ：" << v1.size() << endl;
	if (v1.size() > 0)
	{
		cout << "element of set v1 is: " << endl;
		for (auto i:v1)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "The number of V2 elements is ：" << v2.size() << endl;
	if (v2.size() > 0)
	{
		cout << "element of set v2 is: " << endl;
		for (auto i : v2)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "The number of V3 elements is ：" << v3.size() << endl;
	if (v3.size() > 0)
	{
		cout << "element of set v3 is: " << endl;
		for (auto i : v3)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "The number of V4 elements is ：" << v4.size() << endl;
	if (v4.size() > 0)
	{
		cout << "element of set v4 is: " << endl;
		for (auto i : v4)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	cout << "The number of V5 elements is ：" << v5.size() << endl;
	if (v5.size() > 0)
	{
		cout << "element of set v5 is: " << endl;
		for (auto i : v5)
		{
			cout << i << " ";
		}
		cout << endl;
	}


	cout << "The number of V6 elements is ：" << v6.size() << endl;
	if (v6.size() > 0)
	{
		cout << "element of set v6 is: " << endl;
		for (auto i : v6)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "The number of V7 elements is ：" << v7.size() << endl;
	if (v7.size() > 0)
	{
		cout << "element of set v7 is: " << endl;
		for (auto i : v7)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}*/
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> vString;
	string s;
	char cont = 'y';
	cout << "please enter the frist characters." << endl;
	while (cin >> s) {
		vString.push_back(s);
		cout << "Do you want to continue(y or n)?" << endl;
		cin >> cont;
		if (cont != 'y' && cont != 'Y'){
			break;
		}
		cout << "please enter the next characters." << endl;
	}
	cout << "transformed results is:" << endl;
	for (auto &mem :vString) {
		for (auto &c:mem) {
			c = toupper(c);
		}
		cout << mem << " ";
	}cout << endl;
	return 0;
}*/
/*
#include <iostream>
#include <vector>
using namespace	std;
int main()
{
	vector<int > vInt;
	int iVal;
	cout << "Please enter a set of data:" << endl;
	while (cin >> iVal)  //int type 
		vInt.push_back(iVal);

	if (vInt.size() == 0) {
		cout << "No element" << endl;
		return -1;
	}

		cout << "The value of Adjacent two item is : "; 
		for (decltype(vInt.size()) i = 0; i < vInt.size() -1 ;i+=2) { //use decltype function to do a type
			cout << vInt[i] + vInt[i + 1] << " ";
			if ((i + 2) % 10 == 0 ) {
				cout << endl;
			}
		}
		if (vInt.size() % 2 != 0)
			cout << vInt[vInt.size() - 1];
		return 0;
}
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> vInt;
	int iVal;
	cout << "Please enter a set of number：";
	while (cin >> iVal)
		vInt.push_back(iVal);
	if (vInt.size() == 0)
	{
		cout << "No element!" << endl;
		return -1;
	}

	cout << "首尾两项的和依次是：" << endl;
	for (decltype(vInt.size()) i  : vInt)
	{
		
	}


	for (decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++)
	{
		cout << vInt[i] + vInt[vInt.size() - i - 1] << " ";
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	if (vInt.size() %2 != 0)
	{
		cout << vInt[vInt.size() / 2];
	}
	return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int>v1;
	vector<int>v2(10);
	vector<int>v3(10,42);
	vector<int>v4{ 10 };
	vector<int>v5{10,42};
	vector<string>v6{ 10 };
	vector<string>v7{ 10,"bi" };
	cout << "v1" <<":"<< v1.size() << endl;
	if (v1.cbegin() != v1.cend()) {
		for (auto i = v1.cbegin(); i != v1.cend();i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << "v2" << ":" << v2.size() << endl;
	if (v2.cbegin() != v2.cend()) {
		for (auto i = v2.cbegin(); i != v2.cend(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << "v3" << ":" << v3.size() << endl;
	if (v3.cbegin() != v3.cend()) {
		for (auto i = v3.cbegin(); i != v3.cend(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << "v4" << ":" << v4.size() << endl;
	if (v4.cbegin() != v4.cend()) {
		for (auto i = v4.cbegin(); i != v4.cend(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << "v5" << ":" << v5.size() << endl;
	if (v5.cbegin() != v5.cend()) {
		for (auto i = v5.cbegin(); i != v5.cend(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << "v6" << ":" << v6.size() << endl;
	if (v6.cbegin() != v6.cend()) {
		for (auto i = v6.cbegin(); i != v6.cend(); i++) {
			cout << *i << " ";
		}
		cout << endl;
	}
	cout << "v7" << ":" << v7.size() << endl;
	if (v7.cbegin() != v7.cend()) {
		for (auto i = v7.cbegin(); i != v7.cend(); i++) {
			cout << *i << " ";
		}
		cout << endl;
		for (auto j : v7)
		{
			cout << j << " ";
		}

		cout << endl;
	}
}*/
/*
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() 
{
	vector<string> text;
	string s;
	while (getline(cin, s))
		text.push_back(s);

	for (auto it = text.begin(); it != text.end(); it++){
		for (auto it2 = it->begin(); it2 != it->end();it2++) {
			*it2 = toupper(*it2);
		}
		cout << *it;
	}
	return 0;
}*/
/*
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	vector<int> vInt;
	srand((unsigned) time(NULL));
	for (int i = 0 ; i < 10 ;i++ ){
		vInt.push_back(rand() % 1000);
	}
	cout << "随机生成的10个数字：" << endl;
	//利用常量迭代器读取原始数据
	for (auto it = vInt.cbegin(); it != vInt.cend();it++){
		cout << *it << " ";
	}
	cout << endl;

	cout << "翻倍后的十个数字为：" << endl;
	//利用常量迭代器输出
	for (auto it = vInt.begin(); it != vInt.end(); it++){
		cout << 2 * *it << " ";
	}
	cout << endl;
	return 0;
}
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vInt;
	int ival;
	cout << "请输入一组数字：" << endl;
	while (cin >> ival){
		vInt.push_back(ival);
	}
	
	if (vInt.cbegin() == vInt.cend())
	{
		cout << "没有任何元素！";
		return -1;
	}
	cout << "相邻的两项的和依次是：" << endl;
	for (auto it = vInt.cbegin(); it != vInt.cend() -1; ++it)
	{
		cout << *it + *(++it) << endl;
		if ((it - vInt.cbegin() + 1) % 10 == 0)
			cout << endl;
	}
	if (vInt.size() % 2 != 0)
		cout << *(vInt.cend() - 1);
	return 0;
}
*/
/*
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> vInt;
	int iVal;
	cout << "请输入一组数字" << endl;
	while (cin >> iVal)
		vInt.push_back(iVal);
	if (vInt.cbegin() == vInt.cend()){
		cout << "没有任何元素!" << endl;
		return -1;
	}
	cout << "首尾两项之和依次是：" << endl;
	auto beg = vInt.begin();
	auto end = vInt.end();
	for (auto it = beg; it != beg + (end - beg) / 2;it++) {
		//求首尾的元素和
		cout << (*it + *(beg + (end - it) - 1)) << " ";
		//每行输出5个数字
		if (it - beg + 1 % 5 == 0) {
			cout << endl;
		}
	}
	if (vInt.size() % 2 != 0)
		cout << *(beg + (end - beg) / 2);
	return 0;
}*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<unsigned> vUs(11);
	auto it = vUs.begin();
	int iVal;
	cout << "请输入一组成绩(0-100):" << endl;
	while (cin >> iVal) {
		if (iVal < 101)
			++*(it + iVal / 10);
	}
	cout << "你总计输入了： " << vUs.size() << "个成绩." << endl;
	cout << "各分数段的人数是（成绩由低到高）：" << endl;
	for ( it = vUs.begin(); it != vUs.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ia[10];
string sa[10];
int main()
{
	int ia2[10];
	string sa2[10];
	for (auto i:ia) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : ia2) {
		cout << i << " ";
	}
	cout << endl;
	for (auto s : sa) {
		cout << s << " ";
	}
	cout << endl;
	for (auto s : sa2) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i = 1;
	
	while (cin >> i) {
		try{
			if (i > 100 || i < 0)
				throw runtime_error("data rang must  refer to 0 - 100");
		}//try
		catch (runtime_error err){
			cout << err.what()
				<< "\nTry Again? Enter 'Y' or 'N'?" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;	//跳出循环
		}//catch
	}//while

	return 0;
}*/
/*
#include <iostream>
// int *const p1 = &i				//顶层const 作用于*p1 
//const int * const p1 = p2			//左面的是底层const 作用于p2， 右面的是顶层const作用于 *p1
//const int & p1 = p2				//引用const 都是底层const
//const int ci = 42					//顶层cost
using namespace std;

int call();

int main(int argc,char *argv[])
{	
	for (int  i = 0; i < 10; i++)
	{
		cout << call() << endl;
	}
	cout << endl;
	return 0;
}

int call()
{
	static size_t i = 0;
	cout << typeid(i).name() << " ";
	return ++i;
}*/
/*
#include<iostream>
#include<vector>

using namespace std;

class MyNum
{
public:
	MyNum(const std::initializer_list <int> &v ) {
		for (auto iVal:v) {
			vData.push_back(iVal);
		}
	}
	MyNum(int count,int elem) {
		for (size_t i = 0; i < count; i++)
		{
			vData.push_back(elem);
		}
	}
	void print() {
		for (const auto iVal:vData) {
			cout << iVal << " ";
		}
		cout << endl;
	}
private:
	vector<int> vData;
};

int main()
{
	MyNum num{ 0,1,2,3 };
	num.print();
	MyNum num1 = { 0,1,2,3 };
	num1.print();
	MyNum num2(10,42);
	num2.print();
	return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void error_msg(initializer_list<string> i1);

int main()
{
	error_msg({"string1","string2"});
	return 0;
}	

void error_msg(initializer_list<string> i1) {

	for (const auto it :i1)	{
		cout << it << " ";
	}
	cout << endl;
	for (auto it = i1.begin(); it != i1.end();it++) {
		cout << *it << " ";
	}
	cout << endl;

}*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int* return_test();
int main()
{
	cout << "0x" << return_test() << endl;
	return 0;
}

int* return_test()
{
	int i[5] = {1,2,3,4,5};
	int a;
	cout << "0x" << i << endl;
	return i;
}*/
/*
int odd[] = { 1,3,4,7,9 };
decltype(odd) &arrPtr() {
	return odd;
}

int add(int pre,...)
{
	va_list arg_ptr;
	int sum = 0;
	int nArgValue;
	sum += pre;
	va_start(arg_ptr, pre);
	do
	{
		nArgValue = va_arg(arg_ptr, int);
		sum += nArgValue;
	} while (nArgValue != 0);
	//自定义结束条件是输入参数为0
	va_end(arg_ptr);
	return sum;

}
int main()
{
	cout << add(1, 2, 3, 0) << endl;
	return 0;
}
*/
/*
vector<string> initializerList()
{
	return {"123","567"};
}
int main()
{
	vector<string> v1 = { "123","234" };
	cout << v1[0] << endl;
	cout << v1[1] << endl;
	cout << initializerList()[0] << endl;
	cout << initializerList()[1] << endl;
	return 0;
}*/
/*
class Sales_data
{
public:	
	friend istream& read(istream&, Sales_data &);
	friend ostream& print(ostream&, const Sales_data &);
public:
	Sales_data()=default;
	~Sales_data();
public:
	Sales_data& operator =(const Sales_data&);
	double isbn() { return BookNo; };
	Sales_data& combine(Sales_data &);
	void add();
private:
	double BookNo = 0.0;
};

Sales_data::~Sales_data()
{
}

istream& read(istream &in, Sales_data &temp) {
		in >> temp.BookNo;
		return in;

}
ostream& print(ostream &out, const Sales_data &temp) {
		out << temp.BookNo;
		return out;
}
Sales_data& Sales_data::combine(Sales_data &temp)
{
	BookNo += temp.BookNo;
	return *this;
}
Sales_data& Sales_data::operator =(const Sales_data &temp)
{	
	BookNo = temp.BookNo;
	return *this;
}
int main()
{
	size_t u = 10;
	Sales_data total;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin,trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				cout << "total = ";
				 print(cout, total) << endl;
				total = trans;
			}
		}
		cout << "最后一条交易记录!" << endl;
		print(cout, total) << endl;
	}
	else {
		cerr << "No data？！" << endl;
	}
	return 0;
}*/
/*
int main()
{
	const int cI = 10;
	const size_t array_size = cI;
	constexpr size_t size = 10;
	int aI[array_size];
	for (size_t i = 0; i < array_size; ++i)
	{
		aI[i] = i;
	}
	for (const auto &it:aI)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
int main()
{
	const int sz = 10;
	int a[sz], b[sz];
	for (size_t i = 0; i < sz; i++)
	{
		a[i] = i;
	}
	for (size_t j = 0; j < sz; j++)
	{
		b[j] = a[j];
	}
	for (const auto it : b){
		cout << it << " ";
	}
	cout << endl;

	for (const auto it : a){
		cout << it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
int main(int argc,char *argv[])
{
	const int sz = 10;
	vector<int> vInt, vInt2;
	for (size_t i = 0; i < sz; i++)
	{
		vInt.push_back(i);
	}
	for (size_t i = 0; i < sz; i++)
	{
		vInt2.push_back(vInt[i]);
	}
	for (const auto it : vInt) {
		cout << it << " ";
	}
	cout << endl;

	for (const auto it : vInt2) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
int main(int argc, char* argv[])
{
	const int sz = 10;
	int a[sz];
	for (size_t i = 0; i < sz; i++)
	{
		a[i] = i;
	}
	cout << "初始状态下的数组元素内容是：" << endl;
	for (const auto &it : a)
	{
		cout << it << " ";
	}

	cout << endl;

	int *p = begin(a);
	while (p != end(a))
	{
		*p = 0;
		++p;
	}
	cout << "数组元素内容是：" << endl;
	for (const auto &it : a)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
int main()
{
	const int sz = 5;
	int a[sz], b[sz], i;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < sz; i++){
		a[i] = rand() % 10;
	}
	cout << "请输入你猜测的数字：";
	int uVal;
	for (size_t i = 0; i < sz; i++)	{
		if (cin >> uVal){
			b[i] = uVal;
		}
	}
	cout << "系统生成的数据：";
	for (auto val : a) {
		cout << val << " ";
	}
	cout << endl;
	cout << "你的数据：";
	for (auto val : b) {
		cout << val << " ";
	}
	cout << endl;
	int *p = begin(a), *q = begin(b);
	while (p != end(a) && q!=end(b))
	{
		if (*p != *q) {
			cout << "你猜测的数据有误!" << endl;
			return -1;
		}
		++q;
		++p;
	}
	cout << "你猜测的数据相等!" << endl;
	return 0;
}
*/
/*
int main()
{
	const int sz = 5;
	int i;
	vector<int> a, b;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++){
		a.push_back(rand()%10);
	}
	cout << "请输入你猜测的五个数字:" << endl;
	int uVal;
	for (i = 0; i < sz; i++){
		if (cin >> uVal)
			b.push_back(uVal);
	}
	cout << "系统生成的数据为：" << endl;
	for (const auto iVal:a) 
		cout << iVal << " ";
	cout << endl;
	cout << "你输入的数据: ";
	for (const auto iVal : b)
		cout << iVal << " ";
	cout << endl;
	auto it1 = a.cbegin(), it2 = b.cbegin();
	while (it1 != a.cend() && it2 != b.cend()){
		if (*it1 != *it2) {
			cout << "猜测错误,两个vector不相等!" << endl;
			return -1;
		}
		++it1;
		++it2;
	}
	cout << "恭喜你猜对了!" << endl;
	return 0;
}*/
/*
int main(int argc,char *argv[])
{
	const char ca[] = {'h','e','l','l','o','\0'};
	const char *cb = ca;
	while (*cb) {
		cout << *cb << " ";
		++cb;
	}
	cout << endl;
	return 0;
}*/
/*
int main()
{
	string str1, str2;
	cout << "请输入两个字符串：" << endl;
	cin >> str1 >> str2;
	if (str1 > str2)
		cout << "第一个字符串大于第二个。" << endl;
	else if (str1 < str2)
		cout << "第一个字符串小于第二个." << endl;
	else cout << "两个字符串相等." << endl;
	return 0;
}*/
/*
int main()
{
	const int Size = 80;
	char str1[Size], str2[Size];
	cin >> str1 >> str2;
	int result = strcmp(str1,str2);
	switch (result)
	{
	case 1:cout << "str1 > str2" << endl; break;
	case 0:cout << "str1 = str2" << endl; break;
	case -1:cout << "str1 < str2" << endl; break;
	default:cout << "未定义的结果！" << endl; break;
	}
	return 0;
}*/
/*
int main()
{
	char str1[] = "Welcome to";
	char str2[] = "c++ family!";
	const int lenght = 50;
	char result[lenght];
	strcpy_s(result, str1);
	strcat_s(result, str2);
	cout << result << endl;
	return 0;
}*/
/*
int main()
{
	const int sz = 10;
	int a[sz];
	srand((unsigned)time(NULL));
	cout << "数组的内容:" << endl;
	//利用范围for循环遍历数组的每个元素。
	for (auto &val:a)
	{
		val = rand() % 100; //0-99之间的数字
		cout << val << " ";	//beuteful 这个666
	}
	vector<int>vInt(begin(a), end(a)); //利用数组初始化vector  begin(a) ,end(a).
	cout << "Vecotr的内容是：" << endl;
	for (auto val :vInt) {
		cout << val << " ";
	}
	int iA;
	cout << endl;
	return 0;
}
*/
/*
int main()
{
	const int sz = 10;
	vector<int>vInt;
	srand((unsigned)time(NULL));
	cout << "vector 的内容是:" << endl;
	for (int i = 0; i < sz;i++) {
		vInt.push_back(rand()%10);
		cout << vInt[i] << " ";
	}
	cout << endl;
	int ia[sz];
	auto it = vInt.begin();
	for (auto &iVal:ia)
	{
		iVal = *it;
		++it;
		cout << iVal << " ";
	}
	cout << endl;
	return 0;
}*/
/*
int main()
{
	cout << "请输入交易记录(ISBN,销售价，原价，实际售价)：" << endl;
	Sales_data total;
	if(cin >> total){
		Sales_data trans;
		while (cin >> trans){
			if(total.isbn() == trans.isbn()){
				total += trans;
			}//if
			else {
				cout << total << endl;
				total = trans;
			}
		}//while
		cout << total << endl;
	}//if
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
	}
	*/
/*


class Person {

friend std::istream& operator >>(std::istream &, Person &);

private:
	string strName = "john";
	string strAddress;
public:
	Person() = default;
	Person(const string &name, const string &address) {
		strName = name;
		strAddress = address;
	}
	Person(istream &is) { is >> *this; }
public:
	string getName()const { return strName; }
	string getAddress() const { return strAddress; }


};

std::istream& operator >>(std::istream&in, Person &s)
{
	in >> s.strName >> s.strAddress;
	return in;
}

int main()
{
	Person john;
	cout << john.getName() << endl;
	Person zhou(cin);
	cout << zhou.getName() << endl;
	cout << zhou.getAddress() << endl;
	cin >> zhou;
	cout << zhou.getName() << endl;
	cout << zhou.getAddress() << endl;
	return 0;
}*/
/*
class Screen {
private:
	//length height width 
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default;
	Screen(unsigned ht, unsigned wd) :height(ht), width(wd),contents(ht * wd,' ') {} //字符串的构造函数
	Screen(unsigned ht, unsigned wd, char c) :height(ht), width(wd), contents(ht * wd,c) {}
public:
	Screen& move(const unsigned r, const unsigned c) {
		cursor = r * width + c;
		return *this;
	}
	Screen& set(const char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen& set(const unsigned r, const unsigned c, const char ch)
	{
		contents[r * width + c] = ch;
		return *this;
	}
	void display()
	{
		cout << contents << endl;
	}
};

int main() 
{
	Screen myScreen(5,5,'x');
	myScreen.move(4, 0).set('#').display();
	myScreen.display();
	myScreen.set(4,0,'x').display();
	myScreen.display();
}*/ 
/*
class Window_mgr
{
public:
	void clear();
};
class  Screen
{
	friend void Window_mgr::clear();
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	string contents;
public:
	Screen() = default;
	Screen(unsigned ht, unsigned wd, char c) 
		: height(ht), width(wd), contents(ht * wd, c) { }
};
void Window_mgr::clear()
{
	Screen myScreen(10, 10, 'x');
	cout << "清理之前的内容是:" << endl;
	cout << myScreen.contents << endl;
	myScreen.contents = "";
	cout << "清理之后的内容是:" << endl;
	cout << myScreen.contents << endl;
}
int main()
{
	Window_mgr w;
	w.clear();//成员函数别忘加（）括号
	return 0;
}*/
/*
typedef string Type;
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal() { return 3.0; }
private:
	int val;
};

Exercise::Type Exercise::setVal(Exercise:: Type parm)
{
	val = parm +static_cast<int>( Exercise::initVal());
	return val;
}
int main()
{
	Exercise exe;
	cout << exe.setVal(50) << endl;
	return 0;
}*/
/*
struct X
{
	X(int i,int j):base(i),rem(base%j){}
	int rem, base;
};
int main()
{
	
	return 0;
}*/

/*
class Sales_data
{
	friend istream& read(istream &is, Sales_data &item);
	friend ostream& print(ostream &os, const Sales_data &item);
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
public:
	explicit Sales_data(const string &book, unsigned num, double sellp, double salep)
		:bookNo(book), units_sold(num), sellingprice(sellp), saleprice(salep)
	{//该构造函数接受书号，销售量，原价，实际售价四个信息!
		if (sellingprice)
			discount = saleprice / sellingprice;
		cout << "该构造函数接受书号，销售量，原价，实际售价四个信息!" << endl;
	}
	explicit Sales_data():Sales_data("", 0, 0, 0)
	{//该构造函数无需接受任何信息
		cout << "该构造函数无需接受任何信息！" << endl;
	}
	explicit Sales_data(const string &book) :Sales_data(book, 0, 0, 0)
	{//该构造函数接受书号信息
		cout << "该构造函数接受书号信息!" << endl;
	}
	explicit Sales_data(istream &is) :Sales_data()
	{//该构造函数接受用户输入的信息
		read(is, *this);
		cout << "该构造函数接受用户输入的信息！" << endl;
	}
public:
	Sales_data& combine(Sales_data);
	Sales_data& combine(Sales_data&);
	Sales_data& combine(const Sales_data&)const;
};
istream& read(istream &is,Sales_data &item)
{

	is >> item.bookNo >> item.units_sold >> item.sellingprice
		>> item.saleprice;
	return is;
}
ostream& print(ostream &os, const Sales_data &item)
{
	os << item.bookNo <<" "<< item.units_sold <<" "<< item.sellingprice
		<<" "<< item.saleprice <<" " <<item.discount;
	return os;
}
Sales_data& Sales_data:: combine(Sales_data item)
{
	bookNo = item.bookNo;
	return *this;
}
Sales_data& Sales_data::combine(Sales_data& item)
{
	bookNo = item.bookNo;
	return *this;
}
Sales_data &combine(const Sales_data& item)const
{
	bookNo = item.bookNo;
	return *this;
}


int main()
{
	string null_isbn("9-9999-99999-9");
	Sales_data item1(null_isbn);
	Sales_data item2("9-9999-99999-9");
	return 0;
}*/
/*
class Person
{
private:
	string strName;
	double dAmount = 0.0;
	static double dRate;
public:

};*/
/*
istream& f(istream &in)
{
	int v;
	while (in >> v,!in.eof())
	{
		if (in.bad())
			throw runtime_error("IO 流错误");
		if (in.fail()){
			cerr << "数据错误，请重试：" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	in.clear();
	return in;
}

int main()
{
	cout << "请输入一些整数，按Ctrl+Z结束" << endl;
	f(cin);
	return 0;
}*/
/*
int main()
{
	ifstream in("data");

	if (!in) {
	cerr << "无法打开输入文件!" << endl;
	return -1;
	}

	string line;
	vector <string>words;

	while (getline(in, line)) {
	words.push_back(line);
	}

	in.close();
	vector<string>::const_iterator it = words.begin();

	while (it != words.end()) {
	cout << *it << endl;
	++it;
	}
	return 0;
}*/
/*
int main(int argc,char *argv[])
{
	if (argc < 2) {
		cerr << "请给出文件名!" << endl;
		return -1;
	}
	ifstream in(argv[2]);
	if (!in) {
		cerr << "无法打开输入文件!" << endl;
		return -1;
	}

	Sales_data total;
	if (in >> total){
		Sales_data trans;
		while (in >> trans){
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				cout << total << endl;
				total = trans;
			}
		}//while
		cout << total << endl;
	}//if
	else {
		cerr << "没有数据！" << endl;
	}
	return 0;
}*/
/*
int main(int argc, char *argv[])
{
	if (argc < 2) {
		cerr << "请给出文件名!" << endl;
		return -1;
	}
	for (size_t i = 0; i <= 2; i++)
	{
		cout << argv[i] << " ";
	}
	cout << endl;
	ifstream in(argv[2]);
	if (!in) {
		cerr << "无法打开输入文件！" << endl;
		return -1;
	}
	Sales_data total;
	if (in >> total) {
		Sales_data trans;
		while (in >> trans) {
			if (total.isbn() == trans.isbn()) {
				total += trans;
			}
			else {
				cout << total << endl;
				total = trans;
			}
		}//while
	}//if
	else {
		cerr << "没有数据!" << endl;
	}
	return 0;
}*/
/*
int main(int argc, char *argv[])
{
	if (argc < 4) {
		cerr << "请给出输入，输出的文件名！" << endl;
		return -1;
	}
	ifstream in(argv[2]);
	if (!in) {
		cerr << "无法打开输入文件！" << endl;
		return -1;
	}
	ofstream out(argv[2],ofstream::app);
	if (!out) {
		cerr << "无法打开输出文件!" << endl;
		return -1;
	}
	Sales_data total;
	if (in >> total) {
		Sales_data trans;
		while (in >> trans) {
			if (total.isbn() == trans.isbn())
				total += trans;
			else {
				out << total << endl;
				cout << total << endl;
				total = trans;
			}
		}//while
		out << total << endl;
		cout << total << endl;
	}//if
	else {
		cerr << "没有数据！" << endl;
	}
	in.close();
	out.close();
	return 0;
}*//*
istringstream & f(istringstream & in)
{
	string v;
	while (in >> v, !in.eof()) {
		if (in.bad())
			throw runtime_error("IO流错误!");
		if (in.fail()) {
			cerr << "数据错误，请重试!" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}
		cout << v << " ";
	}
	cout << endl;
	in.clear();
	return in;
}
int main()
{
	ostringstream msg;
	msg << "c++ primer 第五版!" << endl;
	istringstream in(msg.str());
	f(in);
	return 0;
}*/
/*
int main()
{
	ifstream in("data.txt", ifstream::in);
	if (!in) {
		cerr << "无法打开文件！" << endl;
		return -1;
	}
	string line;
	vector<string> words;
	while (getline(in, line)) {
		words.push_back(line);
	}
	in.close();

	vector<string>::const_iterator it = words.begin();
	while (it != words.end()) {
		istringstream line_str(*it);
		string word;
		while (line_str >> word)
			cout << word << " ";
		cout << endl;
		++it;
	}
	return 0;
}
*/

/*
struct PersonInfo {
	friend ostream & operator << (ostream &,PersonInfo &);
	string name;
	vector<string>phones;
};

ostream & operator << (ostream &out, const PersonInfo &item)
{
	out << item.name << " ";
	vector<string>::const_iterator it = item.phones.cbegin();
	while (it != item.phones.cend()) {
		out << *it << " ";
		++it;
	}
	return out;
}

int main()
{
	string line, word;
	vector<PersonInfo>people;
	istringstream record;

	while (getline(cin, line)) {
		PersonInfo personlInfo;
		record.clear();
		record.str(line);
		record >> personlInfo.name;
		while (record >> word){
			personlInfo.phones.push_back(word);
		}
		people.push_back(personlInfo);
	}
	vector<PersonInfo>::const_iterator it = people.cbegin();
	while (it != people.cend()) {
		cout << *it << endl;
		++it;
	
	}
	return 0;
}
*/
/*
int main()
{
	ifstream in("data.txt", ifstream::in);
	if (!in) {
		cerr << "无法打开文件!" << endl;
		return -1;
	}
	
	string line;
	vector<string>words;
	while (getline(in, line)) {
		words.push_back(line);
	}
	in.close();

	vector<string>::const_iterator it = words.cbegin();
	while (it != words.cend()) {
		istringstream line_str(*it);
		string word;
		while (line_str >> word) 
			cout << word << " ";
		cout << endl;
		++it;			
	}
	return 0;
}*/
/*
struct PersonInfo {
	friend ostream & operator << (ostream &, PersonInfo &);
	string name;
	vector<string>phones;
};

ostream & operator << (ostream &out, const PersonInfo &item)
{
	out << item.name << " ";
	vector<string>::const_iterator it = item.phones.cbegin();
	while (it != item.phones.cend()) {
		out << *it << " ";
		++it;
	}
	return out;
}

int main()
{
	ifstream in("data.txt",istream::in);
	if (!in) {
		cerr << "无法打开文件!" << endl;
		return -1;
	}

	string line, word;
	vector<PersonInfo>people;
	istringstream record;

	while (getline(in, line)) {
		PersonInfo personlInfo;
		record.clear();
		record.str(line);
		record >> personlInfo.name;
		while (record >> word) {
			personlInfo.phones.push_back(word);
		}
		people.push_back(personlInfo);
	}
	in.close();

	vector<PersonInfo>::const_iterator it = people.cbegin();
	while (it != people.cend()) {
		cout << *it << endl;
		++it;
	}
	return 0;
}*/
/*
vector<int>::iterator search_vec(vector<int>::iterator beg,
		vector<int>::iterator end,int val);
int main()
{
	vector<int> iList = { 1,2,3,4,5,6,7 };
	cout << search_vec(iList.begin(), iList.end(), 3) - iList.begin() << endl;
	cout << search_vec(iList.begin(), iList.end(), 8) - iList.begin() << endl;
	return 0;
}

vector<int>::iterator search_vec(vector<int>::iterator beg,
	vector<int>::iterator end, int val)
{
	while (beg != end) {
		if (*beg == val) {
			return beg;
		}
		++beg;
	}
	return end;
}*/
/*
int main()
{
	list<int> iList = { 1,2,3,4,5,6,7 };
	vector<int> iVec = { 7,6,5,4,3,2,1 };
	// vector<double>dVec(iList);'
	vector<double>dVec1(iList.begin(),iList.end());
	//vector<double>dVec2(iVec);
	vector<double>dVec3(iVec.begin(),iVec.end());
	cout << dVec1.capacity() << " " << dVec1.size() << " "
		<< dVec1[0] << " " << dVec1[dVec1.size() - 1] << endl;
	cout << dVec3.capacity() << " " << dVec3.size() << " "
		<< dVec3[0] << " " << dVec3[dVec3.size() - 1] << endl;
	return 0;
}*/
/*
int main()
{
	list<char *> sList = { "hello","world","!" };
	vector<string> sVec;
	//sVec = sList;
	sVec.assign(sList.begin(), sList.end());
	cout << sVec.capacity() << " " << sVec.size() << " "
		<< sVec[0] << " " << sVec[sVec.size() - 1] << endl;
	return 0;
}*/
/*
bool l_v_equal(vector<int> &ivec, list<int> &ilist);
int main()
{
	vector<int> ivec = { 1,2,3,4,5,6,7 };
	list<int> ilist = { 1,2,3,4,5,6,7 };
	list<int> ilist1 = { 1,2,3,4,5 };
	list<int> ilist2 = { 1,2,3,4,5,6,8 };
	list<int> ilist3 = { 1,2,3,4,5,7,6 };
	cout << l_v_equal(ivec, ilist) << endl;
	cout << l_v_equal(ivec, ilist1) << endl;
	cout << l_v_equal(ivec, ilist2) << endl;
	cout << l_v_equal(ivec, ilist3) << endl;
	ivec1.push_back(8);
	ivec1.pop_back();
	cout << ivec1.capacity() << " " << ivec1.size() << endl;
	cout << (ivec == ivec1) << endl;
	return 0;
}
bool l_v_equal(vector<int> &ivec, list<int> &ilist)
{
	if (ilist.size() != ivec.size())
		return false;
	auto lb = ilist.cbegin();
	auto le = ilist.cend();
	auto vb = ivec.cbegin();
	while (lb != le) {
		if (*lb != *vb)return false;
		++lb;
		++vb;
	}
	return true;
}*/
/*
int main()
{
	deque<string> sd;
	string word;
	while (cin >> word)
		sd.push_back(word);
	sd.push_front("aaaaaaaaa");
	for (auto sit = sd.cbegin(); 
		sit != sd.cend(); 
		++sit) {
		cout << *sit << endl;
	}
	return 0;
}*/
/*
int main()
{
	list<string> sl;
	string word;
	while (cin >> word)
		sl.push_back(word);
	for (auto sit = sl.cbegin(); sit != sl.cend();++sit) {
		cout << *sit << endl;
	}
	return 0;
}*/
/*
int main()
{
	list<int> il;
	int ival;
	while (cin >> ival)
		il.push_back(ival);
	deque<int> id;
	deque<int> id1;
	bool flage = true;
	for (auto it = il.cbegin(); it != il.cend(); ++it) {
		if (flage)id.push_back(*it);
		else id1.push_back(*it);
		flage = !flage;
	}
	for (auto it = il.cbegin(); it != il.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = id.cbegin(); it != id.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = id1.cbegin(); it != id1.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
///与运算 判断奇偶 ///
/// %2 模2 判断奇偶///
int main()
{
	list<int> il = {0,1,2,3,4,5,6,7,8,9,10};
	deque<int> id_odd;
	deque<int> id_even;
	
	for (auto it = il.cbegin(); it != il.cend(); ++it) {
		if (*it & 1)id_odd.push_back(*it);
		else id_even.push_back(*it);
	}
	for (auto it = il.cbegin(); it != il.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "奇数为：";
	for (auto it = id_odd.cbegin(); it != id_odd.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "偶数为：";
	for (auto it = id_even.cbegin(); it != id_even.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}*/
/*
int main()
{
	vector<string>svec;
	string word;


	auto iter = svec.begin();
	while (cin >> word) {
		iter = svec.insert(iter, word);
	}


	for (auto iter = svec.cbegin(); 
		iter != svec.cend(); 
		++iter) 
		cout << *iter << endl;


	return 0;
}*/


////////////////////////////////////////////////////12-4///////////////////////////////////////
/*
int main()
{
	vector<int> iv = { 1,1,2,1 };
	int some_val = 1;

	vector<int>::iterator iter = iv.begin();
	int org_size = iv.size(), new_ele = 0;
	
	///通过 (iv.begin() + org_size / 2 + new_ele)每次都指向原来的中间位置
	while (iter != (iv.begin() + org_size / 2 + new_ele))
		if (*iter == some_val) {
			iter = iv.insert(iter, 2 * some_val);
			++iter;
			++iter;
			++new_ele;
		}
		else 
			++iter;
	
	for (iter = iv.begin(); 
		iter != iv.end();
		iter++) {
		cout << *iter << endl;
	}
	return 0;
}*/
/*
int main()
{
	vector<int> iv = { 1,1,1,1,1 };
	int some_val = 1;
	vector<int>::iterator iter = iv.begin();
	int org_size = iv.size();
	int i = 0;


	while (i <= org_size / 2){
		if (*iter == some_val){
			iter = iv.insert(iter,2*some_val);
			iter++;iter++;
		}
		else iter++;
		i++;
	}


	for (iter = iv.begin();
		iter != iv.end();
		iter++) {
		cout << *iter << endl;
	}
	return 0;
}*/
/*
int main()
{
	vector<int> iv;
	if(!iv.empty()){
	cout << iv.at(0) << endl;
	cout << iv[0] << endl;
	cout << iv.front() << endl;
	cout << *(iv.begin()) << endl;
	}
	return 0;
}*/
/*
int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int>iv;
	list<int>il;

	iv.assign(ia, ia + 11);
	il.assign(ia, ia + 11);

	vector<int>::iterator iiv = iv.begin();
	while (iiv != iv.end())
		if (!(*iiv & 1))
			iiv = iv.erase(iiv);
		else 
			iiv++;
	
	list<int>::iterator iil = il.begin();
	while (iil != il.end())
		if (*iil & 1)
			iil = il.erase(iil);
		else
			iil++;


	for (iiv = iv.begin(); 
		iiv != iv.end();
		iiv++)
		cout << *iiv << " ";
	cout << endl;

	for (iil = il.begin(); 
		iil != il.end(); 
		iil++)
		cout << *iil << " ";
	cout << endl;
	
	return 0;
}
*/
/*
int main() 
{
	forward_list<int> iflst = { 1,2,3,4,5,6,7,8 };

	auto prev = iflst.before_begin();
	auto curr = iflst.begin();

	while (curr != iflst.end())
		if (*curr & 1)
			curr = iflst.erase_after(prev);
		else {
			prev = curr;
			curr++;
		}
	
	for (curr = iflst.begin(); 
		curr != iflst.end();
		curr++)
		cout << *curr << " ";
	cout << endl;
	return 0;
}*/
/*
void test_and_insert(forward_list<string> &sflst, 
const string &s1, const string &s2);


int main()
{
	forward_list<string> sflst = { "Hello","!","world","!" };

	test_and_insert(sflst,"Hello","你好");

	for (auto curr = sflst.cbegin(); 
		curr != sflst.cend();
		curr++)
		cout << *curr << " ";
	cout << endl;


	test_and_insert(sflst, "!", "?");
	for (auto curr = sflst.cbegin();
		curr != sflst.cend();
		curr++)
		cout << *curr << " ";
	cout << endl;


	test_and_insert(sflst, "Bye", "再见");
	for (auto curr = sflst.cbegin();
		curr != sflst.cend();
		curr++)
		cout << *curr << " ";
	cout << endl;

	return 0;
}


void test_and_insert(forward_list<string> &sflst,
const string &s1, const string &s2)
{
	auto prev = sflst.before_begin();
	auto curr = sflst.begin();
	bool inserted = false;

	while (curr != sflst.end()) {
		if (*curr == s1){
			curr = sflst.insert_after(curr,s2);
			inserted = true;
		}
		prev = curr;
		curr++;
	}

	if (!inserted) {
		sflst.insert_after(prev, s2);
	}
	
}*/
/*

int main()
{
	list<int> ilst = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = ilst.begin();

	while (curr != ilst.end()) {
		if (*curr & 1) {
			curr = ilst.insert(curr, *curr);
			curr++, curr++;
		}
		else
			curr = ilst.erase(curr);
	}

	for (auto curr = ilst.cbegin();
		curr != ilst.cend();curr++)
		cout << *curr << " ";
	cout << endl;
	return 0;
}*/
/*
int main()
{
	forward_list<int> iflst = { 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int>::iterator prev = iflst.before_begin();
	forward_list<int>::iterator curr = iflst.begin();

	while (curr != iflst.end()) {
		if (*curr & 1) {
			curr = iflst.insert_after(curr, *curr);
			prev = curr;
			curr++;
		}
		else
			curr = iflst.erase_after(prev);
	}

	for (auto curr = iflst.cbegin();
		curr != iflst.cend(); curr++)
		cout << *curr << " ";
	cout << endl;
	return 0;
}*/
/*
int main()
{
	vector<int> vi = { 1,2,3,4,5,6,7,8,9 };
	vector<int>::iterator iter = vi.begin();
	string tmp;

	while (iter != vi.end()) {

		if (*iter % 2){
			iter = vi.insert(iter,*iter);
			iter++; 
		}

		for (vector<int>::iterator begin = vi.begin(); begin != vi.end(); begin++)
			cout << *begin << " ";
		cout << endl;
		cin >> tmp;
		iter++;
	}
	
	return 0;
}*/
/*
int main()
{
	vector<int>vi;
	int s, c;

	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数:" << vi.size() << endl;

	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数:" << vi.size() << endl;

	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数:" << vi.size() << endl;

	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数:" << vi.size() << endl;

	for (s = vi.size(), c = vi.capacity(); s <= c; s++)
		vi.push_back(1);
	cout << "空间：" << vi.capacity() << "元素数:" << vi.size() << endl;

	return 0;
}*/
/*
int main()
{
	vector<int>ivec;
	cout << "ivec:size:  " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	
	for (vector<int>::size_type ix = 0; ix != 24; ix++)
		ivec.push_back(ix);

	cout << "after:" << endl;
	cout << "ivec:size:  " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.reserve(50);
	cout << "ReserveAfter:" << endl;
	cout << "ivec:size:  " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	while (ivec.size() != ivec.capacity()) {
		ivec.push_back(0);
	}
	cout << "push_back_Reserve_After:" << endl;
	cout << "ivec:size:  " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.push_back(0);
	cout << "aegin_push_back_Reserve_After:" << endl;
	cout << "ivec:size:  " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.shrink_to_fit();
	cout << "ivec.shrink_to_fit() :" << endl;
	cout << "ivec:size:  " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;
	return 0;
}
*/
/*
int main()
{
	vector<char> vc = {'H','e','l','l','o'};
	string s(vc.data(),vc.size());
	 
	cout << s << endl;
	return 0;
}
*/
/*
int main()
{
	vector<char> vc = { 'H','e','l','l','o' };
	string s(vc.data(), vc.size());
	cout << s << endl;

	return 0;
}*/
/*
void input_string(string &s);

int main()
{
	string s;
	input_string(s);
	cout << s << endl;

	return 0;
}

void input_string(string &s)
{
	s.reserve(100);
	char c;
	while (cin >> c)
		s.push_back(c);
}*/

/*
void replace_string(string &s,
	const string &oldVal, const string &newVal);

int main()
{
	string s = "tho thru tuo!";
	replace_string(s, "thru", "through");
	cout << s << endl;

	replace_string(s, "tho", "though");
	cout << s << endl;

	replace_string(s, "though", "");
	cout << s << endl;

	return 0;
}
void replace_string(string &s,
	const string &oldVal, const string &newVal)
{
	auto l = oldVal.size();
	if (!l)  //查找的字段为空
		return;

	auto iter = s.begin();
	while (iter <= s.end() - 1) {  //末尾少于oldVAl长度的部分无需检查
		auto iter1 = iter;
		auto iter2 = oldVal.begin();


		//s中iter开始的字串必须每个字符都与oldVal相同
		while (iter2 != oldVal.end() && *iter1 == *iter2) {
			iter1++; iter2++;
		}

		if (iter2 == oldVal.end()) {	//字符串耗尽 -字符串相等
			iter = s.erase(iter, iter1);	//删除s中与oldVal相等的部分

			if (newVal.size()) {	//替换字串是否为空
				iter2 = newVal.end();	//由后到前逐个插入newVal中的字符
				do {
					iter2--;
					iter = s.insert(iter, *iter2);	//
				} while (iter2 > newVal.begin());

			}
			iter += newVal.size(); //迭代器移动到新内容之后
		}else iter++;

	}//while

}*/
/*
void replace_string(string &s,
	const string &oldVal, const string &newVal);

int main()
{
	string s = "tho thru tho!";

	replace_string(s,"thru","though");
	cout << s << endl;


	replace_string(s, "tho", "though");
	cout << s << endl;


	replace_string(s, "though", "");
	cout << s << endl;

	return 0;
}


void replace_string(string &s,
	const string &oldVal, const string &newVal)
{
	if (!oldVal.size()) 
		return;

	string::const_iterator iter = s.begin();
	while (iter <= s.end() - 1)
	{
		string::const_iterator iter1 = iter;
		string::const_iterator iter2 = oldVal.begin();

		while (iter2 != oldVal.end() && *iter1 == *iter2) {
			iter1++; iter2++;
		}


		if (iter2 == oldVal.end()) {
			iter = s.erase(iter,iter1);


			if(newVal.size()){
		
				iter2 = newVal.end();
				do {
					iter2--;
					iter = s.insert(iter,*iter2);

				} while (iter2 > newVal.begin());
			}iter += newVal.size();

		}else iter++;
	}//while



}*/
/*
void replace_string(string &s,
	const string &oldVal, const string &newVal);

int main()
{

	string s = "btho thru tho!";

	replace_string(s, "thru", "through");
	cout << s << endl;


	replace_string(s, "tho", "though");
	cout << s << endl;


	replace_string(s, "through", "");
	cout << s << endl;

	return 0;
}


void replace_string(string &s,
	const string &oldVal, const string &newVal)
{
	int p = 0; 
	while ((p = s.find(oldVal, p)) != string::npos) //在s中查找oldVal
	{
		s.replace(p, oldVal.size(), newVal);
		p += newVal.size();
	}
}
*/
/*
void name_string(string &name, 
	const string &prefix, const string &suffix)
{
	//name.insert(name.begin(), 1, ' ');
	name.insert(name.begin(), prefix.begin(), prefix.end());
	name.append(" ");
	name.append(suffix.begin(), suffix.end());

}

int main()
{
	string s = "James Bond";
	name_string(s, "Mr.", "II");
	cout << s << endl;

	s = "M";
	name_string(s, "Mrs.", "III");
	cout << s << endl;
	return 0;
}
*/
/*
void name_string(string &name, const string &prefix, const string &suffix)
{
	name.insert(0, " ");
	name.insert(0, prefix);
	name.insert(name.size(), " ");
	name.insert(name.size(), suffix);
}


int main()
{
	string s = "James Bond";
	name_string(s, "Mr.", "II");
	cout << s << endl;

	s = "M";
	name_string(s, "Mrs.", "III");
	cout << s << endl;
	return 0;
}
*/
/*
void find_char(string &s, const string &chars)
{
	cout << "在" << s << "中查找"
		<< chars << "中字符" << endl;

	string::size_type pos = 0;
	while ((pos = s.find_first_of(chars, pos)) !=
		string::npos){//找到字符
		cout << "pos:" << pos << ",char :" 
			<< s[pos] << endl;	
		pos++;
	}
}

int main()
{
	string s = "ab2c3d7R4E6";
	cout << "查找所有字母" << endl;
	find_char(s, "abcdefghijklmnopqrstuvwxyz"\
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ");

	return 0;
}*/
/*

void find_not_char(string &s, const string &chars)
{
	cout << "在" << s << "中查找不在"
		<< chars << "中字符" << endl;
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(chars, pos)) !=
		string::npos) {
		cout << "pos:" << pos << "\tchar:" 
			<< s[pos] << endl;
		pos++;
	}

}

int main()
{
	string s = "ab2c3d7R4E6";
	cout << "查找所有数字" << endl;
	find_not_char(s, "abcdefghijklmnopqrstuvwxyz"\
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	return 0;
}*/

/*
void finnd_longest_word(istringstream &in)
{
	string s, longest_word;
	int max_length = 0;
	
	while (in >> s) {
		if (s.find_first_of("dbfghjklpqty")
			!= string::npos) continue;
		cout << s << " ";

		if (max_length < s.size()) {
			max_length = s.size();
			longest_word = s;
		}
		cout << endl << "最长字符串： " << longest_word << endl;
	}
}

int main()
{
	istringstream in;
	string line;
	getline(cin,line);
	in.str(line);

	finnd_longest_word(in);

		return 0;
}*/
/*
struct PersonInfo {
	string name;
	vector<string>phones;
};

string format(const string &s) {
	return s;
}

bool valid(const string &s)
{
	return true;
}

int main()
{
	string line, word;
	vector<PersonInfo> people;
	istringstream record;
	
	while (getline(cin, line)) {
		PersonInfo info;
		record.clear();
		record.str(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	ostringstream os;
	for (const auto &entry : people) {
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones) {
			if (!valid(nums))
				badNums << " " << nums;
			else{
				formatted << " " << format(nums);
			}
		}//for entry.phones
		if (badNums.str().empty())
			os << entry.name << " "
			<< formatted.str() << endl;
		else
			cerr << "input error: " << entry.name
			<< "invalid num ber(s)  " << badNums.str() << endl;
	}//for people
	cout << os.str() << endl;
	return 0;

}
*/
/*
int main()
{	
	vector <string>vs = { "123","456","-789" };
	int sum = 0;

	//for(auto iter = vs.begin();iter!=vs.end();iter++){
		//sum += stoi(*iter);
	//}sum += stoi(*(siter));
	for (const  auto &siter : vs) {
		cout << siter << " ";
		sum += stoi(siter);
	}
	cout << endl << "和:" << sum << endl;

	return 0;
}
*/
/*
int main()
{
	vector<string> vs = { "12.3","-4.56","+7.8e-2" };
	float sum = 0;

	for (const auto & sit : vs) {
		sum += stof(sit);
	}
	cout << "和:" << sum << endl;
	return 0;
	}*/
/*
int main()
{
	vector<int> vi;
	int val;
	while (cin >> val)
		vi.push_back(val);
	cout << "请输入你要搜索的整数:";
	cin.clear();
	cin >> val;
	cout << "序列中包含" << count(vi.begin(), vi.end(), val)
		<< "个" << val << endl;;
	return 0;
}*/
/*
int main()
{
	list<string> sl;
	string val;
	while (cin >> val)
		sl.push_back(val);
	cin.clear();
	cin >> val;
	cout << "序列中包含" << count(sl.begin(), sl.end(), val)
		<< "个" << val << endl;;
	return 0;
}*/
/*
int main() {
	vector<string> vi;
	string val;
	while (cin >> val)
		vi.push_back(val);
	cout << "序列中整数的个数之和为:" << accumulate(vi.begin(), vi.end(), string(" ")) << endl;

	return 0;
}*/
/*
int main()
{
	char *p[] = { "Hello","World","!" };
//	char *q[] = { strdup(p[0]), strdup(p[1]), strdup(p[2]) };
	char *r[] = { p[0],p[1],p[2] };
//	cout << equal(begin(p), end(p), q) << endl;
	cout << equal(begin(p), end(p), r) << endl;
	return 0;
}*/

/*
int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (in) {
		cout << "打开文件失败!" << endl;
		exit(1);
	}

	vector<char> vi;
	char val;
	while (cin >> val) {
		vi.push_back(val);
		cout << val << " ";
	}
	cout << endl;

	fill_n(vi.begin(), vi.size(), 0);
	for (auto iter = vi.begin(); iter != vi.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}*/
/*
int main()
{
	list<int> lst;
	vector<int> vec;
	int val;

	while (cin >> val)
		lst.push_back(val);

	copy(lst.begin(), lst.end(), back_inserter(vec));

	cout << equal(lst.begin(), lst.end(), vec.begin()) << endl;
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}*/
/*
int main()
{
	vector<int> vec;
	vec.reserve(10);

	fill_n(back_inserter(vec), 10, 0);

	for (auto iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}*/
/*

inline void output_words(vector<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void elimDups(vector<string> &words)
{
	output_words(words);

	sort(words.begin(), words.end());
	output_words(words);

	auto end_unique = unique(words.begin(), words.end());
	output_words(words);

	words.erase(end_unique, words.end());
	output_words(words);
}
int main()
{
	vector<string>words;
	string word;
	while (cin >> word)
		words.push_back(word);
	elimDups(words);

	return 0;
}*/
/*

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

int main()
{
	vector<string>words;
	string word;
	while (cin >> word)
		words.push_back(word);
	elimDups(words);
	
	for (const auto &iter : words) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}*/
/*
bool isShorter(const string &s1, const string s2) 
{
	return s1.size() < s2.size();
}
int main()
{
	vector<string>words;
	string word;
	while (cin >> word)
		words.push_back(word);
	sort(words.begin(), words.end(), isShorter);

	for (const auto &iter : words)
		cout << iter << " ";
	cout << endl;
	return 0;

}*/
/// lambda ////

/*
void biggies(vector<string> &words,
	vector<string>::size_type sz);
bool isShorter(const string &s1, const string s2);
void elimDups(vector<string> &words);


int main()
{
	vector<string>words;
	string word;
	while (cin >> word)
		words.push_back(word);
	elimDups(words);

	for (const auto &iter : words) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;

}

void biggies(vector<string> &words,
	vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(), words.end());

}


bool isShorter(const string &s1, const string s2)
{
	return s1.size() < s2.size();
}


void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}*/

/*
bool five_or_more(const string &words) {
	return words.size() > 5;
}

int main()
{
	vector<string>words;
	string word;
	while (cin >> word)
		words.push_back(word);

	for (const auto &iter : words)
		cout << iter << " ";
	cout << endl;

	auto iter = partition(words.begin(),
		words.end(),
		five_or_more);

	for (auto it = words.begin();
		it != iter;
		it++)
		cout << *it << " ";
	cout << endl;

	return 0;

}

*/
/*
int main()
{
	auto f = [] { return 42; };
	cout << f(); Enter;

	auto compare = [](const string &s1, const string &s2)
				{ return s1.size() > s2.size(); };
	
	compare("sdlkfjklsd", "ssss") ? cout << "字符串1的长度大于字符串2的长度" << endl :
								cout << "字符串1的长度小于字符串2的长度" << endl;
	return 0;
}*/
/*

inline void output_words(vector<string> &words)
{
	for (auto iter = words.cbegin(); iter != words.end(); iter++)
		cout << *iter << " ";Enter
}


void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr,const string &word,const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

void biggies(vector<string> &words,
	vector<string>::size_type sz)
{
	elimDups(words);
	cout << "elimDups: ";Enter
	output_words(words);

	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b)
		{ return a.size() < b.size(); } );
												///[](const string &a, const string &b)
												///{return a.size() < b.size(); } );
	cout << "stable_sort: ";Enter
	output_words(words);

	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a)
		{ return a.size() > sz; });						/// [sz](const string &a)
														///{ return a.size() > sz; });

	auto count = words.end() - wc;

	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer." << endl;

	for_each(wc, words.end(),
		[](const string &s)
		{cout << s << " "; });Enter
														/// [](const string &s)
														/// {cout << s << " "; });Enter
}

int main()
{
	vector<string> words;
	string word;
	//   输入的数据 fox quick red fox jumps over the slow red turtle
	while (cin >> word)
		words.push_back(word);
	output_words(words);

	biggies(words, 5);

	return 0;
}*/
/*
int main()
{
	int a = 10, b = 12;
	auto sum = [a, b] { cout << a + b << endl; return 1; };
	sum();
	return 0;
}*/


/*
inline void output_words(vector<string> &words)
{
	for (auto iter = words.cbegin(); iter != words.end(); iter++)
		cout << *iter << " "; Enter
}


void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

void biggies(vector<string> &words,
	vector<string>::size_type sz)
{
	elimDups(words);
	cout << "elimDups: "; Enter
		output_words(words);

	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b)
	{ return a.size() < b.size(); });
	///[](const string &a, const string &b)
	///{return a.size() < b.size(); } );
	cout << "stable_sort: "; Enter
		output_words(words);

	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &a)
	{ return a.size() > sz; });						/// [sz](const string &a)
													///{ return a.size() > sz; });

	auto count = words.end() - wc;

	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer." << endl;

	for_each(wc, words.end(),
		[](const string &s)
	{cout << s << " "; }); Enter
		/// [](const string &s)
		/// {cout << s << " "; });Enter
}

int main()
{
	vector<string> words;
	string word;
	//   输入的数据	 fox jumps over the slow red turtle
	while (cin >> word)
		words.push_back(word);
	output_words(words);

	biggies(words, 5);

	return 0;
}*/

/*
int main()
{
	vector<string> words;
	string word;
	vector<string>::size_type sz = 5;
	while (cin >> word)
		words.push_back(word);

	auto it = count_if(words.begin(), words.end(),
		[sz](const string & str) { return str.size() > sz; });
	cout << it << endl;
	return 0;
}*/

/*

void biggies(vector<string>&words, vector<string>::size_type sz)
{


	//将满足lambda的字符串移动到字符串向量前端，并用pos 接受满足字符串的地址
	auto pos = partition(words.begin(), words.end(),
		[sz](const string& str) 
	{ return str.size() > sz; });

	//输出字符串
	cout << "大于6的字符串有：";
	for_each(words.begin(), pos,
		[](const string &str)
	{ cout << str << " "; }); Enter

	//按字典序排序
	sort(words.begin(), words.end());

	//按字符串从小到大排序
	stable_sort(words.begin(), words.end(),
		[](const string &strA, const string &strB)
	{return strA.size() < strB.size(); });


	//输出全部字符
	for_each(words.begin(), words.end(),
		[](const string &str) 
	{ cout << str << " "; });Enter
}


int main()
{
	vector <string > words;
	string word;
	while (cin >> word)
		words.push_back(word);
	biggies(words,5);

}*/
/*

int main()
{
	int sum = 5;
	auto f = [sum]() mutable ->bool { if (sum > 0) { --sum; return false; }
								else  return true; };
	for (int j = 0; j < 6; j++) {
		cout << f() << endl;
	}
	cout << "sum = " << sum << endl;
	return 0;

}*/

/*
bool length(const string &str,string ::size_type sz)
{
	return str.size() < sz;
}

void biggies(vector<string>words,
		vector<string>::size_type sz)
{
	auto bc = count_if(words.begin(), words.end(),
		bind(length, placeholders::_1, sz));

	cout <<"小于" << sz << "字符个数：" << bc << endl;
}

int main()
{
	vector<string>words;
	string word;
	
	while (cin >> word)
		words.push_back(word);

	biggies(words,6);

	return 0;
}*/
/*
bool check_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}

void biggies(vector<int> &vc, const string &s)
{	
	auto p = find_if(vc.begin(), vc.end(),
		bind(check_size, s, _1) );

	cout << "第" << p - vc.begin() + 1 << "个数" << *p
		<< "大于等于" << s << "的长度。" << endl;
}

int main()
{
	vector<int> vc;
	int val;
	while (cin >> val)
		vc.push_back(val);
	biggies(vc, "string");

	return 0;
}*/

/*
ostream & print(ostream &os, const string &s, string c)
{
	return os << s << c << endl;
}

int main()
{
	vector<string> words;
	string word;
	ostream &os = cout; //流不能拷贝
	string s = " wo ui 'C'";
	

	while (cin >> word)
		words.push_back(word);

//	for_each(words.begin(), words.end(),
//		[&os, c](const string &s) {os << s << c << endl; });

	for_each(words.begin(), words.end(),
		bind(print,ref(os), _1, s));   //bind 不能拷贝cout

	return 0;
}*/

/*
void dlimDups(vector<string> words)
{
	sort(words.begin(), words.end());

	vector<string>::iterator end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

bool check_size(const string &str,vector<string>::size_type sz)
{
	return str.size() > sz;
}

void biggies(vector<string> words, vector<string>::size_type sz)
{
	//按字典序排序，删除重复单词
	dlimDups(words);

	//输出words
	for_each(words.begin(), words.end(),
		[](const string &str) 
		{ cout << str << " "; });Enter
	//将字符长度大于sz 的字符串移动到字符串向量前端，并返回其迭代器
	auto pos = partition(words.begin(), words.end(),
		bind(check_size, _1, sz));

	auto sum = count_if(words.begin(), words.end(),
		bind(check_size, _1, sz));

	cout << "字符长度大于" << sz << "的字符串有" 
		<< sum << "个."<<  endl;
	for_each(words.begin(), pos,
		[](const string &str)
	{ cout << str << " "; });Enter


}


int main()
{	
	vector <string> words;
	string word;

	while (cin >> word)
		words.push_back(word);

	biggies(words, 6);

	return 0;
}*/
/*


int main()
{
	vector<int> vi = { 1,2,3,4,5,5,6 };
	list<int>li;

	unique_copy(vi.begin(), vi.end(), inserter(li, li.begin() ) );

	for (auto v : li) {
		cout << v << " ";
	}Enter

	for each (auto var in li)
	{
		cout << var << " ";
	}Enter;
	return 0;
}*/


/*
int main()
{
	vector<int> vi = { 1,2,3,4,5,6,7,8,9 };
	list<int>li1, li2, li3;

	cout << "inserter(li1,li1.begin():" << endl;
	unique_copy(vi.begin(), vi.end(), inserter(li1, li1.end() ) );

	for each (auto var in li1)
	{
		cout << var << " ";
	}Enter;

	cout << "back_inserter(li2):" << endl;
	unique_copy(vi.begin(), vi.end(), back_inserter(li2));

	for each (auto var in li2)
	{
		cout << var << " ";
	}Enter;

	cout << "back_inserter(li3):" << endl;
	unique_copy(vi.begin(), vi.end(), front_inserter(li3));

	for each (auto var in li3)
	{
		cout << var << " ";
	}Enter;

	return 0;

}*/

/*
int main (int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开文件!" << endl;
		return -1;
	}

	//创建流迭代器从文件读入字符串
	istream_iterator<string> ins_iter(in);

	//尾后迭代器
	istream_iterator<string> ins_eof;
	vector<string>words;

	while (ins_iter != ins_eof)
		words.push_back(*ins_iter++);

	for (const auto &it : words) {
		cout << it << " ";
	}Enter;

	istream_iterator<int> ini_iter1(cin);
	istream_iterator<int> ini_eof;

	while (ini_iter1 != ini_eof)
		cout << *ini_iter1++ << " " << endl; Enter;


}*/

/*

int main()
{
	ostream_iterator<int>out_iter(cout, " ");
	vector<int>vec = {1,2,3,4,5};
	for (const auto &e : vec) {
		*out_iter++ = e; //用<<运算符将e写入到迭代器out_iter中的cout 中
	}Enter

	copy(vec.begin(), vec.end(), out_iter);Enter
	return 0;
}*/


/*
int main()
{
	istream_iterator<Sales_data> item_iter(cin), eof;
	ostream_iterator<Sales_data> out_iter(cout, "\n");

	Sales_data sum = *item_iter++;

	while (item_iter != eof) {

		if (item_iter->isbn() == sum.isbn())
			sum += *item_iter++;
		else {
			out_iter = sum;
			sum = *item_iter++;
		}
	}
	out_iter = sum;
	return 0;
}*/
/*

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开文件! "; Enter
		return - 1;
	}

	istream_iterator<string> in_iter(in),eof;
	vector<string>words;
	
	while (in_iter != eof) {
		words.push_back(*in_iter++);
	}

	for (const auto &it : words) {
		cout << it << " ";
	}Enter

	return 0;
}*/

/*
int main()
{
	istream_iterator<int> ini_iter(cin), eof;
	vector<int> ivec;	
	while (ini_iter != eof) {
		ivec.push_back(*ini_iter++);//输入流不能省略解引用和++
	}
	sort(ivec.begin(),ivec.end());

	ostream_iterator<int> outi_iter(cout, " ");
	

	for (const auto &ival : ivec) {
		*outi_iter++ = ival;// 输出流可以省略解引用和++， outi_iter++ = ival
	}Enter

	copy(ivec.begin(),ivec.end(), outi_iter); Enter

	return 0;
}*/


/*
int main()
{
	istream_iterator<int> ini_iter(cin), eof;
	vector<int> ivec;
	while (ini_iter != eof)
		ivec.push_back(*ini_iter++);

	sort(ivec.begin(), ivec.end());

	ostream_iterator<int> outi_iter(cout, " ");
	unique_copy(ivec.begin(), ivec.end(), outi_iter);

	return 0;
}*/

/*
int main()
{
	map<string, size_t>word_count;
	set<string> exclude = { "The","But","And","Or","An","A",
							"the","but","and","or","an","a" };
	string word;
	while (cin >> word)
		if(exclude.find(word) == exclude.end())
			++word_count[word];

	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}*/

/*
string &trans(string &s)
{
	for(int p =0; p < s.size();p++){
		if (s[p] > 'A' && s[p] < 'Z')
			s[p] -= ('A' - 'a');
		else if (s[p] == ',' || s[p] == '.')
			s.erase(p,1);
	}
	return s;
}

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开文件!" << endl;
		exit(0);
	}

	map<string, size_t>word_count;
	string word;

	while (in >> word)
		++word_count[ trans(word) ];

	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times " : " time") << endl;

	}
	return 0;
}*/

/*
int main()
{
	map<string, size_t> word_count;
	set<string>exclude = { "the", "but","and","or","an","a",
							"The","But","And","Or","An","A" };
	map<string, string> authors = { {"Joyce","James"},
								{"Austen","Jane"},
								{"Dickens","Charles"} };
	for (const auto &w : authors)
		cout << "姓:" << w.first << "名:"
		<< w.second << endl;

	
	
	return 0;
}*/

/*
int main()
{
	vector<int>ivec;
	for (vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	set<int>iset(ivec.cbegin(), ivec.cend());
	multiset<int>miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;


	return 0;
}*/

/*
void add_family(map<string, vector<string>> &familys,
	const string & familykey)
{
	if (familys.find(familykey) == familys.end())
		familys[familykey] = vector<string>();

}

void add_child(map<string, vector<string>>&familys,
	const string &familykey, 
	const string &childnames)
{
//	if (familys.find(familykey) == familys.end()) {
//		cerr << "The have not familykey!" << endl;
//		exit(0);
//	}

	familys[familykey].push_back(childnames);
}



int main()
{
	map <string, vector<string>> familys;
	add_family(familys, "周");

	add_child(familys, "郑", "华钰");
	add_child(familys, "周", "军伟");

	for (const auto &w : familys){
		cout << w.first << "家的孩子:";
		for (const auto &c : w.second)
			cout  << w.first << c << " ";Enter
	}
	return 0;
}*/

/*

string &trans(string &s)
{
	for (int p = 0; p < s.size(); p++)
		if (s[p] >= 'A' && s[p] <= 'Z')
			s[p] -= ('A' - 'a');

		else if (s[p] == ',' || s[p] == '.')
			s.erase(p,1);
	return s;
}


int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if(!in) {
		cerr << "无法打开文件" << argv[1] << endl;
		exit(0);
	}

	vector<string> unique_word;

	set<string> s_unique_word;
	string word;

	while (in >> word)	{
		trans(word);
		if (find(unique_word.begin(), unique_word.end(), word)
			== unique_word.end())
			unique_word.push_back(word);


	}

		trans(word);

		if (find(s_unique_word.begin(), s_unique_word.end(), word)
			== s_unique_word.end())
			s_unique_word.insert(word);
		cout << word << endl;
	
	

	cout << "vector<string>:";
	for (const auto&iter : unique_word)
		cout << iter << " "; Enter;



	cout << "set<string>:";
	for (const auto&iter : s_unique_word)
		cout << iter << " "; Enter;

	in.close();
	return 0;
}*/
/*
void trans(string &word)
{
	for (int p = 0; p < word.size(); p++) {
		if (word[p] >= 'A' && word[p] <= 'Z')
			word[p] -= ('A' - 'a');
		if (word[p] == ',' || word[p] == '.')
			word.erase(p, 1);
	}
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "ERROR：Not Open file ！" << endl;
		exit(1);
	}

	map<string, list<int>>word_lineno;
	string line;
	string word;
	int lineno = 0;

	while (getline(in, line)) {
		lineno++;
		istringstream l_in(line);
		while (l_in >> word) {
			trans(word);
			word_lineno[word].push_back(lineno);
		}
	}

	for (const auto &w:word_lineno) {
		cout << w.first << "所在的行：";
		for (const auto &i : w.second)
			cout << i << " ";Enter
	}
	return 0;
}*/

/*
typedef bool (*pf) (const Sales_data &, const Sales_data&);

multiset(Sales_data, pf) bookstore(compareIsbn);
*/

/*

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "ERROR: NOT OPEN THIS FILE !" << endl;
		exit(1);
	}

	vector<pair<string, int>>data;
	string s;
	int v;
	while (in >> s && in >> v)
		data.push_back(pair<string, int>(s, v));
	for (const auto &d : data) {
		cout << d.first << " " << d.second << endl;
	}


	return 0;
}*/
/*

void add_family(map<string, vector<pair<string, string>>>&families,
	const string &family)
{
	families[family];
}


void add_child(map<string, vector<pair<string, string>>> &families,
	const string & family, const string &child,
	const string &birthday )
{
	families[family].push_back({ child,birthday });
}


int main()
{
	map<string, vector<pair<string, string>>>families;
	
	add_family(families, "周");
	add_child(families, "周", "军伟", "1997-6-10");
	add_child(families, "周", "楚", "1989-1-1");
	for (const auto &f : families) {
		cout << f.first << "家的孩子:" << endl;
		for (const auto &c : f.second)
			cout << f.first << c.first << "(生日" << c.second << ")" << endl;
	}


	return 0;
}*/

/*

int main(int argc,char *argv[])
{
	map<int, vector<string>>m;
	//mapped_type 是vector<string>
	//key_type是int
	//value_type是pair<int,vector<string>>


	ifstream in(argv[1]);
	if (!in) {
		cerr << "ERROR: NOT OPEN　THIS FILE !"<< endl;
		exit(1);
	}

	map<string, size_t>word_count;
	string word;
	while (in >> word)
		++word_count[word];

	map<string, size_t>::iterator it = word_count.begin();
	while (it != word_count.end()) {
		cout << (*it).first << "Occur" << (*it).second << endl;
		++it;
	}

	return 0;
}
*/
/*

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "ERROR:NOT OPEN THIS FILE !" << endl;
		exit(1);
	}

	map<string, size_t>word_count;
	string word;

	while (in >> word) {
		auto iter = word_count.insert({ word,1 });//1
		if (!iter.second)//2
			++iter.first->second;//3

	}
	for (const auto &iter : word_count)
		cout << iter.first << "occur" << iter.second
		<< endl;




	return 0;
}*/

/*
void print_books(multimap<string, string>&books)
{
	for (const auto &it : books) {
		cout << it.first << " - " << it.second
			<< endl;
	}
}

void remove_author(multimap<string, string> &books, const string &author)
{
	auto pos = books.equal_range(author);
	if (pos.first == pos.second)
		cout << "删除失败：没有'" << author << "'这个作者! " << endl << endl;
	else {
		books.erase(pos.first, pos.second);
		cout << "已删除'" << author << "'的所有书籍!" << endl << endl;
	}
}

int main(int argc,char *argv[])
{
	multimap<string, string>books;
	books.insert({ "Barth,John","Sot-Weed Factor" });
	books.insert({ "Barth,John","Lost in the Funhouse" });
	books.insert({ "金庸","射雕英雄传" });
	books.insert({ "金庸","天龙八部" });
	print_books(books); Enter
	remove_author(books, "张三");

	remove_author(books, "Barth,John");
	print_books(books);

	return 0;
}*/


/*
map<string,string> buildMap(ifstream &map_file)

{
	map<string, string>trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	return trans_map;

}

const string &transform(const string &s,
	const map<string, string> &m)

{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;

}

void word_transform(ifstream &map_file, 
	ifstream &input)

{
	auto trans_map = buildMap(map_file);
	string text;

	while (getline(input, text)) {

		istringstream stream(text);
		string word;
		bool firstword = true;

		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}Enter

	}

}



int main(int argc,char *argv[])
{

	ifstream in_one(argv[2]);
	if (!in_one) {
		cerr << "ERROR: NOT OPEN FILE \"IN_ONE\" ！" << endl;
		exit(1);
	}
	ifstream in_two(argv[3]);
	if (!in_two) {
		cerr << "ERROR: NOT OPEN FILE \"IN_TWO\" ！" << endl;
		exit(2);
	}
	
	word_transform(in_one, in_two);

	return 0;
}*/
/*
int main(int argc,char **argv)
{
	ifstream fin(argv[1]);
	if (!fin) {
		cerr << "ERROR:NOT OPEN THIS FILE !" 
			<< endl;
		exit(1);
	}

	map<string, size_t >map_word_count;
	unordered_map<string, size_t>unoredered_map_word_count;
	string word;
	while (fin >> word){
		++unoredered_map_word_count[word];
		++map_word_count[word];
	}

	for (const auto &w : unoredered_map_word_count)
		cout << w.first << " : " << w.second 
			<< endl;
	Enter
	for (const auto &w : map_word_count)
		cout << w.first << " : " << w.second
		<< endl;

	fin.close();

	return 0;
}*/
/*

int main(int argc, char **argv)
{
	StrBlob b1;
	{
		StrBlob b2 ({"a","an","the" });
		b1 = b2;
		b2.push_back("about");
		std::cout << b2.size() << endl;
		std::cout << b2.data.use_count() << endl;
	}
	std::cout << b1.data.use_count() << endl;
	std::cout << b1.size() << endl;
	std::cout << b1.front() << " " << b1.back() << endl;

	const StrBlob b3 = b1;
	std::cout << b3.front() << " " << b3.back() << endl;

	std::cout << b1.data.use_count() << endl;
	return 0;
}*/

/*
vector<int> *new_vector(void)
{
	return new (nothrow)vector<int>;
}

void read_ints(vector<int> *pv)
{
	int v;

	while (cin >> v)
		pv->push_back(v);
}

void print_ints(vector<int> *pv)
{
	for (const auto &v : *pv)
		cout << v << " "; Enter
}


int main(int argc, char **argv)
{
	vector<int> *pv = new_vector();
	vector<int> *pvTest = new vector<int>(10,1);
	if (!pv) {
		cout << "内存不足 ！" << endl;
		return -1;
	}
	read_ints(pv);
	print_ints(pv);
	print_ints(pvTest);

	return 0;
}*/
/*
shared_ptr<vector<int>> 
new_vector(void)
{
	return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>>spv)
{
	int v;

	while (cin >> v)
		spv->push_back(v);
}

void print_ints(shared_ptr<vector<int>>spv)
{
	for (const auto &it : *spv)
		cout << it << " ";
	Enter;
}

int main()
{
	auto spv = new_vector();

	read_ints(spv);
	print_ints(spv);

	return 0;
}*/

/*
void  process(shared_ptr<int>ptr)
{
	cout << ptr.use_count() << endl;
	cout << *ptr << endl;

}

int main()
{
	shared_ptr<int>p(new int(42));
	process(p);
//	process(shared_ptr<int>(p.get()));
	

	return 0;
}*/
/*

struct destination{};
struct connection{};

connection connect(destination *pd)
{
	cout << "打开连接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;
}

//未使用shared_ptr的版本
void f(destination &d)
{
	cout << "直接管理connect" << endl;
	connection c = connect(&d);
	//忘记调用disconnect关闭连接
	cout << endl;
}


void end_connection(connection *p) { disconnect(*p); }

void f1(destination &d)
{
	cout << "用shared_ptr管理connect" << endl;
	connection c = connect(&d);
	shared_ptr<connection>p(&c, end_connection);
	//忘记调用disconnect关闭连接
	cout << endl;
}


int main()
{

	destination d;
	f(d);
	f1(d);
	
	return 0;
}*/

/*
struct destination{};
struct connection {};

connection connect(destination *pd)
{
	cout << "打开连接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;
}

//未使用shared_ptr的版本
void f(destination &d)
{
	cout << "直接管理connect" << endl;
	connection c = connect(&d);
	//忘记调用disconnect关闭连接
	Enter
}

//使用shared_ptr的版本
void f1(destination &d)
{
	cout << "用shared_ptr管理conncet" << endl;
	connection c = connect(&d);
	shared_ptr<connection>p(&c,
		[](connection *p) { disconnect(*p); });
	Enter
}


int main()
{

	destination d;
	f(d);
	f1(d);

	return 0;
}*/
/*
int main(int argc, char ** argv)
{
	ifstream in(argv[1]);
	if (!in) {
		cout << "ERROR:无法打开输入文件!" << endl;
		return -1;
	}
	StrBlob b;
	string s;
	while (getline(in, s))
		b.push_back(s);
	for (auto it = b.begin(); neq(it, b.end()); it.incr())
		cout << it.deref() << endl;

	return 0;
}*/
/*
int main(int argc, char **argv)
{
	const StrBlob b ({ "Hello","Wordl","!" });
	for (auto it = b.begin(); neq(it, b.end()); it.incr())
		cout << it.deref() << endl;

	return 0;
}*/
/*


int main()
{
	const char *c1 = "Hello ";
	const char *c2 = "World !\0";
	char *r = new char[strlen(c1) + strlen(c2) + 1];// 多开辟一个空间放入'/0'作为结束控制符 

	strcpy_s(r, strlen(c1) + strlen(c2) + 1,c1);
	strcat_s(r, strlen(c1) + strlen(c2) + 1,c2);
	cout << r << endl;

	string s1 = "hello ";
	string s2 = "world !";
	strcpy_s(r, strlen(c1) + strlen(c2) + 1,
		(s1 + s2).c_str());//拷贝连接结果
	cout << r << endl;
	
	//释放动态数组
	delete[] r;


	return 0;
}*/

/*

int main(int argc,char **argv)
{
	char c;
	char *r = new char[20];
	int l = 0;

	while (cin.get(c)){
		if (isspace(c))
			break;
		r[l++] = c;
		if (l == 19) {
			cout << "达到数组上限" << endl;
			break;
		}
	}
	r[l-1] = 0;
	cout << r << endl;
	delete[]r;
	
	return 0;
}*/
/*
int main()
{


	string *const p = new string[10];
	string s;
	string *q = p;
	while (cin >> s && q != q + 10) {
		*q++ = s;
	}

	const size_t size = q - p;
	cout << size << endl;
	delete[] p;


	allocator<string>alloc;
	//分配100个未初始化的string
	auto const p = alloc.allocate(5);
	string s;
	string *q = p;
	while (cin >> s && q != p + 5)
		alloc.construct(q++, s);

	const size_t size = q - p;

	for (size_t i = 0; i < size; i++)
		cout << p[i] << " " << endl;
	while (q != q)
		alloc.destroy(--q);

	alloc.deallocate(p, 100);
	return 0;
}*/
/*
class Test
{
public:
	Test() {};
	Test(const Test &object)
		:ival(object.ival) {};
	~Test() {};
public:
	int get_ival() const { return ival; }
	void set_ival(int temp) { this->ival = temp; }
private:
	int ival = 0;
};

int main()
{

	Test a;
	a.set_ival(2);
	Test b(a);
	b = a;
	Test *c = new Test();
	
	cout << c->get_ival();
	cout << b.get_ival() << endl;

	
//	a.print_ival();
	return 0;
}*/
/*

class Test
{
public :
	Test()=default;
//explicit
Test(const Test&);
public:
	string get_bookNo()const { return bookNo; };
private:
	string bookNo;
	int units_sold = 0;
	double revenue = 0.0;

};

Test::Test(const Test&orig)
	:bookNo(orig.bookNo),
	units_sold(orig.units_sold),
	revenue(orig.revenue)
{

}

int main()
{
	Test a;
	cout << a.get_bookNo() << endl;
	Test b;
	b = a;
	cout << b.get_bookNo() << endl;
	
	return 0;
}*/

/*
struct X
{
	X() { cout << "构造函数X() " << endl; }
	X(const X&) { cout << "拷贝构造函数!x(const X&) " << endl; }
	X &operator = (const X &rhs){
		cout << "拷贝赋值运算符 =(const X&) " << endl;
		return *this; 
	}
	~X() { cout << "析构函数~X()" << endl; };
};
void f1(X x)
{

}

void f2(X &x)
{

}


int main()
{
	cout << "局部变量：" << endl;
	X x; Enter;

	cout << "非引用参数传递:" << endl;
	f1(x); Enter;

	cout << "引用参数传递:" << endl;
	f2(x); Enter;

	cout << "动态分配： " << endl;
	X *px = new X; Enter;

	cout << "添加到容器中:" << endl;
	vector<X> vx;
	vx.push_back(x); Enter;

	cout << "释放动态分配对象: " << endl;
	delete px; Enter;

	cout << "间接初始化和赋值: " << endl;
	//X y = x;
	X y(x);
	y = x;
	cout << endl;

	cout << "________________END_____________" << endl;

	return 0;
}
*/
/*

class Test
{
public:
	Test() {};
	Test(const Test &object)
		:ival(object.ival) {};
	~Test() {};
public:
	int get_ival() const { return ival; }
	void set_ival(int temp) { this->ival = temp; }
private:
	int ival = 0;
};

int main()
{

	Test a;
	a.set_ival(2);

	Test b;
	cout << b.get_ival() << endl;
	b = a;
	cout << b.get_ival() << endl;


	//	a.print_ival();
	return 0;
}*/

/*


class Test
{

public :
	int data = 0;
};

int main()
{
	Test a;
	cout << a.data << endl;
//	control;
	Test b(a); //
	b = a;


	return 0;
}*/
/*
class numbered
{
private:
	static int seq;
public:
	numbered() { mysn = seq++; }
	numbered(const numbered &n) { mysn = seq++; }
	int mysn;
};

int numbered::seq = 0;

void f(const numbered &s)
{
	cout << s.mysn << endl;
}


int main()
{
	numbered a, b = a, c = b;
	f(a), f(b), f(c);

	return 0;
}*/


/*
class Employee
{
private:
	static int sn;
public:
	Employee() { mysn = sn++; }
	Employee(const string &s) { name = s; mysn = sn++; }
	//为19题
	Employee(const Employee &e) {name = e.name;mysn = sn++;}
	Employee operator = (const Employee &rhs) {name = rhs.name;return *this;}
	const string &get_name() { return name; }
	int get_mysn() { return mysn; }
private :
	string name;
	int mysn;
};

int Employee::sn = 0;

void f(Employee &s)
{
	cout << s.get_name() << ":" << s.get_mysn() << endl;
}



int main()
{

	Employee a("赵"), b = a, c;

	c = b;
	f(a), f(b), f(c);
	return 0;
}*/
/*
class HasPtr
{
public: 
	//构造string
	HasPtr(const string &s = string())
		:ps(new string(s)), i(0) { }
	HasPtr(const HasPtr&p)
		:ps(new string(*p.ps)), i(p.i) { }
public:
	HasPtr& operator= (const HasPtr &);
	//赋值string
	HasPtr& operator=(const string &);
	//解引用
	string & operator*();
	~HasPtr();
	
private:
	string *ps;
	int i;
};

inline 
HasPtr& HasPtr:: operator=(const HasPtr &rhs)
{
	auto newps = new string(*rhs.ps);
	delete ps;   
	ps = newps;
	i = rhs.i;
	return *this;
}
inline
HasPtr& HasPtr:: operator=(const string &rhs)
{
	*ps = rhs;
	return *this;
}

inline
string& HasPtr:: operator*()
{
	return *ps;
}

HasPtr::~HasPtr()
{
	delete ps;
}
 
int main()
{
	
	int i = 3;
	int *j = new int(i);
	int j;
	delete j;
	cout << *j << endl;

	j = &i;
	cout << *j << endl;

	return 0;
}*/

/*

int main()
{
	vector<string>sv{ "include girl" };
	StrBlob p = { "Hello ","World!" };
	StrBlob p1(new vector<string> {"include boy"} );
	p = sv;

	for (const auto &it : *p.data)
		cout << it; Enter;
	for (const auto &it : *p1.data)
		cout << it;	Enter;


	return 0;
}*/

/*
int main()
{

	cout << "Value of __LINE__ : " << __LINE__ << endl;
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	cout << "Value of __TIME__ : " << __TIME__ << endl;
	OUT_LINE;
	return 0;

}*/

/*

int main()
{
	HasPtr h("hi mon!");
	HasPtr h2("hi dad!");
	swap(h, h2);
	
	cout << "H: " << *h << endl;
	cout << "H2: " << *h2 << endl;
	
	return 0;
} */
/*
int main()
{
	int i = 43;
	int &r = i;
	int &&rr = 43;

	int &r2 = i * 42;

	return 0;
}*/

/*
int main()
{
	String s1("One\0"), s2("Two");
	cout << s1;
	cout << " " << s2 << endl << endl;
	String s3(s2);
	cout << s1 << " " << s2 << " " << s3 << endl << endl;
	s3 = s1;
	cout << s1 << " " << s2 << " " << s3 << endl << endl;

	
	vector<String>vs;
	cout << " 1 " << endl;
	vs.push_back(s1);
	cout << " 2 " << endl;
	vs.push_back(std::move(s2));
	cout << " 3 " << endl;
	vs.push_back(String("Three"));
	cout << " 4 " << endl;
	vs.push_back("Four");

	for_each(vs.begin(), vs.end(),
		[](const String &s)
	{cout << s << " "; });

	return 0;
}
*/
/*
struct absInt {
	int operator()(int val)const {
		return -val;
	}
	int operator[](size_t n) {
		return a[n];
	}
private:
	int a[10];
};

int main()
{
	absInt absObj;
	cout << absObj(-42) << endl;
	cout << absObj[1] << endl;
	return 0;
}
*/

/*
class ReadString {
public:
	ReadString(istream &is = cin):is(is){ }
	string operator()()
	{
		string line;
		if (!getline(is, line))
		{
			line = " ";
		}
		return line;
	}
private:
	istream &is;
};


void testReadString()
{
	ReadString rs;
	vector<string>vec;

	while (true)
	{
		string line = rs();
			if (!line.empty()) {
			vec.push_back(line);
		}
	}
}

int main()
{
	ReadString read(cin);
	testReadString();
	return 0;
}
*/
/*
class StrLenIs {
public:
	StrLenIs(int len) :len(len) { }
	bool operator()(const string &str) { return str.length() == len; }

private:
	int len;
};

void readStr(istream &is, vector<string>&vec)
{
	string word;
	while (is >> word)
	{
		vec.push_back(word);
	}
}
int main()
{
	vector<string>vec;
	readStr(cin, vec);
	const int minLen = 1;
	const int MaxLen = 10;
	for(int i = minLen; i < MaxLen; i++) {
		StrLenIs slenIs(i);
		cout << "len : " << i << ",cnt: " << count_if(vec.begin(), vec.end(), slenIs) << endl;
	}

	return 0;
}*/
/*

class Quote
{
public:
	Quote() = default;
	Quote(const string &book, double sales_price) :
		bookNo(book), price(sales_price) {}
	string isbn()const { return bookNo; }
	//返回给定数量的书籍的销售总额，派生类改写并使用不同的折扣算法
public:
	virtual double net_price(std::size_t n) const { return n*price; }
	virtual void debug()
	{
		cout << "bookNo=" << bookNo << "  price=" 
			<< price << endl;
	}
	virtual ~Quote() = default;				//对析构函数进行动态绑定
private:
	string bookNo;							//书籍的ISBN
protected:
	double price = 0.0;						//代表不同状态下不打折的价格
};

class Bulk_quote : public Quote
{
public:
	Bulk_quote(const string &book = "", double sales_price = 0,
		size_t qty = 0, double disc_rate = 0) :
		Quote(book, sales_price), min_qty(qty), discount(disc_rate) {}
public:
	double net_price(size_t cnt)const override
	{
		if (cnt >= min_qty)
			return cnt * (1 - discount) *price;
		else return 
			cnt * price;

	}

	virtual void debug()
	{
		Quote::debug();			//bookNo变量为private，所以不能直接访问bookNo
								//只能调用积累的debug（）函数来显示
		cout << "min_qty" << min_qty << " discount=" 
			<< discount << endl;
	}
private:
	size_t min_qty;
	double discount;

};

class Limited_quote : public Quote
{
public:
	double net_price(size_t cnt) const override
	{
		if (cnt <= min_qty)
			return cnt * (1 - discount) * price;
		else
			return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
	}
private:
	size_t min_qty;
	double discount;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::net_price
	//或者从Bulk_quote::net_price(n)
	double ret = item.net_price(n);
	os << "ISBN : " << item.isbn() << "  #sold: "
		<< n << "  total due: " << ret << endl;
	return ret;
}


int main()
{
	Quote  quote("978-7-121-25229-7",89);
	Bulk_quote b_Quote("978-7-121-25229-7", 89,10,9);

	print_total(cout, quote, 5);
	print_total(cout, b_Quote, 5);

	int ary[12];
	for (int i = 0; i < 12; i++)
	{
		ary[i] = i;
	}
	ary[-2] = 0;
	int *p = ary;
	++++p;
	p[-100] = 2;
	++++p;
	(-2)[p] = 6;
	cout << p << endl;
	cout << (-3)[p] << endl;
	cout << (-1)[p] << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << ary[i] << " ";
	}
	Enter;

	return 0;
}
*/

/*
struct AbsInt 
{
	int operator()(int val)const {
		return val < 0 ? -val:val;
	}
};

class PrintString
{
public:
	PrintString(ostream&o = cout, char c = ' ')
	:os(o),sep(c) {}
	void operator()(string &s)
		{ os << s << sep; }
private:
	ostream &os;
	char sep;
};

int add(int i, int j) { return i + j; }

int main()
{
	PrintString printer;
	string s= "abcd";
	vector<string> vs;
	vs.push_back(s);
	vs.push_back(s);
	for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));

	auto mod = [](int i, int j) { return i%j; };
	struct divide {
		int operator()(int denominator, int divisor) {
			return denominator / divisor;
		}
	};
	int (*addback)(int,int) = add;

	divide divide_back;

	cout << divide_back(10,5) << endl;
	map<string, int(*)(int, int)>binops;
	binops.insert({ "+", add });
	binops.insert({ "%",mod});
	binops.insert({ "++",addback });
	cout << binops["%"](10, 3); Enter;
	cout << binops["+"](10, 5); Enter;
	cout << binops["++"](10, 55); Enter;

	return EXIT_SUCCESS; 
}*/
/*
template<typename T>
int compare( const T& lhs, const T& rhs)
{
	if(lhs != rhs)
		return lhs > rhs ? 1 : -1;
	return 0; 
}

 
int main()
{
	cout << compare(1, 0) << endl;
	cout << compare(1.0, 0.0) << endl;
	vector<int>vec1{ 1,2,3 }, vec2{4,5,6};
	cout <<  compare(vec1, vec2) << endl;
	return 0;
}
*/


#include<iostream>  
#include<vector>  
#include<random>  
#include<ctime>  
#include<iterator>  
#include<algorithm>  
using namespace std;

/*
* 插入排序，从小到大
*/
template<typename T>
void insertionSort(vector<T> & a)
{
	for (size_t p = 1; p < a.size(); ++p) // 从第二个数开始  
	{
		T tmp = a[p];
		size_t j = p;
		for (; j > 0 && a[j - 1] > tmp; --j)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

template<typename T>
void printVector(vector<T> & v)
{
	copy(v.cbegin(), v.cend(), ostream_iterator<T>(cout, " "));
	cout << endl;
}

int main()
{
	vector<int> source;
	uniform_int_distribution<int> u(0, 100);
	default_random_engine e(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < 10; i++)
	{
		source.push_back(u(e));
	}

	cout << "排序前：" << endl;
	printVector(source);

	insertionSort(source);

	cout << "排序后：" << endl;
	printVector(source);

	return 0;
}