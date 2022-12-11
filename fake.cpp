#include <iostream>
using namespace std;
#include<conio.h>
#include <windows.h> 
#include <stdlib.h>


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
struct node 
{
	struct node *left; 
	char name[100];
	char num[100];
	char dept[100];
	char sx[2];
	char add[100];
	int start;
	
	struct node *right;
	
};


void clear(int clr)
{
	SetConsoleTextAttribute(hConsole, clr);
	system("CLS");
}



node* getnode() 
{   
    node * newnode; 
    newnode = (node *) malloc(sizeof(node));
    
	cout << "Enter ID number:"; 
	cin >> newnode -> num;
	
	cout << "Enter name: \n"; 
	cin >> newnode -> name;
	
	cout <<"Enter your Department:";
	cin >> newnode -> dept;
	
	cout <<"Enter your Sex (f/m):";
	cin >> newnode -> sx;
	
	cout <<"Enter your Address:";
	cin >> newnode -> add;
	
	cout<<"\n\n";
	
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
     
} 

node *start = NULL;

int countnode(node *start) 
{ 
    	if (start == NULL)
		return 0;
	else
		return 1 + countnode(start->right);
}


//node *start = NULL;




void box(int x1, int y1, int x2, int y2)
{
	gotoxy(x1, y1); cout << char(201);
	gotoxy(x2, y1); cout << char(187);
	gotoxy(x1, y2); cout << char(200);
	gotoxy(x2, y2); cout << char(188);

	for (int row = y1+1;row < y2;row++)
	{
		gotoxy(x1, row);cout << char(186);
		gotoxy(x2, row); cout << char(186);
	}
	for (int col = x1+1; col < x2; col++)
	{
		gotoxy(col, y1); cout << char(205);
		gotoxy(col, y2); cout << char(205);
	}

}

void boxchar(int x1, int y1, int x2, int y2,int chr)
{

	for (int row = y1 ; row < y2; row++)
	{
		gotoxy(x1, row); cout << char(chr);
		gotoxy(x2, row); cout << char(chr);
	}
	for (int col = x1; col <=x2; col++)
	{
		gotoxy(col, y1); cout << char(chr);
		gotoxy(col, y2); cout << char(chr);
	}

}

void blanks(int x1, int y1, int x2, int y2,int spceclr,int shdwclr)
{
	int row;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for ( row = y1; row < y2; row++)
	{
		for (int col = x1; col < x2; col++)
		{
			SetConsoleTextAttribute(hConsole, spceclr);
			gotoxy(col, row); cout << char(32);
		}
		SetConsoleTextAttribute(hConsole, shdwclr);
		if (row == y1)
		{
			gotoxy(x2, row); cout << char(220);
		}
		else
		{
			gotoxy(x2, row); cout << char(219);
		}	
		
	}
	for (int col = x1 + 1; col <= x2; col++)
	{
		gotoxy(col, row); cout << char(223);
	}

}

int menu()
{
	int ch,k;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	clear(80);
	blanks(5, 2, 75, 24,31,80);
	boxchar(4, 1, 81, 25,3);
	
	SetConsoleTextAttribute(hConsole, 16);
	boxchar(31, 5, 50, 5, 223);
	gotoxy(50, 4); cout << char(220);
	SetConsoleTextAttribute(hConsole, 244);
	gotoxy(30,4); cout << "\tInternet Library Student Record\n\n";
	blanks(10, 6, 70, 19,71,16);
	SetConsoleTextAttribute(hConsole, 71);
	gotoxy(16, 7);cout << "1. Create a list\n";
    gotoxy(16, 8);cout << "2. Display Record\n";
    gotoxy(16, 9);cout << "3. Add new Student\n";
    gotoxy(16, 10);cout << "4. Delete a Record\n";
    gotoxy(16, 11);cout << "5. Exit (End Program)\n";
	blanks(24, 20, 57, 23, 97, 16);
	SetConsoleTextAttribute(hConsole, 97); 
	gotoxy(26, 21); cout << "Enter your choice: ";
	cin >> ch;
	return ch;
	
}



void display() 
{ 	

	node *temp; 
    temp = start; 
    
    blanks(5, 2, 75, 24, 45, 16);
	SetConsoleTextAttribute(hConsole, 96);
   	gotoxy(25, 5);cout << "\n\tStudents INternet Record  \n\n";
   	cout << "Number:    \tName:            \tDepartment: \tSEX:    \tAddress:\n"; 
   	//cout<<"\nCreate a list first\n\n";  
    if(start == NULL) 
   		cout << "\n Empty List"	;
    else 
    { 
		while(temp != NULL) 
    	{ 
            cout << "\t"<< temp -> num << "\t" << temp -> name <<"\t" << temp -> dept<<"\t" << temp -> sx<<"\t" << temp -> add << endl; 
            temp = temp -> right; 
           
		   if (temp != NULL)
				cout << temp->left << "\n";  
    	}
	}
		cout << "\n\n"; 
		system("PAUSE");
      
} 

void createlist() 
{  
    int numberOfNodes;
   	char name[100];
	char num[100];
	char dept[100];
	char sx[2];
	char add[100];
	node *newnode; 
    node *temp; 
	
	cout << "\nEnter the number student internet record: ";
	
	while (!(cin >> numberOfNodes))
	{
		cout << "\n\tINVALID INPUT!\n\n";
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Enter the number of Studentrecord: \n ";
	}
	
    for(int i = 0; i < numberOfNodes; i++) 
    { 
		newnode = (node *)malloc(sizeof(node)); 
		
		cout << "Enter ID number: "; 
		cin >> newnode -> num; 
   		
		cout << "\nEnter name: "; 
		cin >> newnode -> name; 
    	
		cout << "College Department : (ccsict) : "; 
		cin >> newnode -> dept;
		
		cout << "Enter your sex (f/m): "; 
		cin >> newnode -> sx;
		
		cout << "Enter your address: "; 
		cin >> newnode -> add;
		cout<<"\n";
    	
		newnode -> right = NULL;
    	
        if(start == NULL){
            start = newnode; 
        }
        else
        {
            temp = start; 
            while(temp -> right ) 
            temp = temp -> right; 
            temp->right = newnode;
            newnode -> left = temp; 
        }
    }
	
	cout << "\nList Created\n" << endl;
	
	display(); 
}

void add_node()
{
    int ctr = 1, pos, nodectr = countnode(start); 
	node *newnode, *temp, *prev; 
    
	newnode = getnode();
	 
    cout<<"\nEnter position to insert in: "; 
    cin >> pos;
    
    if(start == NULL) 
	{ 
        start = newnode; 
    } 
    
    else if (pos == 1)
	{ 
    	newnode -> right = start; 
    	start->left = newnode;
    	start = newnode; 
	}
	
	else if (pos == nodectr)
    { 
    	temp = start; 
    	
		while(temp -> right != NULL) 
    	temp = temp -> left; 
        
		temp -> right = newnode; 
    }
	
	else if(pos > 1 && pos < nodectr) 
    { 
        temp = prev = start; 
        
		while(ctr < pos) 
        { 
            prev = temp; 
            temp = temp -> right; 
            ctr++; 
        } 
        
		prev -> right = newnode; 
        newnode -> left = temp; 
    } 
    
	else
    {
    	cout<<"\nInvalid position\n"; 
    }
	
	cout << "\nContact added\n";
	
	display(); 
}

void delete_node() 
{ 
	int ctr = 1, pos, nodectr = countnode(start); 
	node *temp, *prev;
	
	cout<<"\nEnter position of contact to delete: ";  
	cin >> pos;
	
	if(start == NULL) 
    { 
        cout<<"\nThere's no list\n"; 
        return; 
    }
	
	else if(pos == 1) 
	{ 
   	    temp = start; 
   	    start = temp -> right; 
        free(temp); 
         
	} 
	
	else if (pos == nodectr) 
	{ 
        temp = start; 
        prev = start; 
        
		while(temp -> right != NULL) 
        { 
            prev = temp; 
            temp = temp -> right; 
        } 
        
		prev -> left = NULL; 
        free(temp);  
    } 
	
    else if(pos > 1 && pos < nodectr) 
    { 
    	temp = prev = start; 
        	
		while(ctr < pos) 
        { 
            prev = temp; 
            temp = temp -> right; 
            ctr++; 
        }
			 
        prev -> left = temp -> right; 
        free(temp); 
    }	 
    
    else 
    {   
		cout<<"\nInvalid position\n"; 
    }
 	
 	cout <<"\nContact deleted\n";
 	
 	display();
} 

int main()
{
	int ch;
	
    while(true)
    {  
        ch= menu();
        clear(31);
  
    {
	
		
		if (ch == 1 && start == NULL)
		{
			createlist();
		}
		else if (ch == 1 && start != NULL)
		{
			cout << "\nThere's already a list\n";
		}
		else if (ch == 2)
		{
			display();
		}
		else if (ch == 3)
		{
			add_node();
		}
		else if (ch == 4)
		{
			delete_node();
		}
		else if (ch == 5)
		{
			return 0;
		}
		}
	}
	return 0;
}
