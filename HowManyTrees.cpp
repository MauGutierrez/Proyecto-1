/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Proyecto 2E How many trees?
*/

#include <iostream>
using namespace std;

int howManyTrees(int num){
	if (num <= 1){
		return 1;
	}
	else{
		int sum = 0;
		int left, right, root;
		for (root = 1; root <= num; root++){
			left = howManyTrees(root - 1);
			right = howManyTrees(num - root);
			sum += left * right;
		}
		return sum;
	}
}

int main(){
	int nodes;
	cin >> nodes;
	cout << howManyTrees(nodes) << " BTrees" << endl;
	return 0;
}
