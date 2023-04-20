#include<iostream>
using namespace std;
class frame
{
    
    public:
    int frameset[9][9];
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
class sudukosolver
{
    public:
    frame k;
    
    sudukosolver()
    {
        if(sudukosolv())
        {
            printGrid();
        }
    }
    bool sudukosolv()
    {
        int row,col,num;
           if(!findunloc(row,col))
            return true;
        for(num=1;num<=9;num++)
        {
            if(issafe(row,col,num))
            {
                k.frameset[row][col]=num;
                if(sudukosolv())
                return true;
                k.frameset[row][col]=0;
            }

        }
        return false;
    }
    bool findunloc(int &row,int &col)
    {
        for(row=0;row<9;row++)
        {
            for(col=0;col<9;col++)
            {
                if(k.frameset[col][col])
                    return true;
            }
        }
        return false;
    }
    bool usedinrow(int row,int num)
    {
        for(int col=0;col<9;col++)
        {
            if(k.frameset[row][col]==num)
            {
                return true;
            }
        }
        return false;
    }
    bool usedincol(int col,int num)
    {
        for(int row=0;row<9;row++)
        {
            if(k.frameset[row][col]==num)
            {
                return true;
            }
        }
        return false;
    }
    bool safebox(int bsrow,int bscol,int num)
    {
        for(int row=0;row<3;row++)
        {
            for(int col=0; col<3;col++)
            {
                if(k.frameset[row+bsrow][col+bscol]==num)
                {
                    return true;
                }
            }
            return false;
        }
    }
    bool issafe(int row,int col,int num)
    {
        return(!safebox(row-row%3,col-col%3,num)&&usedincol(col,num)&&usedinrow(row,num)&&k.frameset[row][col]==0);
    }
 void printGrid()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << k.frameset[row][col] << " ";
        cout << endl;
    }
}
};
int main()
{
sudukosolver k;
}