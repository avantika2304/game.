#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<array>
using namespace std;
 int x[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
 int y[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
class GRID
{
public:

    bool search2D(char *grid, int row, int col,string word, int R, int C)
    {
    if (*(grid+row*C+col) != word[0])
        return false;

    int len = word.length();

    for (int dir = 0; dir < 8; dir++) {

        int k, rd = row + x[dir], cd = col + y[dir];


        for (k = 1; k < len; k++) {

            if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;


            if (*(grid+rd*C+cd) != word[k])
                break;


            rd += x[dir], cd += y[dir];
        }
        if (k == len)
            return true;
    }
    return false;
   }

   vector<pair<int,int>> patternSearch(char *grid, string word,int R, int C)
   {
       vector<pair<int,int>> ma;

    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++)
            if (search2D(grid, row, col, word, R, C))
            {
                pair<int,int> answer;
                answer.first=row;
                answer.second=col;
                ma.push_back(answer);
            }
          return ma;
   }

};

int main()
{
    GRID g1;
    int n,m;
    cout<<"enter the size of table i.e. number of rows and coloume"<<endl;
    cin>>n>>m;
    cout<<"enter the 2-D grid i.e give me the table of characters "<<endl;
    char grid[n][m];
    for(int i=0;i<n;i++)
      {
           for(int j=0;j<m;j++)
            cin>>grid[i][j];
      }
    int choice;
    vector<pair<int,int>> answer;
    string str;
    while(1)
    {
        system("cls");
        cout<<"0-see your grid"<<endl;
        cout<<"1-change the table of characters or 2-D grid"<<endl;
        cout<<"2-enter the string that you are looking for in this grid"<<endl;
        cout<<"3-exit"<<endl;
        cin>>choice;
        
        switch(choice)
        {
        case 0:
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                cout<<grid[i][j]<<" ";
                cout<<endl;
            }
            break;
            
        case 1:
             cout<<"enter the size of table i.e. number f rows and coloume"<<endl;
             cin>>n>>m;
             cout<<"enter the 2-D grid i.e give me the table of characters "<<endl;
              for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                  cin>>grid[i][j];
                  break;
                  
        case 2:
            cout<<"enter the string that you are looking for"<<endl;
            cin>>str;
            answer=g1.patternSearch((char*)grid,str,n,m);
            if(answer.size()==0)
                cout<<"'"<<str<<"' not found on this grid try another one"<<endl;
            else if(answer.size()!=0)
            {
                for(int i=0;i<answer.size();i++)
                    cout<<"'"<<str<<"'"<<" found at index -> ("<<answer[i].first<<","<<answer[i].second<<")"<<endl;
            }

            break;
        case 3:
            exit(0);
            break;
        }
        system("pause");
    }
    return 0;
}