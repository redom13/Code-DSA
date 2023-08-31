#include <bits/stdc++.h>

using namespace std;
char boggle[100][100];
bool isValid(int x,int y){
    return x>=0 && y>=0 && x<row && y <col;
}

int row,col;

void DFS(pair<int,int>src){
    
}