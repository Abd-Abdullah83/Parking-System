#include<iostream>
#include <fstream>
using namespace std;
bool isEmpty(char**** ptr, int block, int row, int slot);
void Empty(char**** ptr, int b, int r, int s);
void Park(char**** ptr, int b, int r, int s);
void Unpark(char**** ptr, int b, int* rpb, int** spb, int block, int row, int slot);

void input(char**** ptr, int b, int* rpb, int** spb);
void output(char**** ptr, int b, int* rpb, int** spb);
void Alocation(char**** ptr, int b, int* rpb, int** spb);
void deletion(char**** ptr, int b, int* rpb, int** spb);
void space();
bool inside(char**** ptr, int b, int* rpb, int** spb, int block, int row, int slot);
void LocationMenu(int& block, int& row, int& slot);
int* find(char**** ptr, int b, int *rpb, int **spb, char* p);
void FindMenu(char**** ptr, int b, int* rpb, int** spb);
void SlotInput(char** ptr, int s);
void Shrink(char**** ptr, int b, int* spb[], int block, int row);
void grow(char**** ptr, int b, int* spb[], int block, int row);
void Smart(char**** ptr, int* rpb, int** spb, int block, int& row, int& slot, int xb, int yb);
void Coordinates(int block, int& xb, int& yb);




void input(char**** ptr, int b, int *rpb, int **spb)
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < rpb[i]; j++)
		{
			for (int k = 0; k < spb[i][j]; k++)
			{
				Empty(ptr, i, j, k);
			}
		}
	}
}
void output(char**** ptr, int b, int* rpb, int** spb)
{
	for (int i = 0; i < b; i++) 
	{
		cout << "Block " << i + 1 << ":\n"; 
		for (int j = 0; j < rpb[i]; j++) 
		{
			for (int k = 0; k < spb[i][j]; k++)  
			{
				cout << ptr[i][j][k] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";  
	}
}
bool isEmpty(char**** ptr, int block, int row, int slot)
{
	char* p = new char[6];
	p[0] = 'E', p[1] = 'M'; p[2] = 'P', p[3] = 'T', p[4] = 'Y', p[5] = '\0';
	int j = 0;
	bool result = true;

	while (p[j] != '\0')
	{
		if (p[j] != ptr[block - 1][row - 1][slot - 1][j])
		{
			result = false;
			break;
		}
		j++;
	}

	delete[] p;
	return result;
}
bool inside(char**** ptr, int b, int* rpb, int** spb,int block, int row, int slot)
{
	if (block < 1 || block > b)
	{
		cout << "\nInvalid Block!\n";
		return false;
	}

	if (row < 1 || row > rpb[block - 1])
	{
		cout << "\nInvalid Row!\n";
		return false;
	}

	if (slot < 1 || slot > spb[block - 1][row - 1])
	{
		cout << "\nInvalid Slot!\n";
		return false;
	}

	if (!(isEmpty(ptr, block, row, slot)))
	{
		cout << "Slot is Already contain : " << ptr[block - 1][row - 1][slot - 1];
		return false;
	}
	return true;
}
void Alocation(char**** ptr, int b, int *rpb, int** spb)
{
	for (int i = 0; i < b; i++)
	{
		cout << "Enter rows for Block " << i + 1 << ": ";
		cin >> rpb[i];

		ptr[i] = new char** [rpb[i]];
		spb[i] = new int[rpb[i]];

		for (int j = 0; j < rpb[i]; j++)
		{
			cout << "Enter slots for Row " << j + 1 << ": ";
			cin >> spb[i][j];

			ptr[i][j] = new char* [spb[i][j]];

			for (int k = 0; k < spb[i][j]; k++)
			{
				Empty(ptr, i, j, k);
			}
		}
	}

}
void deletion(char**** ptr, int b, int *rpb, int **spb)
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < rpb[i]; j++)
		{
			for (int k = 0; k < spb[i][j]; k++)
			{
				delete[]ptr[i][j][k];
			}
			delete[]ptr[i][j];
		}
		delete[]ptr[i];
	}
	delete[]ptr;
}
void SlotInput(char** ptr, int s)
{
	for (int i = 0; i < s; i++)
	{
		ptr[i] = new char[6];
		ptr[i][0] = 'E', ptr[i][1] = 'M', ptr[i][2] = 'P', ptr[i][3] = 'T', ptr[i][4] = 'Y', ptr[i][5] = '\0';
	}
}





void Empty(char****ptr, int b, int r, int s)
{
	ptr[b][r][s] = new char[6];
	char* p = new char[6]; 
	p[0] = 'E', p[1] = 'M'; p[2] = 'P', p[3] = 'T', p[4] = 'Y', p[5] = '\0';
	for (int i = 0; i < 6; i++)
	{
		ptr[b][r][s][i] = p[i];
	}
	delete[]p;
}
void Park(char**** ptr, int b, int r, int s)
{
	delete[] ptr[b][r][s];
	ptr[b][r][s] = new char[8];
	cout << "\n---------------------------------------------\n";
	cout << "Enter License of Car i.e (ABC-123) : ";
	for (int i = 0; i < 7; i++)
	{
		cin >> ptr[b][r][s][i];
	}
	ptr[b][r][s][7] = '\0'; 
	cout << "\nCar Successfully Parked" << endl;
	cout << "---------------------------------------------\n";
}
void Unpark(char**** ptr, int b, int* rpb, int** spb, int block, int row, int slot)
{
	if (block < 1 || block > b)
	{
		cout << "\nInvalid Block!\n";
		return ;
	}

	if (row < 1 || row > rpb[block - 1])
	{
		cout << "\nInvalid Row!\n";
		return ;
	}

	if (slot < 1 || slot > spb[block - 1][row - 1])
	{
		cout << "\nInvalid Slot!\n";
		return ;
	}
	if (isEmpty(ptr,block,row,slot))
	{
		cout << "\nSlot is Already : " << ptr[block-1][row-1][slot-1]<<endl;
		return ;
	}
	cout << "\n-----------------------------";
	cout << "\nCar License Number : " << ptr[block - 1][row - 1][slot - 1] <<"\nSuccessfully UnParked" << endl;
	cout << "-----------------------------\n";
	delete[] ptr[block - 1][row - 1][slot - 1];
	ptr[block - 1][row - 1][slot - 1] = new char[6];
	char* p = new char[6];
	p[0] = 'E', p[1] = 'M'; p[2] = 'P', p[3] = 'T', p[4] = 'Y', p[5] = '\0';
	for (int i = 0; i < 6; i++)
	{
		ptr[block - 1][row - 1][slot - 1][i] = p[i];
	}
	delete[]p;
}



void Smart(char**** ptr, int *rpb, int **spb, int block, int& row, int& slot, int xb, int yb)
{
	bool find = false;
	int x, y;
	double dis = 0, minDis = 1000000.0;
	for (int i = 0; i < rpb[block - 1]; i++)
	{
		for (int j = 0; j < spb[block - 1][i]; j++)
		{
			if (isEmpty(ptr, block, i + 1, j + 1))
			{
				x = xb + j * 8;
				y = yb + i * 16;
				dis = sqrt((x - xb) * (x - xb) + (y - yb) * (y - yb));
				if (dis < minDis)
				{
					find = true;
					minDis = dis;
					row = i + 1;
					slot = j + 1;
				}
			}
		}
	}
	if (!find)
	{
		cout << "\bBlock Is Filled! ";
	}
	else
	{
		cout << "\nMinimum Walking Distance : " << minDis << "\nRow : " << row << "\nSlot : " << slot << endl;
		Park(ptr, block - 1, row - 1, slot - 1);
	}
}
void Coordinates(int block, int& xb, int& yb)
{
	ifstream file("block.txt");
	if (!file)
	{
		cout << "File not found!" << endl;
		return;
	}

	int b, x, y;
	bool found = false;

	while (file >> b >> x >> y)
	{
		if (b == block)
		{
			xb = x;
			yb = y;
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "Block coordinates not found in file!\n";
		xb = 0; 
		yb = 0; 
	}

	file.close();
}




int* find(char**** ptr, int b, int *rpb, int **spb,char *p)
{
	int* S =nullptr;
	bool found = false;
	for (int i = 0; i < b && found == false; i++)
	{
		for (int j = 0; j < rpb[i] && found == false; j++)
		{
			for (int k = 0; k < spb[i][j] && found == false; k++)
			{

				int m = 0;
				while (ptr[i][j][k][m] != '\0')
				{
					if (ptr[i][j][k][m] == p[m])
						m++;
					else
						break;

				}
				if (m == 7)
				{
					S = new int[3];
					found = true;
					S[0] = i + 1;
					S[1] = j + 1;
					S[2] = k + 1;
				}

			}
		}
	}
	return S;
}////delete its memory
void grow(char**** ptr, int b,int *spb[], int block, int row)
{
	if (block < 1 || block > b)
	{
		cout << "\nInvalid Block!\n";
		return;
	}
	if (row < 1 || row > spb[block - 1][0]) 
	{
		cout << "\nInvalid Row!\n";
		return;
	}
	int oldSlots = spb[block - 1][row - 1];
	int Ns;//New Slots
	cout << "\nHow much slots do you want (Slots > "<< oldSlots <<" )";
	cin >> Ns;
	if (Ns <= oldSlots)
	{
		cout << "\nNew Slots Must Be Greater than " << oldSlots << endl;
		return;
	}
	if (Ns > oldSlots)
	{
		char** N = new char* [Ns];
		for (int i = 0; i < Ns; i++)
		{
			N[i] = new char[6];
		}
		SlotInput(N, Ns);
		for (int i = 0; i < oldSlots; i++)
		{
			if (!(isEmpty(ptr, block, row, i+1)))
			{
				delete[]N[i];
				N[i] = new char[8];
				for (int j = 0; j < 7; j++)
				{
					N[i][j] = ptr[block - 1][row - 1][i][j];
				}
				N[i][7] = '\0';
			}
		}
		for (int i = 0; i < oldSlots; i++)
			delete[] ptr[block - 1][row - 1][i];
		delete[]ptr[block - 1][row - 1];
		ptr[block - 1][row - 1] = N;
		spb[block - 1][row - 1] = Ns;
		cout << "\n------Done!------\n";
	}
	
}
void Shrink(char**** ptr, int b, int* spb[], int block, int row)
{
	if (block < 1 || block > b)
	{
		cout << "\nInvalid Block!\n";
		return;
	}
	if (row < 1 || row > spb[block - 1][0]) 
	{
		cout << "\nInvalid Row!\n";
		return;
	}
	int oldSlots = spb[block - 1][row - 1];
	int Ns;//New Slots
	cout << "\nHow much slots do you want (Slots < " << oldSlots << " )";
	cin >> Ns;
	if (Ns < oldSlots)
	{
		for (int i = Ns; i < oldSlots; i++)
		{
			if (!isEmpty(ptr, block, row, i+1))
			{
				cout << "Cannot shrink: slot " << i + 1 << " is not empty.\n";
				return;
			}
		}
		char** N = new char* [Ns];
		for (int i = 0; i < Ns; i++)
		{
			N[i] = new char[6];
		}
		SlotInput(N, Ns);
		for (int i = 0; i < Ns; i++)
		{
			if (!(isEmpty(ptr, block, row, i+1)))
			{
				delete[]N[i];
				N[i] = new char[8];
				for (int j = 0; j < 7; j++)
				{
					N[i][j] = ptr[block - 1][row - 1][i][j];
				}
				N[i][7] = '\0';
			}
		}
		for (int i = 0; i <oldSlots; i++)
			delete[] ptr[block - 1][row - 1][i];
		delete[]ptr[block - 1][row - 1];
		ptr[block - 1][row - 1] = N;
		spb[block - 1][row - 1] = Ns;
		cout << "\n------Done!------\n";

	}
	else
	{
		cout << "\nNew Slots Must Be Lesser than " << oldSlots << endl;
	}
}


void space()
{
	cout << "\t\t\t\t";
}

void LocationMenu(int& block, int& row, int& slot)
{
	cout << "\n";
	cout << "    +----------------------+\n";
	cout << "    |  Parking Location    |\n";
	cout << "    +----------------------+\n";
	cout << "    | Block : ";
	cin >> block;
	cout << "    | Row   : ";
	cin >> row;
	cout << "    | Slot  : ";
	cin >> slot;
	cout << "    +----------------------+\n";
}
void FindMenu(char ****ptr,int b,int *rpb,int **spb)
{
	char* p = new char[9];
	int* S = nullptr;
	cout << "\nEnter License of Car i.e (ABC-123) : ";
	for (int i = 0; i < 7; i++)
	{
		cin >> p[i];
	}
	p[8] = '\0';
	S = find(ptr, b, rpb, spb, p);
	if (S!=nullptr)
	{
		cout << "-------VEHICLE FOUND------\nBlock : " << S[0] << "\nRow : " << S[1] << "\nSlot : " << S[2] << endl << endl;
	}
	else
	{
		cout << "------VEHICLE-NOT-FOUND----\nBlock : ";
	}
	delete[]S;
	delete[]p;

}

int main()
{
	int b, r, s, n;
	cout << "Enter the Numbers of Block : ";
	cin >> b;
	char**** ptr = new char*** [b];
	int* rpb = new int[b];
	int** spb = new int* [b];
	Alocation(ptr, b, rpb,spb);
	input(ptr, b, rpb, spb);
	while (1)
	{
		cout << "\nEnter Your Choice : \n1-->) Display Parking Area \n2-->)Park a Car\n3-->)Un-Park a Car\n4-->)Find a Car\n5-->)Smartly Parking of Car\n6-->)Increase Number of Slots\n7-->)Decrease Number of Slots\n8-->)Exit ";
		cin >> n;
		cout << endl;
		switch (n)
		{
			case 1:
			{
				output(ptr, b, rpb, spb);
				break;
			}
			case 2:
			{
				int block, row, slot;
				LocationMenu(block, row, slot);
				if (inside(ptr, b, rpb, spb, block, row, slot))
				{
					Park(ptr, block - 1, row - 1, slot - 1);
				}
				break;
			}
			case 3:
			{
				int block, row, slot;
				LocationMenu(block, row, slot);
				Unpark(ptr, b, rpb, spb, block, row, slot);
				break;;
			}
			case 4:
			{
				FindMenu(ptr, b, rpb, spb);
				break;
			}
			case 5:
			{
				int xb, yb, block, row, slot;
				cout << "\nEnter the Desired-Block Number Available (1 - " << b << ") : ";
				cin >> block;
				Coordinates(block, xb, yb);
				Smart(ptr, rpb, spb, block, row, slot, xb, yb);
				break;
			}
			case 6:
			{
				int block, row;
				cout << "\nEnter the Block For Increasing the Slots : ";
				cin >> block;
				cout << "Enter the Row Number : ";
				cin >> row;
				grow(ptr, b, spb, block, row);
				break;
			}
			case 7:
			{
				int block, row;
				cout << "\nEnter the Block For Decreasing the Slots : ";
				cin >> block;
				cout << "Enter the Row Number : ";
				cin >> row;
				Shrink(ptr, b, spb, block, row);
				break;
			}
			default:
			{
				deletion(ptr, b, rpb, spb);
				return 0;
			}
		}
	}

}

