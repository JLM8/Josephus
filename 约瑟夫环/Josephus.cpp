#include<iostream>
#include"Josephus.h"
using namespace std;

Josephus::Josephus(int size, int bound){ //Լɪ�򻷵����캯��
	_size=size; //������ֵ
	_bound=bound; //mֵ��ֵ
	creativeList(); //����Լɪ��
	outList(); //������
}

void Josephus::creativeList(){ //����Լɪ��
	MyNode *pre=NULL; //��ǰ���
	MyNode *cur=NULL; //��ʱ���
	MyNode *p=NULL;
	cout<<"Please input password..."<<endl;
	cout<<"The IMPORTANT THING is the OVERFLOW password won't be retain!!!"<<endl; 

	int * passward = new int [_size];  //�������������
	bool legal; //�ж������Ƿ�Ϸ�
	do{
		legal = true;
		for(int i=0; i<_size; i++){ //�û���������
			int data=0;
			cin>>data;
			passward[i]=data;
		}
		for(int i=0; i<_size; i++){ //ѭ���������� �����Ϊ��0������ ����Ƿ�
			if(passward[i]==0){
				cout<<"The password isn't equal to 0! Please re-input your password..."<<endl;
				legal=false;
				break;
			}
		}

	}while(legal==false); //����Ƿ���������

	for(int i=0; i<_size; i++){ //�������������
		if(i==0){
			p = new MyNode(passward[i]);
			p->num=1;
			head=p;
			cur=p;
		}else{
			p = new MyNode(passward[i]);
			p->num=i+1;
			pre = cur;
			cur = p;
			pre->m_next=cur;
		}
	}
	delete passward;
	cur->m_next=head;

	cout<<endl;
	cout<<"size:"<<_size<<endl;
	cout<<"bound:"<<_bound<<endl;
	cout<<endl;
	cout<<"The password is"<<endl;
	p=head;
	for(int i=0; i<_size; i++){ //��ӡ����
		cout<<p->m_data<<" ";
		p = p->m_next;
	}
	cout<<endl;
	cout<<"-------------------------"<<endl;
}

void Josephus::outList(){
	MyNode *pre = NULL;
	MyNode *cur = head;
	cout<<"The result is"<<endl;

	for(int i=_size; i>0; i--){
		//��_bound���м��� Ѱ����һ����
		_bound-=1;
		while(_bound--){
			pre=cur;
			cur=cur->m_next;
			//cout<<pre->m_data<<" ";
		}
		//cout<<endl;
		//�����ǰ�˱��
		cout<<cur->num<<" ";
		//cout<<endl;
		//����ǰ���������븳��_bound
		_bound=cur->m_data;
		//cout<<"bound: "<<_bound<<endl;

		//��cur��ֵ��*p ������ɾ�� ͬʱ����ǰһ���ͺ�һ�������
		MyNode *p=cur;
		cur=cur->m_next;
		pre->m_next=cur;
		delete p;    
	}
	cout<<endl;
}