#include <iostream>
#include <climits>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

int corte_haste_rec(vector<int> p, int n){

	int c = INT_MIN;
	
	if(n == 0){
		return 0;
	}
	else{
		for(int i = 0; i < n; i++){
			c = max(c,p[i]+corte_haste_rec(p,n-i-1));
		}
	}
	return c;

}

int main(){

    
    int n[22] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
	vector<int> p;
	int k = 0;
	int t = 1;
    
    while(true){
		
		for (int i = t; i <= n[k]; i++){
			p.push_back(rand() % n[k]);
		}
		
		clock_t begin = clock();
		int retorno = corte_haste_rec(p,p.size());
		clock_t end = clock();
		
		double tempo = (end - begin) / (CLOCKS_PER_SEC/1000);
		cout << k+1 << " - TAMANHO DA ENTRADA: " << n[k] << " - TEMPO GASTO: " << tempo <<  " ms - CONVERGINDO P/: " << tempo/pow(2,n[k]) << endl;
	
		t = n[k];
		t++;
		k++;
		
		if(k == 22)
			break;	
		
	}
	
	return 0; 
	
}




