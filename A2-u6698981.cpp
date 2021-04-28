#include <iostream>
#include <fstream>
// Add additional libraries you need here
#include <climits> 
#include <cstdlib> 
#include <vector>

using namespace std;
using namespace std::chrono; 
  
void exchange(vector<int>& A, int i, int j) ;
int randomisedSelect(vector<int>& A, int target_index); 
int partition(vector<int>& A, int l, int h);
int randomisedPartition(vector<int>& A, int l, int r);

int * findMedian(vector<int>& arrayX, vector<int>& arrayY, int n) {

	int x = randomisedSelect(arrayX, n/2);
	int y = randomisedSelect(arrayY, n/2);

	static int returnValues[2] = {x, y}; 

	return returnValues; 
}

int randomisedSelect(vector<int>& A, int target_index) {
    int l = 0;
    int r = A.size() - 1;

    bool even; 

    int partition_index = -1;

    while (true) {
        partition_index = randomisedPartition(A, l, r);

        if (target_index == partition_index) {
            break; 
        } 
        if (partition_index < target_index) {
            l = partition_index + 1;
        }  else {
            r = partition_index - 1;
        }
    }

    return A[partition_index];
}

int randomisedPartition(vector<int>& A, int l, int r) {
	int n = r - l + 1;
	int i = rand() % n; 
	exchange(A, r, i + l); 
	return partition(A, l, r); 
}

int partition(vector<int>& A, int l, int r) {
    exchange(A, l, r);
    
    int i = l;
    for (int j = l; j < r; j++) {
        if (A[j] > A[r]) {
            exchange(A, i, j);
            i++;
        }
    }
    
    exchange(A, i, r);
    return i;
}

inline void exchange(vector<int>& A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please supply the name of the input file\n";
    } 
    else { 
		// Read input
		ifstream inFile(argv[1]);
		int n, x, y;
		inFile >> n;

        std::vector<int> xArray(n);
        std::vector<int> yArray(n);

		for (int i = 0; i < n; i++) {
			inFile  >> x >> y;
			// Store x and y data
			xArray[i] = x; 
			yArray[i] = y; 
		}
		inFile.close();  		

		int xh, yh;
		// Place your algorithm here
		// If you need to create a function, place the function above the main function
		// The results of your algorithm should be placed in variable xh and yh
		int *p; 

		p = findMedian(xArray, yArray, n); 

		xh = p[0]; 
		yh = p[1]; 

        cout << xh << " " << yh << "\n";

    }

    return 0;
}
