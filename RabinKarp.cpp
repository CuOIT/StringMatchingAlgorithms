#include<bits/stdc++.h>
using namespace std;

////RABIN-KARP ALGORITHM
//Hash a string into a value
int countRB=0;
const int mod = 10007;
long int hash(string str,int n) {
	long int HashValue = 0;
	for (int i = 0; i<n; i++){
		HashValue = (10 * HashValue + str[i]) % mod;
//		countRB+=2;
	}
	return HashValue;
}
//Rabin-Karp Algorithm
vector<int> RabinKarpSearch(string txt, string pat) {
	clock_t time;
	int num=0;
	time = clock();
	vector<int> indices;
	int m = pat.length();
	int n = txt.length();
	int p;
	int d = (int)pow(10, m-1) % mod;
	int* t = new int[n - m + 1];
	//preprocessing
	p = hash(pat,m);
	t[0] = hash(txt,m);
	//matching
	for (int s = 0; s < n - m + 1; s++) {
		if (t[s] == p){
			bool found = true;
//			countRB++;
            for (int j = 0; j < m; j++) {
                if (txt[s+j] != pat[j]) {
                    found = false;
//                    countRB++;
                    break;
                }
            }
            if (found) {
            	num++;
                for(int i=s;i<s+m;i++)
                	indices.push_back(i);
            }
		}
		if (s < n - m){
			int z=s+1;
			long int tmp1 = t[s] - d*txt[s];
			t[z] = (10 *tmp1 + txt[s+m]) % mod;
			t[z]=(t[z]+mod)%mod;
//			countRB+=3;
			
		}
	}
	time=clock()-time;
    cout<<"This function took "<<(float)time<<" milisec and return "<<num<<" results"<<endl;
	return indices;
}
