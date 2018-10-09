// DataStructure.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace::std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int sort_kp(vector<int> &to_sort, size_t left, size_t right) {
	// left : low index
	// right : hight index

	if (right == left || left > right) {
		cout << "--" << endl;
		return 0;
	};
	size_t n = 0;
	int i = 1;
	for (; left + n <= right; ++n) {
		if (to_sort.at( left ) > to_sort.at(left + n) ) {			// 选择最左边的元素作为基底，即left
			swap( to_sort.at(left + i++), to_sort.at(left + n) );	// 记录每一次交换的次数
		}
	}
	swap(to_sort.at(left), to_sort.at(left + i-1));					// 基底归位

	sort_kp(to_sort, left, left + i -1);
	sort_kp(to_sort, left+i, right);
	return 0;
}


//struct Stack {
//	// struct 默认为public
//
//	vector<int> stack;
//	//入栈
//	void push(int data_push) {	
//		stack.push_back(data_push);
//	}
//	// 出栈
//	int pop() {
//		if (!isEmpty()) {
//			auto temp = stack.back();
//			stack.pop_back();
//			return temp;
//		}
//		else {
//			cout << "The stack is Empty!" << endl;
//			return 0;
//		}
//	}
//	// 判断栈是否为空
//	bool isEmpty() {
//		return stack.empty();
//	}
//	// 显示所有栈元素
//	void show() {
//		if(isEmpty())
//			cout << "The stack is Empty!" << endl;
//		else {
//			for (auto data : stack) {
//				cout << data << endl;
//			}
//		}
//	}
//	// 显示栈顶元素
//	int top() {
//		if (isEmpty()) {
//			cout << "The stack is Empty!" << endl;
//			return 0;
//		}
//		else
//		{
//			return stack.back();
//		}
//	}
//};
//class Squeue {
//public:
//	vector<int> squeue;
//	int len = 0;
//	void push(int data_push) {
//		squeue.push_back(data_push);
//	}
//	int pop() {
//		if (!isEmpty()) {
//			auto temp = squeue.front();
//			squeue.erase(squeue.begin());
//			return temp;
//		}
//		else
//			return 0;
//	}
//	int len();
//	bool isEmpty() {
//		return(squeue.empty());
//	}
//};

int main()
{	
	vector<int> x{ 3,5,7,1,9,2,6,8,0,50,3,54,7,2,72,2,6,2,7,8,3,4};
	for (int n = 0; n != x.size(); ++n) {
		cout << x.at(n) << " ";
	}
	sort_kp(x, 0, x.size()-1);
	cout << "\n after sorted :\n";
	for (int n = 0; n != x.size(); ++n) {
		cout << x.at(n) << " ";
	}


	//system(pause);
    return 0;
}

