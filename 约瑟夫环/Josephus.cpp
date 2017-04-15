#include<iostream>
#include"Josephus.h"
using namespace std;

Josephus::Josephus(int size, int bound){ //约瑟夫环到构造函数
	_size=size; //人数赋值
	_bound=bound; //m值赋值
	creativeList(); //创建约瑟夫环
	outList(); //输出结果
}

void Josephus::creativeList(){ //创建约瑟夫环
	MyNode *pre=NULL; //当前结点
	MyNode *cur=NULL; //临时结点
	MyNode *p=NULL;
	cout<<"Please input password..."<<endl;
	cout<<"The IMPORTANT THING is the OVERFLOW password won't be retain!!!"<<endl; 

	int * passward = new int [_size];  //储存密码的数组
	bool legal; //判断密码是否合法
	do{
		legal = true;
		for(int i=0; i<_size; i++){ //用户输入密码
			int data=0;
			cin>>data;
			passward[i]=data;
		}
		for(int i=0; i<_size; i++){ //循环密码数组 如果有为”0“密码 密码非法
			if(passward[i]==0){
				cout<<"The password isn't equal to 0! Please re-input your password..."<<endl;
				legal=false;
				break;
			}
		}

	}while(legal==false); //密码非法重新输入

	for(int i=0; i<_size; i++){ //将密码存入链表
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
	for(int i=0; i<_size; i++){ //打印密码
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
		//对_bound进行计数 寻找下一个人
		_bound-=1;
		while(_bound--){
			pre=cur;
			cur=cur->m_next;
			//cout<<pre->m_data<<" ";
		}
		//cout<<endl;
		//输出当前人编号
		cout<<cur->num<<" ";
		//cout<<endl;
		//将当前人所持密码赋给_bound
		_bound=cur->m_data;
		//cout<<"bound: "<<_bound<<endl;

		//将cur赋值给*p 并将其删除 同时将其前一结点和后一结点链接
		MyNode *p=cur;
		cur=cur->m_next;
		pre->m_next=cur;
		delete p;    
	}
	cout<<endl;
}