// just testing vectors to understand them
// will be useful for turning in, as we have to provide tests

#include <iostream>
#include <vector>
using namespace std;

int main()
{
   // initialize vector w/ array

   int base[5] = { 1, 2, 3, 4, 5 };
   vector<int> tableau(base, base + sizeof(base) / sizeof(int));
   
   //print vector via iterators
   for (vector<int>::iterator it = tableau.begin(); it != tableau.end(); ++it)
      cout << *it << endl;
   cout << endl;

   // checking result
   cout << tableau[0] << endl;
   cout << tableau[1] << endl;
   cout << tableau[2] << endl;
   cout << tableau[3] << endl;
   cout << tableau[4] << endl;
   cout << endl;
   
   // initializing 2 iterators w/ begin()/end()
   vector<int>::iterator it_beg = tableau.begin();
   vector<int>::iterator it_end = tableau.end();

   // copying raw content (reference) of 1st/last element via front()/back()
   int beg_it = tableau.front();
   int end_it = tableau.back();

   cout << beg_it << endl;
   cout << end_it << endl;
   cout << endl;


   // they don't have the same addresses directly, because they are diffent objects
   cout << &tableau[0] << endl; // address of our 1st element
   cout << &it_beg << endl;
   cout << &beg_it << endl;
   cout << endl;

   // but at core, they do stock the same adress (:
   cout << &tableau[0] << endl; // address of our 1st element
   cout << &(*it_beg) << endl; // address of the element pointed by the iterator
   //cout << addressof(*it_beg) << endl; // same but different syntax, since C++11

   cout << endl;
   cout << endl;

   // what if we modify the 1st element ?
   tableau[0] = 99;
   cout << tableau[0] << endl; // ofc updated
   cout << *it_beg << endl; // updated, bc it just points to the same value that has just been changed
   cout << beg_it << endl; // not updated bc it's just an int
   cout << endl;



   cout << &tableau[5] << endl;
   cout << &(*it_end) << endl; // same address
   cout << &end_it << endl; // address of an int containing the copied value
   cout << &it_end << endl; // address of the iterator, so different from our vector's 1st element
   cout << endl;

	// Vector's iterators are of random_access type by default !
	// hence they can be decremented
	cout << "Reverse list print via decrementing iterator :" << endl;
	for ( ; it_end != tableau.begin() - 1; it_end--)
		cout << *it_end << endl;
   cout << endl;

	// they also support [] op
	cout << "Normal list print via [] operator on iterator :" << endl;
	for (int i = 0; i < (int)tableau.size(); i++)
		cout << it_beg[i] << endl;

	// can I declare an input iterator and use it on a vector ? (respecting input iterator's limits)

   return 0;
}