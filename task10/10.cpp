#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Node
{
public:
	int Id; //����� �������
	int Data; //���� ������� 
	Node** Neighbours; //��������(�������) �������
	int NeighboursCount;
	int MaxNeighboursCount;

	Node(int Id, int Data = 0, int MaxNeighboursCount = 10)
	{
		this->Id = Id;
		this->Data = Data = 0;
		this->Neighbours = new Node * [MaxNeighboursCount];
		this->NeighboursCount = 0;
		this->MaxNeighboursCount = MaxNeighboursCount;
	}

	void AddNeighbor(Node* Neighbor, bool oriented = false) // �������� ������� �������
	{
		if (NeighboursCount == MaxNeighboursCount)
		{
			cout << "��� ������� " << this->Id << " ��������� ����� �������" << endl;
		}
		else
		{
			Neighbours[NeighboursCount] = Neighbor;
			NeighboursCount++;
			if (oriented == false)
			{
				Neighbor->AddNeighbor(this, true);
			}
		}

	}

};


enum Color { white, grey, black };
bool IsBinaryTree(Node* FirstNode, int* colors, Node* PrevNode = nullptr)
{
	bool HaveCycle = false;
	
	int ChildCount = 0;

	bool ChildThreeIsBin = true;

	colors[FirstNode->Id] = grey;

	for (int i = 0; i < FirstNode->NeighboursCount; i++)
	{
		Node* Neighbour = FirstNode->Neighbours[i];
		if (colors[Neighbour->Id] == white)
		{
			ChildThreeIsBin = IsBinaryTree(Neighbour, colors, FirstNode);
			ChildCount++;
		}
		else if (colors[Neighbour->Id] == grey && Neighbour != PrevNode)
		{
			HaveCycle = true;
		}
		colors[FirstNode->Id] = black;
	}

	if (HaveCycle == false && ChildCount <=2 && ChildThreeIsBin == true)
	{
		return true;
	}
	return false;

}

int BFS(Node* node, int NodeCount)
{
	int EdgeCount = 0;
	int* colors = new int[NodeCount];
	for (int i = 0; i < NodeCount; i++)
	{
		colors[i] = white;
	}

	queue<Node*> Queue;
	Queue.push(node);
	while (!Queue.empty())
	{
		Node* fnode = Queue.front();
		Queue.pop();
		colors[fnode->Id] = black;

		for (int i = 0; i < fnode->NeighboursCount; i++)
		{
			Node* NextNode = fnode->Neighbours[i];
			if (colors[NextNode->Id] == white)
			{
				Queue.push(NextNode);
				colors[NextNode->Id] = grey;
				EdgeCount++;
			}
		}
	}

	return EdgeCount;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Node* v1 = new Node(0);
	Node* v2 = new Node(1);
	Node* v3 = new Node(2);
	Node* v4 = new Node(3);

	//2
	//���� ������� ����(�������)
	v1->AddNeighbor(v2);

	v2->AddNeighbor(v3);

	v3->AddNeighbor(v4);

	v4->AddNeighbor(v1);

	cout << "1. �������� �� �������� ���� �������� �������." << endl;
	
	int* colors = new int[4]{ white, white, white, white };
	if (IsBinaryTree(v1, colors))
	{
		cout << "���� �������� �������� �������" << endl;
	}
	else
	{
		cout << "���� �� �������� �������� �������" << endl;
	}

	//���� �� ������� ����(�������)
	Node* n1 = new Node(0);
	Node* n2 = new Node(1);
	Node* n3 = new Node(2);
	Node* n4 = new Node(3);
	Node* n5 = new Node(4);

	n1->AddNeighbor(n2);
	n1->AddNeighbor(n3);

	n2->AddNeighbor(n4);
	n2->AddNeighbor(n5);

	colors = new int[5]{ white, white, white, white, white };
	if (IsBinaryTree(n1, colors))
	{
		cout << "���� �������� �������� �������" << endl;
	}
	else
	{
		cout << "���� �� �������� �������� �������" << endl;
	}

	Node* m1 = new Node(0);
	Node* m2 = new Node(1);
	Node* m3 = new Node(2);
	Node* m4 = new Node(3);
	Node* m5 = new Node(4);

	m1->AddNeighbor(m2);

	m2->AddNeighbor(m3);
	m2->AddNeighbor(m4);
	m2->AddNeighbor(m5);

	colors = new int[5]{ white, white, white, white, white };
	if (IsBinaryTree(m1, colors))
	{
		cout << "���� �������� �������� �������" << endl;
	}
	else
	{
		cout << "���� �� �������� �������� �������" << endl;
	}

	

	//3
	cout << "2. ���������� ����� � ������� ������" << endl;

	cout << "���� V(�������) � 4 ������� ����� �������� ������ � "<< BFS(v1, 4) << " �������" << endl;

	cout << "���� N(�������� ������) � 4 ������� ����� �������� ������ � " << BFS(n1, 5) << " �������" << endl;

	cout << "���� M(������) � 4 ������� ����� �������� ������ � " << BFS(m1, 5) << " �������" << endl;

	//������� ��������� ������ 
	m3->AddNeighbor(m4);
	m4->AddNeighbor(m5);

	cout << "���� M(����������) � 6 ������� ����� �������� ������ � " << BFS(m1, 5) << " �������" << endl;
}