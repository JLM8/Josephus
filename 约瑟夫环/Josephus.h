#include<iostream>
using namespace std;

struct MyNode{ //���Ľṹ��
	MyNode(int a_data):m_data(a_data),m_next(NULL),num(NULL){};
	int m_data;
	int num;
	MyNode *m_next;
};

class Josephus{
private:
	int _size; //����
	int _bound; //����
	MyNode *head;
public:
	Josephus(int size,int bound);
protected:
	void creativeList(); //����ÿ�����������봴���б�
	void outList(); //����б�
};