#include<iostream>
#include"Josephus.h"
using namespace std;
int main(){
	int size=0; //������ʼ��
	int bound=0; //�����ʼ��
	cout<<"Please input the size of people..."<<endl;
	cin>>size; //�û���������
	cout<<"Please input bound..."<<endl;
	cin>>bound; //�û������ʼ����
	Josephus(size,bound);
	
	
	
	system("pause");
	return 0;
}