// BinaryTree
#include <iostream>

using namespace std;

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDesstructor:\t" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "Tconstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "Tdestructor:\t" << this << endl;
	}
	//				Adding element
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	//			Methods
	void Print(Element* Root)const
	{
		if (Root == nullptr)return;
		Print(Root->pLeft);
		cout << Root->Data << "\t";
		Print(Root->pRight);
	}
	int MinValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pLeft == nullptr)return Root->Data;
		else return MinValue(Root->pLeft);	*/
		return Root->pLeft == nullptr ? Root->Data : MinValue(Root->pLeft);
	}
	int MaxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pRight == nullptr)return Root->Data;
		else return MinValue(Root->pRight);*/
		return Root->pRight == nullptr ? Root->Data : MinValue(Root->pRight);
	}
	int Count(Element* Root)
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	double Sum(Element* Root) const
	{
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	double avg(Element* Root) 
	{
		return Sum(Root) / Count(Root);
	}
	int depth(Element* Root)
	{
		static int a;
		static int b;
		a+= Count(Root->pRight);
		b += Count(Root->pLeft);
		return a >= b ? a : b;
	}
};
class UniqueTree :public Tree
{
public:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите кол-во элементов: "; cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}

	tree.Print(tree.getRoot()); cout << endl;
	cout << "Kол-во элементов: " << tree.Count(tree.getRoot()) << endl;
	cout << "Сумма элементов: " << tree.Sum(tree.getRoot()) << endl;
	cout << "Среднее значение элементов элементов: " << tree.avg(tree.getRoot()) << endl;
	cout << "Глубина дерева: " << tree.Level(tree.getRoot()) << endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.getRoot());
	}
	u_tree.Print(u_tree.getRoot());
}
