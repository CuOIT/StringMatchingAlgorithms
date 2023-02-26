#include<bits/stdc++.h>
using namespace std;
int countK=0;
void computeLPSArray(string pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
            countK+=3;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
            countK+=2;
        }
    }
}

vector<int> KMPSearch(string txt, string pat) {
	int num=0;
	clock_t time;
	time = clock();
	vector<int> indices;
    int m = pat.length();
    int n = txt.length();
    int *lps = new int[m];
    computeLPSArray(pat, m, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
//            countK+=2;
        }
        if (j == m) {	
        	num++;
            for(int k=i-j;k<i;k++){
            	indices.push_back(k);
			}
            j = lps[j - 1];
//            countK++;
        } else if (i < n && pat[j] != txt[i]) {
//        	countK++;
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    time=clock()-time;
    cout<<"This function took "<<(float)time<<" milisec and return "<<num<<" results"<<endl;
    delete[] lps;
    return indices;
}
