/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Proyecto 2A Longest Common Subsequence (LCS)
*/

#include <iostream>
using namespace std;

int LCS(string letter_1, string letter_2){
	int m = letter_1.length();
	int n = letter_2.length();
	int c[m + 1][n + 1];

	for (int i = 1; i <= m; i++){
		c[i][0] = 0;
	}
	
	for (int j = 0; j <= n; j++){
		c[0][j] = 0;
	}
	
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (letter_1[i] == letter_2[j]){
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if (c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
			}
			else{
				c[i][j] = c[i][j-1];
			}
		}
	}
	return c[m][n];
}

int main(){
	int casos, index = 0;
	string palabra_1, palabra_2;
	cin >> casos;
	while(casos > index){
		cin >> palabra_1 >> palabra_2;
		cout << "Case " << index + 1 << ": " << LCS(palabra_1, palabra_2) << endl;
		index++;
	}
	return 0;
}