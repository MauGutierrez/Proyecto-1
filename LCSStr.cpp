/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Proyecto 2B Longest Common Substring (LCSStr)
*/

#include <iostream>
using namespace std;

int LCSStr(string letter_1, string letter_2){
	int m = letter_1.length();
	int n = letter_2.length();
	int c[m + 1][n + 1];
	int result;

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
				result = max(result, c[i][j]);
			}
			else{
				c[i][j] = 0;
			}
		}
	}
	cout << endl;
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return result;
}

int main(){
	int casos, index = 0;
	string palabra_1, palabra_2;
	cin >> casos;
	while(casos > index){
		cin >> palabra_1 >> palabra_2;
		cout << "Case " << index + 1 << ": " << LCSStr(palabra_1, palabra_2) << endl;
		index++;
	}
	return 0;
}