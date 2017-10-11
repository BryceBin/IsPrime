#include<iostream>
#include<cmath>
#include<time.h>
#include <windows.h>
#define n 10//n��ʾ����n�η���С������֤
using namespace std;


/*		��������	*/	
long getnum();
void Isprime_1(long num);
void Isprime_2(long num);
void Isprime_3(long num);
void Isprime_4(long num);
long get_a(long num);
bool quick_mod(long long a, long long b, long long c);


int main() {
	srand((unsigned)time(NULL));

	long num = getnum();
	double start;
	double  end;

	start = GetTickCount();
	for (int i = 0; i < 3000; i++) {
	Isprime_1(num);
	}
	end = GetTickCount();
	cout << end - start << endl;

	start = GetTickCount();
	for (int i = 0; i < 3000; i++) {
		Isprime_2(num);
	}
	end = GetTickCount();
	cout << end - start << endl;
	
	start = GetTickCount();
	for (int i = 0; i < 3000; i++) {
		Isprime_3(num);
	}
	end = GetTickCount();
	cout << end - start << endl;

	start = GetTickCount();
	for (int i = 0; i < 3000; i++) {
		Isprime_4(num);
	}
	end = GetTickCount();
	cout << end - start << endl;

	return 0;
}

long getnum() {
	cout << "enter the number below" << endl;
	long num;
	cin >> num;
	return num;
}


/*			����һ����������3С��num����			*/
void Isprime_1(long num) {
	bool flag = true;
	if (num < 2) flag = false;
	for (int i = 3; i < num; i++) {
		if (num%i == 0) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "Is Prime" << endl;
	else
		cout << "Not Prime" << endl;
}


/*			����������������3С��num/2����			*/
void Isprime_2(long num) {
	bool flag = true;
	if (num < 2) flag = false;
	for (int i = 3; i < num / 2; i++) {
		if (num%i == 0) {
			flag = false;
			break;
		}
	}
	/*if (flag)
		cout << "Is Prime" << endl;
	else
		cout << "Not Prime" << endl;*/
}


/*			����������������3С��sqrt(num)����			*/
void Isprime_3(long num) {
	bool flag = true;
	if (num < 2) flag = false;
	for (int i = 3; i < sqrt(float(num)); i++) {
		if (num%i == 0) {
			flag = false;
			break;
		}
	}
	/*if (flag)
		cout << "Is Prime" << endl;
	else
		cout << "Not Prime" << endl;*/
}


/*			�����ģ����÷���С�����ж�����					*/
/*			a^(num-1)��1 (mod num)   aΪ[2,num-1]������һ�� */
void Isprime_4(long num) {
	bool flag = true;

	/*�ų��������*/
	if (num < 2) {
		cout << "Not prime" << endl;
		return;
	}
	if (num == 2) {
		cout << "Is prime" << endl;
		return;
	}
	///////////////

	for (int i = 0; i < n; i++) {
		long a = get_a(num);
		flag = quick_mod(a, num - 1, num);
		if (flag == false) {
			cout << "Not prime" << endl;
			break;
		}
	}
	if (flag)
		cout << "Is prime" << endl;
}

/*	����������ƻ�ȡa	*/
long get_a(long num) {
	return (rand() % (num - 2)+2) ;
}

/*	������ȡģ����֤����С����ʽ	*/
bool quick_mod(long long a, long long b, long long c) {
	long long ans = 1;
	while (b != 0) {
		if (b & 1)
			ans = (ans*a) % c;
		b >>= 1;
		a = (a*a) % c;
	}
	if (ans == 1)
		return true;
	else
		return false;
}




