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
int quick_sort(vector<int> &to_sort, size_t left, size_t right) {
	//if (left >= right) return 0;
	if (right == left || left > right) {
		//cout << "--" << endl;
		return 0;
	};

	size_t count = 0;
	size_t n = 0;
	while (left + ++n < right) {
		if (left == right) return 0;

		if (to_sort[left] >= to_sort[left + n]) {
			//if (to_sort[left] == to_sort[left + n]) {
				//count++; 
			//}
			//else {
				swap(to_sort[left + ++count], to_sort[left + n]);
			//}
		}
	}
	swap(to_sort[left], to_sort[left + count]);

	cout << "count :" << count << endl;
	quick_sort(to_sort, left, left + count -1);
	quick_sort(to_sort, left + count,right);
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode  newListNode(vector<double> input) {

	auto it = input.begin();
	
	ListNode L(*it);
	auto nl = &L;
	for (it++ ; it != input.end();it++) {
		nl->next = new ListNode(*it);
		nl = nl->next;
	}
	return L;
}
int printListNode(ListNode toPrint) {
	auto nextLN = &toPrint;
	while (nextLN!=NULL)
	{
		cout << nextLN->val ;
		nextLN = nextLN->next;
		if (nextLN != NULL) {
			cout << " -> ";
		}
		else {
			cout << endl;
		}
	}
	return 0;
}
int main()
{	

	vector<double> t1{ 2,4,3 };
	vector<double> t2{ 5,6,4 };
	ListNode L1 = newListNode(t1);
	ListNode L2 = newListNode(t2);
	cout << "Initialized\n";
	printListNode(L1);
	printListNode(L2);
	// start
	ListNode L3(0);
	auto nl1 = &L1;	
	auto nl2 = &L2;
	auto nl3 = &L3;

	// start
	double up = 0;
	int sum = nl1->val + nl2->val + up;
	up = sum / 10;
	L3.val = sum%10 ;
	// note 
	while (nl1->next != NULL) {

		nl1 = nl1->next;		// next
		nl2 = nl2->next;
		sum = nl1->val + nl2->val + up;
		up = sum / 10;
		//cout << nl1->val << "  " << nl2->val <<"  "<<sum<<"  "<<up << endl;
		nl3->next = new ListNode(sum %10) ;
		nl3 = nl3->next;
	}

	printListNode(L3);
    return 0;
}

/* 
// 原有快速排序
vector<int> x{ 3,5,7,1,9,2,6,8,0,50,3,54,7,2,72,2,6,2,7,8,3,4};
cout << "Before sort\n";
for (int n = 0; n < x.size(); ++n) {
cout << x.at(n) << " ";
}
cout << "\n--------------"<<endl;
//sort_kp(x, 0, x.size()-1);
quick_sort(x, 0, x.size()-1);
cout << "\n after sorted :\n";
for (int n = 0; n != x.size(); ++n) {
cout << x.at(n) << " ";
}
*/