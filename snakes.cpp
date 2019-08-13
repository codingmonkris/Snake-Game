#include <bits/stdc++.h>
using namespace std;
#include<conio.h>

char arr[23][23];
bool flag = 1;
int x1 = 22/2-1,y1 = 22/2;
int x2 = 22/2+1,y2 = 22/2;
int direction = 1;
queue<pair<int,int> > q;
bool endy = 0;
int len = 3;
int cnt;

void food(){
	
	int xx = 22,yy = 22;
	
	while(arr[xx][yy]=='X' || arr[xx][yy]=='o'){
		xx = rand()%22+1,yy = rand()%22+1;
	}
	
	arr[xx][yy] = '*';
	
}

void change(char x){
    
    int dir;
    
    if(x=='a')
      dir = 4;
    else if(x=='s')
      dir = 3;
    else if(x=='d')
      dir = 2;
    else
	  dir = 1; 
		
	if(dir==1){
		if(direction!=3)
		  direction = dir;
	}
	else if(dir==2){
		if(direction!=4)
		  direction = dir;
	}
	else if(dir==3){
		if(direction!=1)
		  direction = dir;
	}
	else{
		if(direction!=2) 
		  direction = dir;
	}
	 
}

void state2(){
	
	arr[x2][y2] = ' ';
	
	pair<int,int> temp = q.front();
	x2 = temp.first,y2 = temp.second;
	arr[x2][y2] = 'o';
	
	q.pop();
	
}

void state1(){
	
	if(direction==1)
        x1--;
	else if(direction==2)
	    y1++;
	else if(direction==3)
	    x1++;
	else
	    y1--;
	
	if(arr[x1][y1]=='*'){
		len++;
		arr[x1][y1] = 'o';
		q.push({x1,y1});
	    food();
		return;
	}
	
	state2();
	
    if(arr[x1][y1]=='o')
	  endy = 1;
	
	arr[x1][y1] = 'o';
	  
    q.push({x1,y1});
			
}

void print(){
	
	for(int i=0;i<23;i++){
    	
		for(int j=0;j<23;j++)
    	  cout<<arr[i][j];
    	
		cout<<'\n';
		  
	}
	
}

int main(){
	
	srand(time(0));
	arr[x1][y1] = 'o';
    arr[x2][y2] = 'o';
    arr[x2-1][y1] = 'o';
    q.push({x2-1,y2}),q.push({x1,y1});
	
	for(int i=0;i<23;i++)
	   arr[0][i] = 'X',arr[22][i] = 'X',arr[i][22] = 'X',arr[i][0] = 'X';
    
    food();

	while(flag){
		
		if (kbhit()) {
            // Change to direction determined by key pressed
            change(getch());
        }
		
		state1();
		
		if(x1==0 || x1==22 || y1==0 || y1==22 || endy==1)
		  break;
		
	    system("cls"); 
		
		print();  
		_sleep(500-cnt);
		cnt++;
		
	}
	   
	cout<<"Your score is "<<len<<"!!!"<<endl;   
    cout<<cnt<<endl;

}
