#include "ArrayedList.h"

void testType(string message)
{
	cout<<"--------------------------------------------"<<endl<<"\t"<<message<<"\n\n";

}

int main()
{
	ArrayedList<int> l;

	testType("ADD TESTS");

	l.add(6);
	l.add(7);
	l.add(1);
	l.add(4);
	l.displayList();

	l.add(8);
	l.displayList();

	l.add(5);
	l.displayList();

	l.add(2);
	l.displayList();



	testType("DISPLAY TABLE");

	l.display();


	testType("FIND TESTS\n");


	l.displayList();

	int idx = 5;
	cout <<"Found element: " << l.getElement(idx) << " At pos " << idx << endl;

	idx = 0;
	cout <<"Found element: " <<  l.getElement(idx) << " At pos " << idx << endl;



	testType("REMOVE TESTS\n");

	l.displayList();
	idx = 0;
	l.remove(0);
	l.displayList();

	idx = 1;
	l.remove(idx);
	l.displayList();

	idx = 5;
	l.remove(idx);

	cout<<endl<<endl;








	return 0;
}

