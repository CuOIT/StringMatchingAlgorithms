//#include<bits/stdc++.h>
//using namespace std;
//
//////RABIN-KARP ALGORITHM
////Hash a string into a value
//int countRB=0;
//const int mod = 10007;
//const int d=23;
//long int hash(string str,int n) {
//	long int HashValue = 0;
//	for (int i = 0; i<n; i++){
//		HashValue = (d * HashValue + str[i]) % mod;
////		countRB+=2;
//	}
//	return HashValue;
//}
////Rabin-Karp Algorithm
//vector<int> RabinKarpSearch(string txt, string pat) {
//	clock_t time;
//	int num=0;
//	time = clock();
//	vector<int> indices;
//	int m = pat.length();
//	int n = txt.length();
//	int p;
//	int power = (int)pow(d, m-1) % mod;
//	int* t = new int[n - m + 1];
//	//preprocessing
//	p = hash(pat,m);
//	t[0] = hash(txt,m);
//	//matching
//	for (int s = 0; s < n - m + 1; s++) {
//		if (t[s] == p){
//			bool found = true;
////			countRB++;
//            for (int j = 0; j < m; j++) {
//                if (txt[s+j] != pat[j]) {
//                    found = false;
////                    countRB++;
//                    break;
//                }
//            }
//            if (found) {
//            	num++;
//                for(int i=s;i<s+m;i++)
//                	indices.push_back(i);
//            }
//		}
//		if (s < n - m){
//			int z=s+1;
//			long int tmp1 = t[s] - power*txt[s];
//			t[z] = (d *tmp1 + txt[s+m]) % mod;
//			t[z]=(t[z]+mod)%mod;
////			countRB+=3;
//			
//		}
//	}
//	time=clock()-time;
//    cout<<"This function took "<<(float)time<<" milisec and return "<<num<<" results"<<endl;
//	return indices;
//}

/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;
 
// d is the number of characters in the input alphabet
#define d 256
 
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
const int q=INT_MAX;
vector<int> RabinKarpSearch(string txt, string pat)
{
	clock_t time;
	int num=0;
	time = clock();
	vector<int> indices;
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
 
            if (j == M){
                num++;
            for(int k=i;k<i+M;k++){
            	indices.push_back(k);
			}
		}
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
    }
    	time=clock()-time;
    cout<<"This function took "<<(float)time<<" milisec and return "<<num<<" results"<<endl;
    return indices;
}
 
///* Driver code */
//int main()
//{
//    char txt[] = "GEEKS FOR GEEKS";
//    char pat[] = "GEEK";
// 
//    // we mod to avoid overflowing of value but we should
//    // take as big q as possible to avoid the collison
//    int q = INT_MAX;
// 
//    // Function Call
//    search(pat, txt, q);
//    return 0;
//}
// 
