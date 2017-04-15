#include<iostream>
using namespace std;

struct MyNode{ //结点的结构体
	MyNode(int a_data):m_data(a_data),m_next(NULL),num(NULL){};
	int m_data;
	int num;
	MyNode *m_next;
};

class Josephus{
private:
	int _size; //人数
	int _bound; //密码
	MyNode *head;
public:
	Josephus(int size,int bound);
protected:
	void creativeList(); //根据每个人所持密码创建列表
	void outList(); //输出列表
};