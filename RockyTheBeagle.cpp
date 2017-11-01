/* 
	Alumno: Gerardo Mauricio Gutiérrez Quintana
	Matricula: A00815174
	Proyecto 2D Rocky the Beagle
*/

#include <iostream>
using namespace std;

const int INF = 1000;
int L[105], T[105];
int W[105][105];
int n, vmin;
bool done[105];


int main(){
	int m, r, cases, count = 0;
	char a, b;
	cin >> cases;
	while(count < cases){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				W[i][j] = INF;
			}
			W[i][i] = 0;
			done[i] = true;
		}
		
		for (int i = 1; i <= m; i++){
			cin >> a >> b >> r;
			W[int(a - 64)][int(b - 64)] = r;
			W[int(b - 64)][int(a - 64)] = r; 
		}

		for (int i = 2; i <= n; i++){
			L[i] = W[1][i];
			T[i] = 1;
		}

		for (int d = 1; d < n - 1; d++){
			int min = INF;
			for (int i = 2; i <= n; i++){
				if (0 <= L[i] && L[i] <= min && done[i] != false){
					min = L[i];
					vmin = i;
				}
			}

			for (int i = 2; i <= n; i++){
				if (L[vmin] + W[vmin][i] < L[i]){
					L[i] = L[vmin] + W[vmin][i];
					T[i] = vmin;
					
				}
			}
			done[vmin] = false;
		}
		int nodoMayor = 0;
		for (int index = 2; index <= n; index++){
			if (T[index] > T[nodoMayor]){
				nodoMayor = index;
			}
		}
		cout << "Case " << count + 1 << ": " << (char) (64 + nodoMayor) << endl;
		count++;
	}
}