#include <bits/stdc++.h>

using namespace std;
//rat in a maze
bool ratInmaze(vector<vector<int>>vec,int r,int c,int row,int col)
{
    if(r==row-1&&c==col-1){
            vec[r][c]=1;
        return true;
    }
    if(r>=row||c>=col){

        return false;
    }
    if(vec[r][c]==0){
        return false;
    }
    if(ratInmaze(vec,r+1,c,row,col)==true){
            return true;
    }
    if(ratInmaze(vec,r,c+1,row,col)==true){
        return true;
    }
    vec[r][c]=0;
    return false;


}

//Nqueen problem
bool board[3][3];
int N=3;
bool isSafe(int row,int col){
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(int i=row,j=col;i<N&&j>=0;j--,i++){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}

bool Nqueen(int level){
    if(level==N){
        return true;
    }
    for(int i=0;i<N;i++){

        if(isSafe(i,level)==true){
            board[i][level]=1;
            if(Nqueen(level+1)==true){
                return true;
            }
            board[i][level]=0;
        }
    }
    return false;
}

//Sudoku problem
vector<vector<int>>vec;
bool safe(int r,int c,int N,int col){

    for(int i=0;i<col;i++){
        if(vec[i][c]==N||vec[r][i]==N){
            return false;
        }
    }
    int s=sqrt(col);
    int rs=r-r%s;
    int cs=c-c%s;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++){
            if(vec[i+rs][j+cs]==N){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(vec[i][j]==0){
                break;
            }
        }
    }
    if(i==row&&j==col)
    {
        return true;
    }

    for(int k=1;k<=N;k++){
        if(safe(i,j,k,col))
        {
            vec[i][j]=k;
            if(sudoku(row,col)==true)
            {
                return true;
            }
            vec[i][j]=0;

        }
    }
    return false;

}
int main()
{

    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
            vector<int>temp;
        for(int j=0;j<c;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        vec.push_back(temp);
    }
    cout<<sudoku(r,c);
    return 0;
}

