/*ID: brainfck
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet;
	string group;

	fin >> comet;
	fin >> group;

	int cometNumber=1;
	int groupNumber=1;

	for(int i=0;i<comet.length();i++)
	{
		cometNumber *= ((int)comet[i]-64);
	}
	for(int i=0;i<group.length();i++)
	{
		groupNumber *= ((int)group[i]-64);
	}
	if(groupNumber % 47 == cometNumber % 47)
	{
		fout << "GO" << endl;
	}
	else
	{
		fout << "STAY" << endl;
	}
	return 0;
}