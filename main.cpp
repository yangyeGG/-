#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<termio.h>
#include<cstring>
using namespace std;

int scanKeyboard();
class map{
private:
	int lei[5][5];
	char ditu[5][5];	

public:
	map();
	void show();
	void move();
	void win();
	void defeat();
	void show_lei();
};
map::map()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			lei[i][j]=rand()%2;
			ditu[i][j]='*';
		}
	}
	ditu[0][0]='$';

}
void map::show()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
                {                        
			cout<<ditu[i][j];
			cout<<' ';
		}
		cout<<endl;
	}
}

void map::move()
{
	char c;
	c=(char)scanKeyboard();
	switch(c)
	{
		case 'w':
		{
			system("clear");
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
				{
					if(ditu[i][j]=='$' && (i!=0))
					{
						ditu[i][j]='*';
					
						ditu[i-1][j]='$';
					}
				}
			
			map::show();
			break;	
		}
		case 'a':
		{
			system("clear");
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
				{
					if(ditu[i][j]=='$' && (j!=0))
					{
						ditu[i][j]='*';
					
						ditu[i][j-1]='$';
					}
				}	
			map::show();
			break;	
		}
		case 'd':
		{
			system("clear");
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<5;j++)
				{
					if(ditu[i][j]=='$' && j!=4)
					{
						ditu[i][j]='*';
					
						ditu[i][j+1]='$';
						break;		
					}
				
				}
				
			}
			map::show();
		break;
		}
		case 's':
		{
			system("clear");
			int cnt = 0;
			for(int i=0;i<5;i++)
			{
				if(cnt==1)
					break;
				for(int j=0;j<5;j++)
				{
					if(ditu[i][j]=='$' && (i!=4))
					{
						ditu[i][j]='*';
					
						ditu[i+1][j]='$';
						cnt++;
					}
				}
		
			}
			map::show();
			break;	
                                          
		}
		case '\n':
		{
			for(int i=0;i<5;i++)
				for(int j=0;j<5;j++)
				{
					if(ditu[i][j]=='$')
					{
						if(lei[i][j]==1)
							defeat();
						else 
						{	
							show_lei();
							break;}
					}
				}
			break;
		}	
	}

}

void map::win()
{

}

void map::defeat()
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(lei[i][j]==1)
				cout<<'X'<<' ';
			else 
				cout<<'*'<<' ';
		}
		cout<<endl;
	}
	cout<<"Game Over!"<<endl;
	exit(0);
}

void map::show_lei()
{
	int i,j;
	int cnt=0;
	system("clear");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ditu[i][j]=='$')
			{
				/*if(i=0 && j=0)
					while(lei[i+1][j]==1 || lei[i][j+1]==1 || lei[i+1][j+1]==1)
					cnt++;
				else if(i!=0 && j=0 && i!=4)
					while(lei[i-1][j]==1 || lei[i-1][1]==1 || lei[i][1]==1 || lei[i+1][j+1]==1 || lei[i+1][j]==1)
					cnt++;*/

			int a,b,c,d;
			a=i+1,b=i-1,c=j+1,d=j-1;
			if(a==5) a=4;
			if(b==-1) b=0;
			if(c==5) c=4;
			if(d==-1)d=0;
			if(lei[b][d]) cnt++;
			if(lei[b][j]) cnt++;
			if(lei[b][c]) cnt++;
			if(lei[i][d]) cnt++;
			if(lei[i][a]) cnt++;
			if(lei[a][d]) cnt++;
			if(lei[a][j]) cnt++;
			if(lei[a][c]) cnt++;
			ditu[i][j]=cnt;
			//cout<<cnt<<endl;
			printf("%c\n",ditu[i][j]);
			cout<<ditu[i][j]<<endl;
			ditu[i][j+1]='$';
			break;
			}
			
		}
	}
	show();

}

int main()
{
	srand(time(NULL));
	map a;
	a.show();
while(1)
	a.move();	

	return 0;
}

int scanKeyboard()
{
int in;
struct termios new_settings;
struct termios stored_settings;
tcgetattr(0,&stored_settings);
new_settings = stored_settings;
new_settings.c_lflag &= (~ICANON);
new_settings.c_cc[VTIME] = 0;
tcgetattr(0,&stored_settings);
new_settings.c_cc[VMIN] = 1;
tcsetattr(0,TCSANOW,&new_settings);

in = getchar();

tcsetattr(0,TCSANOW,&stored_settings);
return in;
}
