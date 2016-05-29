#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iomanip>
#include <math.h>
 
using namespace std;

struct BinaryTree{
       int Data; //���� ������
       BinaryTree* Left; //��������� �� ����� �������
       BinaryTree* Right; //��������� �� ������ �������
};

//�������� ��������� ������
void Make_Binary_Tree(BinaryTree** Node, int n){
  BinaryTree** ptr;//��������������� ���������
  while (n > 0) {
    ptr = Node;
    while (*ptr != NULL) {
      if ((double) rand()/RAND_MAX < 0.5) 
        ptr = &((*ptr)->Left);
      else ptr = &((*ptr)->Right);
    }
    (*ptr) = new BinaryTree();
    cout << "������� �������� ";
    cin >> (*ptr)->Data;
    n--;
  }
}

//������ ����� ��������� ������
void PreOrder_BinaryTree(BinaryTree* Node){
  if (Node != NULL) {
    printf ("%3ld",Node->Data);
    PreOrder_BinaryTree(Node->Left);
    PreOrder_BinaryTree(Node->Right);
  }
}

int summ(BinaryTree* Node){
	return 1 + (Node->Left ? summ(Node->Left) : 0) + (Node->Right ? summ(Node->Right): 0);
}

//������� �����
void Sum(BinaryTree* Node, int &sum){
  	if (Node != NULL) {
		Sum(Node->Left,sum);
		if(!Node->Left  && ! Node->Right )
      {
          sum+=Node->Data;
      }
        
        Sum(Node->Right,sum);
		
			    }
}

//������ ��������� ������
void Print_BinaryTree(BinaryTree* Node, int l){
  int i;
  if (Node != NULL) {
    Print_BinaryTree(Node->Right, l+1);
    for (i=0; i< l; i++) cout << "    ";
    printf ("%4ld", Node->Data);
    Print_BinaryTree(Node->Left, l+1);
  }
  else cout << endl;
}

//������������ ������, ���������� ��� �������� ������
void Delete_BinaryTree(BinaryTree* Node){
  if (Node != NULL) {
    Delete_BinaryTree(Node->Left);
    Delete_BinaryTree(Node->Right);
    delete(Node);
  }
}

void main()
{   BinaryTree* BTree = NULL;
    int N,SUM=0;
    setlocale(LC_CTYPE, "Russian");
	cout<< "������� ���-�� ������� ������ ";
	cin>>N;   
    Make_Binary_Tree(&BTree,N);
	 Print_BinaryTree(BTree,N);
	 cout<<"������ �����:"<<endl;
	 PreOrder_BinaryTree(BTree);
	 cout<<endl;
	 Sum(BTree,SUM);
	 cout<<"����� �������������� ����� ������� ������="<<SUM<<endl;
	 Delete_BinaryTree(BTree);

    system("pause");
}



