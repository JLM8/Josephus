#include<iostream>
#include"Josephus.h"
using namespace std;
int main(){
	int size=0; //人数初始化
	int bound=0; //密码初始化
	cout<<"Please input the size of people..."<<endl;
	cin>>size; //用户输入人数
	cout<<"Please input bound..."<<endl;
	cin>>bound; //用户输入初始密码
	Josephus(size,bound);
	
	
	
	system("pause");
	return 0;
}