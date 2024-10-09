#include <iostream>
#include <climits>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

int ch_bottom_up(vector<int> p, int n){

	int c;
	int memoria[n+1];
	
	memoria[0] = 0;
	
	for(int j = 1; j <= n; j++){
		c = INT_MIN;
		for(int i = 0; i < j; i++){
			c = max(c,p[i]+memoria[j-i-1]);
		}
		memoria[j] = c;
	}
	
	return memoria[n];

}

int main(){

    
    int n[13] = {400,800,1600,3200,6400,12800,25600,51200,102400,204800,409600,819200,1638400};
	vector<int> p;
	int k = 0;
	int t = 1;
    
    while(true){
		
		for (int i = t; i <= n[k]; i++){
			p.push_back(rand() % n[k]);
		}
		
		clock_t begin = clock();
		int retorno = ch_bottom_up(p,p.size());
		clock_t end = clock();
		
		double tempo = (end - begin) / (CLOCKS_PER_SEC/1000);
		cout << k+1 << " - TAMANHO DA ENTRADA: " << n[k] << " - TEMPO GASTO: " << tempo <<  " ms - CONVERGINDO P/: " << tempo/pow(n[k],2) << endl;
		
		t = n[k];
		t++;
		k++;
		
		if(k == 13)
			break;	
		
	}
	
	return 0; 
	
}
