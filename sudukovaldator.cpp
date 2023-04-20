#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_set>
using namespace std;
class frame
{
    int frameset[9][9];
    public:
        frame()
        {
            mainmenue();
        }
void mainmenue()
        {
            cout<<"welcome! to suduko validator";
            cout<<"\nenter the values manually.";
            readframevalues();
            
        }
    void readframevalues()
    {
        cout<<"\nEnter the specified value when prompted.\n";
        cout<<"Enter 0 if cell is empty.\n\n";
        int row,col;
        for(row=0;row<9;row++)
        {
            for(col=0;col<9;col++)
            {
                int val;
                cout<<"enter value of cell["<<row+1<<"]["<<col+1<<"]";
                cin>>val;
                if(!(val>=0&&val<=9))
                {
                    int n=0;
                    while(n<3)
                    {
                        cout<<"Oops! it seems you entered wrong value\n";
                        cout<<"enter value of cell["<<row+1<<"]["<<col+1<<"]";
                        cin>>val;
                        n++;
                       if((val>=0&&val<=9))
                       {
                        break;
                       }
                    }
                }
                frameset[row][col]=val;
            }
        }
    }
    int getcelval(int row ,int col)
    {
        return frameset[row][col];
    }
};
class sudukovalidator
{   
    public:
    frame k;
    
    sudukovalidator()
    {
        if(isValidSudoku())
        {
            cout<<"\nthe given suduko is valid suduko";
        }
    else{
            cout<<"\nthe given suduko is not an  valid suduko";
        }
    }
bool isValidSudoku() {
        unordered_set<int>ro[9];
        unordered_set<int>col[9];
        unordered_set<int>sem[3][3];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int f=k.getcelval(i,j);
                if(f!=0)
                {
                    if(ro[i].count(f) || col[j].count(f) || sem[i/3][j/3].count(f))
                        return false;  
                }
                ro[i].insert(f);
                col[j].insert(f);
                sem[i/3][j/3].insert(f);
            }
        }
        return true;
    }
};
int main()
{
    sudukovalidator k;
}