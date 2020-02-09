
#ifndef STACKLIST_H_
#define STACKLIST_H_

#include<iomanip>
#include<iostream>
#include<string>
#include<limits>
#include<ios>
#include<sstream>
using namespace std;

template <class Type>
class StackList
{
	public:
		/*******************************
		 **CONSTRUCTOR & DECONSTRUCTOR**
		 *******************************/
		StackList();
		~StackList();

		/**********
		 *MUTATORS*
		 **********/
		void InitializeStack(const Type ARRAYDATA[],
							 const int  AR_SIZE);

		void PushData(Type newData);

		void PopData();

		void DisplayDataTable();

		void FindAndDeleteData(Type delValue);

		/***********
		 *ACCESSORS*
		 ***********/
		Type Top() const;

		bool IsEmpty() const;

		int GetDataCounter() const;

		void Print() const;

	private:
		struct StackNode
		{
			Type 	  dataValue;
			StackNode *next;
		};

		StackNode *head; //PROC - A WHOLE LINK LIST/FRONT OF LIST
		int dataCounter; //PROC&OUT - REPRESENTS THE AMOUNT OF DATA
		};

#endif /* STACKLIST_H_ */
