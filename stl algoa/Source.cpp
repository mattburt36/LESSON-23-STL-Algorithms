/*STL ALGORITHM_1_SEARCH*/
/*#include <algorithm>
#include <vector>
#include <list> 
#include <iostream> 
using namespace std; 

template <typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin(); element != container.cend(); ++element)
		cout << *element << ' ';

	cout << endl; 
}

int main()
{
	vector <int> numsInVec{ 2017, 0, -1 , 42, 10101, 25, 9, 9, 9 };
	list <int> numsInList{ -1, 42, 10101 };

	cout << "The contents of the sample vector are: " << endl;
	DisplayContents(numsInVec);

	cout << "The contents of the sample list are: " << endl; 
	DisplayContents(numsInList);

	cout << "search() for the contents of list in vector:" << endl;
	auto range = search(numsInVec.cbegin(), //Start range to search in
		numsInVec.cend(), //End range to search in
		numsInList.cbegin(), //start range to search for
		numsInList.cend()); //End range to search for 

	//Check if search found a match 
	if (range != numsInVec.end())
	{
		cout << "Sequence in list found in vector at position: "; 
		cout << distance(numsInVec.cbegin(), range) << endl; 
	}

	cout << "Searching {9, 9, 9} in vector using search_n(): " << endl;
	auto partialRange = search_n(numsInVec.cbegin(), //Start range
		numsInVec.cend(), //End range  
		3,   //Count of item to be searched for 
		9 ); //Item to search for

	if (partialRange != numsInVec.end())
	{
		cout << "Sequence {9, 9, 9} found in vector at position: ";
		cout << distance(numsInVec.cbegin(), partialRange) << endl; 
	}

	return 0;

}
*/ 

/*STL ALGORITHM_2_FILL*/
/*
#include <algorithm>
#include <vector> 
#include <iostream>

int main()
{
	using namespace std; 

	//Initialize a sample vector with 3 elements
	vector <int> numsInVec(3);

	//fill all elements in the container with a value of 9
	fill(numsInVec.begin(), numsInVec.end(), 9);

	//increase the size of the vector to hold 6 elements 
	numsInVec.resize(6);

	//fill three elements starting at offset position 3 with value -9
	fill_n(numsInVec.begin() + 3, 3, -9);

	cout << "Contents of the vector are: " << "\n"; 
	for (size_t index = 0; index < numsInVec.size(); ++index)
	{
		cout << "Element [" << index << "] = ";
		cout << numsInVec[index] << "\n"; 
	}

	return 0;

}
*/

/*STL ALGORITHM_3_GENERATE*/
/*
#include <algorithm>
#include <vector>
#include <list> 
#include <iostream>
#include <ctime> 

int main()
{
	using namespace std; 
	srand(time(NULL));//seed random generator using time 

	vector <int> numsInVec(5); 
	generate(numsInVec.begin(), numsInVec.end(), rand);

	cout << "Elements in the vector are: ";
	for (size_t index = 0; index < numsInVec.size(); ++index)
		cout << numsInVec[index] << ' ';
	cout << "\n"; 

	list <int> numsInList(5);
	generate_n(numsInList.begin(), 3, rand);

	cout << "Elements in the list are: ";
	for (auto element = numsInList.begin();
		element != numsInList.end();
		++element)
		cout << *element << ' '; 

	return 0;
}
*/

/*STL ALGORITHM_4_FOR_EACH*/
/*#include <algorithm>
#include <iostream> 
#include <vector> 
#include <string>
using namespace std; 

template <typename elementType>
struct DisplayElementKeepCount
{
	int count;
	DisplayElementKeepCount() : count(0) {}

	void operator () (const elementType& element)
	{
		++count;
		cout << element << ' '; 
	}
};

int main()
{
	vector <int> numsInVec{ 2017, 0, -1, 42, 10101, 25 }; 
	
	cout << "Elements in vector are: " << "\n";
	DisplayElementKeepCount<int> functor =
		for_each(numsInVec.cbegin(), //Start of range
			numsInVec.cend(), // End of Range
			DisplayElementKeepCount<int>());//functor
	cout << "\n";

	//Use the state stored in the return value of for_each!
	cout << "'" << functor.count << "' elements displayed" << "\n";

	string str("for_each and strings!");
	cout << "Sample string: " << str << "\n";

	cout << "Characters displayed using lambda:" << "\n";
	int numChars = 0;
	for_each(str.cbegin(),
		str.cend(),
		[&numChars](char c) { cout << c << ' '; ++numChars; });

	cout << "\n";
	cout << "'" << numChars << "' characters displayed" << "\n";

	return 0;
}*/

/*STL ALGORITHM_5_TRANSFORM*/
/*
#include <algorithm> 
#include <string>
#include <vector> 
#include <deque> 
#include <iostream>
#include <functional>

int main()
{
	using namespace std; 

	string str("THIS is a TEst string!");
	cout << "The sample string is: " << str << "\n";

	string strLowerCaseCopy;
	strLowerCaseCopy.resize(str.size());

	transform (str.cbegin(),             //start source range
		       str.cend(),               //end source range 
			   strLowerCaseCopy.begin(), //start dest range 
			   ::tolower);               //unary function 

	cout << "Result of 'transform' on the string with 'tolower':" << "\n";
	cout << "\"" << strLowerCaseCopy << "\"" << "\n" << "\n";

	//Two sample vectors of integers... 
	vector<int> numsInVec1{ 2017, 0, -1, 42, 10101, 25 };
	vector<int> numsInVec2(numsInVec1.size(), -1);

	//A destination range for holding the result of addition
	deque <int> sumInDeque(numsInVec1.size());

	transform(numsInVec1.cbegin(), //start of source range 1
		      numsInVec1.cend(),   //end of source range 1
		      numsInVec2.cbegin(), //start of source range 2
		      sumInDeque.begin(),  //start of dest range
		      plus <int>());	   //binary function 

	cout << "Result of 'transform' using binary function 'plus': " << "\n"; 
	cout << "Index  Vector1 + Vector2 = Result (in Deque)" << "\n";
	for (size_t index = 0; index < numsInVec1.size(); ++index)
	{
		cout << index << "    \t " << numsInVec1[index] << "\t+    ";
		cout << numsInVec2[index] << " \t  =    ";
		cout << sumInDeque[index] << "\n";
		
	}

	return 0; 

} 
*/

/*STL ALGORITHM_6_COPY_REMOVE*/
/*
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std; 

template <typename T>
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin();
		element != container.cend();
		++element)
		cout << *element << ' '; 

	cout << "| Number of elements: " << container.size() << "\n";
}

int main()
{
	list <int> numsInList{ 2017, 0, -1, 42, 10101, 25 };

	cout << "Source (list) contains:" << "\n"; 
	DisplayContents(numsInList);

	// Initialize vector to hold 2x elements as the list 
	vector <int> numsInVec(numsInList.size() * 2); 

	auto lastElement = copy(numsInList.cbegin(), //start source range
							numsInList.cend(), //end source range
							numsInVec.begin()); //start dest range 

	//copy odd numbers from list into vector
	copy_if(numsInList.cbegin(), numsInList.cend(),
		lastElement,
		[](int element) {return ((element % 2) != 0); });

	cout << "Destination (vector) after copy and copy_if:" << "\n"; 
	DisplayContents(numsInVec);

	//Remove all instances of '0', resize vector using erase()
	auto newEnd = remove(numsInVec.begin(), numsInVec.end(), 0);
	numsInVec.erase(newEnd, numsInVec.end());

	//Remove all odd numbers from the vector using remove_if
	newEnd = remove_if(numsInVec.begin(), numsInVec.end(),
		[](int element) {return ((element % 2) != 0);});
	numsInVec.erase(newEnd, numsInVec.end()); //resizing

	cout << "Destination (vector) after remove, remove_if, erase:" << "\n"; 
	DisplayContents(numsInVec);

	return 0; 
}*/

/*STL ALGORITHM_7_REPLACE_REPLACE_IF*/
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

template <typename T> 
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin();
		element != container.cend();
		++element)
		cout << *element << ' ';

	cout << "| Number of elements: " << container.size() << "\n";
}

int main()
{
	vector <int> numsInVec(6); 

	//fill first 3 elements with value 8, last 3 with 5
	fill(numsInVec.begin(), numsInVec.begin() + 3, 8);
	fill_n(numsInVec.begin() + 3, 3, 5); 

	//shuffle container
	random_shuffle(numsInVec.begin(), numsInVec.end());

	cout << "The initial contents of vector: " << "\n";
	DisplayContents(numsInVec);

	cout << "\n" << "'std::replace' value 5 by 8" << "\n";
	replace(numsInVec.begin(), numsInVec.end(), 5, 8); 

	cout << "'std:: replace_if' even values by -1" << "\n";
	replace_if (numsInVec.begin(), numsInVec.end(), [](int element) {return ((element % 2) == 0); }, -1);
	
	cout << "\n" << "Vector after replacements:" << "\n";
	DisplayContents(numsInVec);

	return 0;
}
*/

/*STL ALGORITHM_8_SORT_BINARY_SEARCH_UNIQUE*/
/*
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std; 

template <typename T> 
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin();
		element != container.cend();
		++element)
		cout << *element << "\n"; 
}

int main()
{
	vector<string> vecNames{ "John", "jack", "sean", "Anna" };

	//insert a duplicate
	vecNames.push_back("jack");

	cout << "The initial contents of the vector are: " << "\n"; 
	DisplayContents(vecNames);

	cout << "The sorted vector contains names in the order:" << "\n"; 
	sort(vecNames.begin(), vecNames.end());
	DisplayContents(vecNames);

	cout << "Searching for \"John\" using 'binary_search':" << "\n"; 
	bool elementFound = binary_search(vecNames.begin(), vecNames.end(), "John");

	if (elementFound)
		cout << "Result: \"John\" was found in the vector!" << "\n";
	else cout << "Element not found" << "\n"; 

	//Erase adjecent dupicates
	auto newEnd = unique(vecNames.begin(), vecNames.end());
	vecNames.erase(newEnd, vecNames.end());

	cout << "The contents of the vector after using 'unique':" << "\n"; 
	DisplayContents(vecNames); 

	return 0; 
}*/

/*STL ALGORITHM_9_PARTITION_STABLE_PARTITION*/
/*
#include <algorithm>
#include <vector> 
#include <iostream> 
using namespace std; 

bool IsEven(const int& num) // unary predicate
{
	return ((num % 2) == 0);
}

template <typename T> 
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin();
		element != container.cend();
		++element)
		cout << *element << ' ';

	cout << "| Number of elements: " << container.size() << "\n";
}

int main()
{
	vector <int> numsInVec{ 2017, 0, -1, 42, 10101, 25 };

	cout << "The initial contents: " << "\n"; 
	DisplayContents(numsInVec);

	vector <int> vecCopy(numsInVec);

	cout << "The effect of using partition():" << "\n"; 
	partition(numsInVec.begin(), numsInVec.end(), IsEven);
	DisplayContents(numsInVec);

	cout << "The effect of using stable_partition():" << "\n"; 
	stable_partition(vecCopy.begin(), vecCopy.end(), IsEven); 
	DisplayContents(vecCopy);

	return 0; 
}
*/

/*STL ALGORITHM_10_LOWER_BOUND_UPPER_BOUND*/
/*
#include <algorithm> 
#include <list> 
#include <string>
#include <iostream>
using namespace std; 

template <typename T> 
void DisplayContents(const T& container)
{
	for (auto element = container.cbegin();
		element != container.cend();
		++element)
		cout << *element << "\n"; 
}

int main()
{
	list<string> names{ "John", "Brad", "jack", "sean", "Anna" };

	cout << "Sorted contents of the list are: " << "\n"; 
	names.sort(); 
	DisplayContents(names); 

	cout << "Lowest index where \"Brad\" can be inserted is: "; 
	auto minPos = lower_bound(names.begin(), names.end(), "Brad");
	cout << distance (names.begin(), minPos) << "\n"; 

	cout << "The highest index where \"Brad\" can be inserted is: "; 
	auto maxPos = upper_bound(names.begin(), names.end(), "Brad");
	cout << distance(names.begin(), maxPos) << "\n"; 

	cout << "\n"; 

	cout << "List after inserting Brad in sorted order: " << "\n"; 
	names.insert(minPos, "Brad");
	DisplayContents(names);

	return 0; 
}
*/
