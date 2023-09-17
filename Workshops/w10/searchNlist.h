#ifndef SDDS_SEARCHNIF_H
#include "Collection.h"
using namespace std;
namespace sdds {
	/*
	This function template searches within an array objects and matches with the Key Object.
	If there is a match, it returns true, else it will return false.
	This functions requires an operator of "==" to be able to work as it is needed to match the arrays of objects.
	*/
	template <typename T, typename K>
	bool search(Collection<T>& collection, T arr[], int size, K key) {
		bool ok = false;
		for (int i = 0; i < size; i++) {
			if (arr[i] == key) {
				ok = true;
				collection.add(arr[i]);
			}
		}
		return ok;
	}

	/*
	This function lists out and prints the entire array of objects into an ostream or output.
	This requires the operator "<<" so the objects can be sent to the ostream.
	The function will also print empty objects.
	*/
	template <typename T>
	void listArrayElements(const char* title, const T* array, int size) {
		cout << title << endl;

			for (int i = 0; i < size; i++) {
				if (i < 7) {
					cout << i + 1 << ": " << array[i] << endl;
				}
		}
	}
}
#endif // !SDDS_SEARCHNIF_H
