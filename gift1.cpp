/*
ID: braincfk
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Person
{
	string name;
	int account;
	Person()
	{
		account=0;
	}
};

int main()
{
	ofstream fout ("gift1.out");
	ifstream fin("gift1.in");
	
	int n;
	fin >> n;
	Person *group;
	group = new Person[n];
	for(int i=0;i<n;i++)
	{
		string name;
		fin >> name;
		group[i].name =name;
	}
	do
	{
		string name;
		string name1;
		int amountToGive;
		int numberToGive;
		int valueToGive;
		fin >> name;
		fin >> amountToGive;
		fin >> numberToGive;
		if (numberToGive != 0)
		{
			valueToGive = amountToGive / numberToGive * numberToGive / numberToGive;
			for (int i=0; i<n; i++)
			{
				if(group[i].name.compare(name) == 0)
				{
					for(int k=0;k<numberToGive;k++)
					{
						fin >> name1;
						for(int j=0;j<n;j++)
						{
							if(group[j].name.compare(name1) == 0)
							{
								group[j].account += valueToGive;
								group[i].account -= valueToGive;
							}
						}	
					}
				}
			}
		}

	}while(!fin.eof());
	for(int i=0;i<n;i++)
	{
		fout << group[i].name << " " << group[i].account << endl;
	}
	return 0;
}