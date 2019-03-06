#include<iostream>
#include"LinkedList.h"
using namespace std;
int main()
{
	LinkedList Test;
	Test.insertEnd(1);
	Test.insertEnd(2);
	Test.insertEnd(3);
	Test.insertEnd(4);
	Test.insertEnd(5);
	Test.reverse(3);
	Test.display();
	system("pause");
}