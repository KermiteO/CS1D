/**************************************************************
 * PROGRAMMER   : Omar Kermiche
 * ASSIGNMENT #7: Double Hashing
 * PROFESSOR    : Jerry Lebowitz
 * CLASS	    : CS1D
 **************************************************************/

#ifndef MAP_H_
#define MAP_H_
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

const int N = 31;

struct Entry
{
	int key;
	string value;
};

class Map
{
public:
	class Iterator;

	Map()
	{
		for(int i = 0; i < N; i++)
		{
			Entry e = {0,""};

			table.push_back(e);
		}

		total = 0;
	}

	Entry find(int key)
	{
		Entry e = {key, ""};

		int hash1 = e.key % N;
		int hash2 = 17 - (e.key % 17);

		if(hash1 == table[hash1].key % N)
		{
			if(hash2 == 17 - (table[hash2].key % 17))
			{
				int j = 0;
				bool hashed = false;

				while(!hashed && j < N)
				{
					int probe = (hash1 + (j*hash2)) % N;

					if(probe != table[j].key % N)
					{
						table[j] = e;
						hashed = true;
					}

					j++;
				}
			}
			else
			{
				table[hash2] = e;
			}
		}
		else
		{
			table[hash1] = e;
		}

		return e;
	}

	void Put(Entry e)
	{
		int elem;
		int j = 0;

		elem = Hash(e.key, j);

		table[elem] = e;

		total++;
	}

	int Hash(int k, int j)
	{
		int hashKey = ((k % N) + j*(17 - k % 17)) % N;

		if(table[hashKey].key == k || table[hashKey].value == "")
		{
			return hashKey;
		}
		else
		{
			return Hash(k, j + 1);
		}
	}

	void Erase(int delKey)
	{
		Entry null = {0, ""};

		table[Hash(delKey, 0)] = null;
	}

	int Size() const {return total;}

	bool empty() const {return table.empty();}

	vector<Entry>::iterator begin()  {return table.begin();}

	vector<Entry>::iterator  end() {return table.end();}

	void Print() const
	{
		for(int i = 0; i < N; i++)
		{
			switch(i)
			{
			case 5:
			case 10:
			case 15:
			case 20:
			case 25: cout << "|->" << endl << endl << "<-";
				break;
			}

			if(table[i].value != "")
			{
				cout << " | "<< table[i].key << "," << table[i].value;

			}
			else
			{
				cout << left << setw(10) << " | ";
			}
		}
	}

private:
	vector<Entry> table;
	int total;
};



#endif /* MAP_H_ */
