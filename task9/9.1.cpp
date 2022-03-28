#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	string Name; //èìÿ âåðøèíû
	int Id; //íîìåð âåðøèíû
	int Data; //äàííûå 
	Node** Neighbours; //ñîñåäíèå(ñìåæíûå) âåðøèíû
	int NeighboursCount;
	int MaxNeighboursCount;

	Node(string Name, int Id, int Data = 0, int MaxNeighboursCount = 10)
	{
		this->Name = Name;
		this->Id = Id;
		this->Data = Data;
		this->Neighbours = new Node*[MaxNeighboursCount];
		this->NeighboursCount = 0;
		this->MaxNeighboursCount = MaxNeighboursCount;
	}

	void AddNeighbor(Node* Neighbor, bool oriented = false) // äîáàâèòü ñìåæíóþ âåðøèíó
	{
		if (NeighboursCount == MaxNeighboursCount)
		{
			cout << "Äëÿ âåðøèíû " << this->Name << " äîñòèãíóò ëèìèò ñîñåäåé" << endl;
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


bool IsSimple(int n) //ïðîâåðêà íà ïðîñòîòó
{
	if (n < 2)
		return false;

	for (int i = 2; i <= n/2; i++)
		if (n % i == 0)
			return false;
	return true;
}

bool IsPerfect(int n) //ïðîâåðêà íà ñîâåðøåííîñòü (ñóììà äåëèòåëåé ðàâíà ñàìîìó ÷èñëó)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
		//Ïðîâåðêà íà äåëèìîñòü áåç îñòàòêà
		if (n % i == 0)
			//Ïðèáàâëÿåì äåëèòåëü ê ñóììàå
			sum += i;
	//Ïðîâåðêà íà ðàâåíñòâî ñóììû äåëèòåëåé è ïåðâîíà÷àëüíîãî ÷èñëà
	if (n == sum)
		return true;
	else
		return false;
}

bool IsFriendly(int n1, int n2) //ïðîâåðêà íà äðóæåñòâåííîñòü (ñóììà äåëèòåëåé ïåðâîãî ÷èñëà ðàâíà âòîðîìó ÷èñëó è îáðàòíî)
{
	int sum1 = 0;
	for (int i = 1; i < n1; i++)
		if (n1 % i == 0)
			sum1 += i;

	int sum2 = 0;
	for (int i = 1; i < n2; i++)
		if (n2 % i == 0)
			sum2 += i;
	
	if (sum1 == n2 && sum2 == n1)
		return true;
	else
		return false;
}



void DataDepthSearch(Node* FirstNode, int* visited, int* DataArray, int &DataCount)
{
	DataArray[DataCount] = FirstNode->Data;
	DataCount++;

	visited[FirstNode->Id] = 1;
	for (int i = 0; i < FirstNode->NeighboursCount; i++)
	{
		Node* NextNode = FirstNode->Neighbours[i];
		if (visited[NextNode->Id] == 0)
		{
			DataDepthSearch(NextNode, visited, DataArray, DataCount);
		}
	}
}

enum Color {white, grey, black};

void FindCycle(Node* FirstNode, int* colors, bool& HaveCycle, Node* PrevNode = nullptr)
{
	colors[FirstNode->Id] = grey;
	for (int i = 0; i < FirstNode->NeighboursCount; i++)
	{
		Node* NextNode = FirstNode->Neighbours[i];
		if (colors[NextNode->Id] == white)
		{
			FindCycle(NextNode, colors, HaveCycle, FirstNode);
		}
		else if(colors[NextNode->Id] == grey && NextNode != PrevNode)
		{
			HaveCycle = true;
			return;
		}
		colors[FirstNode->Id] = black;
	}
}

void DepthSearch(Node* FirstNode, bool* visited)
{
	visited[FirstNode->Id] = 1;
	for (int i = 0; i < FirstNode->NeighboursCount; i++)
	{
		Node* NextNode = FirstNode->Neighbours[i];
		if (visited[NextNode->Id] == 0)
		{
			DepthSearch(NextNode, visited);
		}
	}
}

bool IsConnectivity(Node* FirstNode, int Count)
{
	bool* visited = new bool[Count];
	for (int i = 0; i < Count; i++)
		visited[i] = false;

	DepthSearch(FirstNode, visited);

	for (int i = 0; i < Count; i++)
	{
		if (!visited[i]) 
		{
			return false;
		}
	}
		
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Node* v1 = new Node("v1", 0, 13);
	Node* v2 = new Node("v2", 1, 7);
	Node* v3 = new Node("v3", 2, 6);
	Node* v4 = new Node("v4", 3, 220);
	Node* v5 = new Node("v5", 4, 284);

	v1->AddNeighbor(v2);
	v1->AddNeighbor(v4);

	v2->AddNeighbor(v3);
	v2->AddNeighbor(v4);

	v3->AddNeighbor(v4);

	v4->AddNeighbor(v5);

	
	cout << "1. Îáõîäû ãðàôîâ" << endl;
	//4
	
	int* visited = new int[5]{0,0,0,0,0}; // ïîñåùåííûå âåðøèíû
	int* DataArray = new int[5]; // ìàññèâ äëÿ õðàíåíèÿ ÷èñåë èç âåðøèí
	int DataCount = 0;
	DataDepthSearch(v1, visited, DataArray, DataCount); //îáõîä â ãëóáèíó è ñáîð äàííûõ ñ ãðàôà â ìàññèâ DataArray

	//ïîäñ÷åò
	int SIMPLE_COUNT = 0;
	int PERFECT_COUNT = 0;
	int FRIENDLY_COUNT = 0;

	for (int i = 0; i < DataCount; i++)
	{
		if (IsSimple(DataArray[i]))
		{
			SIMPLE_COUNT++;
		}

		if (IsPerfect(DataArray[i]))
		{
			PERFECT_COUNT++;
		}

		for (int j = i+1; j < DataCount; j++)
		{
			if (IsFriendly(DataArray[i], DataArray[j]))
			{
				FRIENDLY_COUNT+=2;
			}
		}
	}

	cout << "ïðîñòûõ ÷èñåë " << SIMPLE_COUNT << "\nñîâåðøåííûõ ÷èñåë " << PERFECT_COUNT << "\näðóæåñòâåííûõ ÷èñåë " << FRIENDLY_COUNT << endl;


	cout << "2. Öåïè è öèêëû íåîðèåíòèðîâàííîãî ãðàôà." << endl;
	//2
	//ãðàô èìåþùèé öèêë(êâàäðàò)
	bool HaveCycle = false;
	visited = new int[5]{ 0,0,0,0,0 };
	FindCycle(v1, visited, HaveCycle);
	if (HaveCycle)
	{
		cout << "èìååò öèêë"<< endl;
	}
	else
	{
		cout << "íå èìååò öèêë" << endl;
	}

	//ãðàô íå èìåþùèé öèêë(ëîìàíàÿ)
	Node* n1 = new Node("n1", 0, 0);
	Node* n2 = new Node("n2", 1, 0);
	Node* n3 = new Node("n3", 2, 0);

	n1->AddNeighbor(n2);
	n1->AddNeighbor(n3);

	HaveCycle = false;
	int* colors = new int[3]{ white, white, white };
	FindCycle(n1, colors, HaveCycle);
	if (HaveCycle)
	{
		cout << "èìååò öèêë" << endl;
	}
	else
	{
		cout << "íå èìååò öèêë" << endl;
	}


	cout << "3. Ñâÿçíîñòü" << endl;
	//6
	//ïðîâåðêà íà ñâÿçíîñòü îáõîäîì â ãëóáèíó
	//ïðîâåðèì ïðåäûäóùèå 2 ãðàôà(íå îðèåíòèðîâàííûå)
	if (IsConnectivity(v1, 5))
	{
		cout << "ãðàô ñâÿçíûé" << endl;
	}
	else
	{
		cout << "ãðàô íå ñâÿçíûé" << endl;
	}
	
	if (IsConnectivity(n1, 3))
	{
		cout << "ãðàô ñâÿçíûé" << endl;
	}
	else
	{
		cout << "ãðàô íå ñâÿçíûé" << endl;
	}

	//ïðîâåðèì òðåòèé îðèåíòèðîâàííûé ãðàô

	Node* m1 = new Node("m1", 0);
	Node* m2 = new Node("m2", 1);
	Node* m3 = new Node("m3", 2);
	Node* m4 = new Node("m4", 3);

	m1->AddNeighbor(m2, true);

	m3->AddNeighbor(m2, true);

	m4->AddNeighbor(m1, true);
	m4->AddNeighbor(m3, true);


	if (IsConnectivity(m1, 4))
	{
		cout << "ãðàô ñâÿçíûé" << endl;
	}
	else
	{
		cout << "ãðàô íå ñâÿçíûé" << endl;
	}

}
