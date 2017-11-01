/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Proyecto 2C Railroad
*/

#include <iostream>
using namespace std;

bool railroad(int A, int B){
	bool c[A+1][B+1];
	int T1[A+1];
	int T2[B+1];
	int orden[A + B];

	c[0][0] = true;

	for (int i = 0; i < A; i++){
		cin >> T1[i];
	}
	
	for (int j = 0; j < B; j++){
		cin >> T2[j];
	}
	
	for (int i = 0; i < A + B; i++){
		cin >> orden[i];
	}

	for (int i = 1; i <= A; i++){
		c[0][i] = c[0][i-1] && (T1[i-1] == orden[i-1]);
	}

	for (int j = 1; j <= B; j++){
		c[j][0] = c[j-1][0] && (T2[j-1] == orden[j-1]);
	}

	for (int i = 1; i <= A + B; i++){
		for (int j = 1; j <= A + B; j++){
			c[i][j] = (c[i][j-1] && (T1[i - 1] == orden[i + j - 1])) || (c[i-1][j] && (T2[j - 1] == orden[i + j - 1]));
		}
	}
	return c[A][B];
}

int main(){
	int N1, N2;
	cin >> N1 >> N2;
	while(N1 != 0 && N2 != 0){
		railroad(N1, N2) == true ? cout << "Possible" << endl : cout << "not possible" << endl ;
		cin >> N1 >> N2;
	}
	return 0;
}