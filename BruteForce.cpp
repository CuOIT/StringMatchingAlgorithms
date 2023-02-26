#include <bits/stdc++.h>
using namespace std;

int countBF=0;
vector<int> BruteForceSearch(string text, string pattern) {
	int num=0;
	clock_t time;
	time = clock();
	vector<int> indices;
    int n = text.length();
    int m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
//        countBF++;
        for (j = 0; j < m; j++) {
//      	countBF+=2;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
			num++;
			for(int k=i;k<i+j;k++){
        	indices.push_back(k);
			}
        }
    }
    time=clock()-time;
    cout<<"This function took "<<(float)time<<" milisec and return "<<num<<" results"<<endl;
    return indices;
//    cout<<"BF:"<<count<<endl;
}

