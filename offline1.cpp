#include<iostream>
#include<fstream>

//slightly changed
using namespace std;
struct node
{
    int row;
    int col;
    bool visited = false;
    int visitNum=0;
};
int numVisit = 0;
int r = 3;
int c = 3;
node mat[9][9];
int log[9][9];
bool success=false;



void dfs(int row,int col)
{
    //cout<<mat[row][col].visitNum<<endl;
    //cout<<row<<","<<col<<endl;
    if(mat[row][col].visitNum == (r*r - 1))
        {
           // cout<<"got it "<<endl;
            success = true;
            return ;
        }
    //right move
    if((col+1) <= (c-1) && mat[row][col+1].visited == false)
    {
        //cout<<"right"<<endl;

        mat[row][col+1].visited = true;
        mat[row][col+1].visitNum=mat[row][col].visitNum+1;
        dfs(row,col+1);
    }

    //downward move
    if((row+1) <= (r-1) && mat[row+1][col].visited == false)
    {
       // cout<<"downward"<<endl;
        //cout<<row+1<<" , "<<col<<endl;
        mat[row+1][col].visitNum=mat[row][col].visitNum+1;
        mat[row+1][col].visited = true;
        dfs(row+1,col);
    }

    //diagonally left move
    if((row-1) >= 0 && (col-1) >= 0 && mat[row-1][col-1].visited == false)
    {
        //cout<<"diagonally left"<<endl;
        numVisit++;
        mat[row-1][col-1].visitNum=mat[row][col].visitNum+1;
        mat[row-1][col-1].visited = true;
        dfs(row-1,col-1);
    }
    mat[row][col].visited = false;

}

void initLog()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            log[i][j]=0;
        }
    }
}
void refMat()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            mat[i][j].visited=false;
            mat[i][j].visitNum=0;
        }
    }
}
int main()
{

    ofstream output;
    output.open("test.txt");
    output<<"OUTPUT"<<endl<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            mat[i][j].row=i+1;
            mat[i][j].col=j+1;
        }
    }

    for(int i=2;i<=8;i++)
    {

        r=i;
        c=i;
        initLog();
        output<<i<<"X"<<i<<" Matrix"<<endl<<endl;
        for(int j=0;j<r;j++)
        {
            for(int k=0;k<c;k++)
            {
                mat[j][k].visited=true;
                dfs(j,k);
                refMat();
                if(success == true)
                {
                    log[j][k]=1;
                }
                else
                {
                   // cout<<"not possible"<<endl;
                }
                success=false;
            }
        }
        for(int l=0;l<r;l++)
        {
            for(int m=0;m<c;m++)
            {
                output<<log[l][m]<<" ";
            }
            output<<endl;
        }
        output<<endl;
    }


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           // cout<<mat[i][j].row<<","<<mat[i][j].col<<" ";
        }
        //cout<<endl;
    }

}
