#include <iostream>
#include <iomanip>
#include <windows.h> 
#include <string>
using namespace std;

struct slinklist 
    { 
    int data; 
    string MCZei;
    string quantity;
    struct slinklist *next; 
    }; 

typedef struct slinklist node; 
node *start = NULL;
int nodectr;

node* getnode() 
{   
    node * newnode = new node; 
    cout<<"Enter your Order: "; 
    cin >> newnode -> MCZei; 
    cout<<"Enter quantity: ";
    cin >> newnode -> quantity; 
    newnode -> next = NULL; 
    return newnode; cout<<endl;
}

int countnode(node *ptr) 
{ 
    int count=0; 
    while(ptr != NULL) 
    { 
        count++; 
        ptr = ptr -> next; 
    }  
}


void createlist(int n) 
{ 
    int i; 
    node *newnode; 
    node *temp; 
    for(i = 0; i < n; i++) 
        { 
        newnode = getnode(); 
        if(start == NULL){
            start = newnode; 
        }
        else
            {
            temp = start; 
            while(temp -> next != NULL) 
            temp = temp -> next; 
            temp -> next = newnode; 
            }
        } 
}

void display() 
{ 
    node *temp; 
    temp = start; 
    cout<<"\nYour Order:"<<endl; 
    if(start == NULL) 
        { 
        cout<<"\n Empty List\n"; 
        return; 
        } 
        else 
        { 
        while(temp != NULL) 
            { 
            cout<< temp -> MCZei;
            cout<<"\t" << temp -> quantity <<"x"<<endl;
            temp = temp -> next; 
            } 
    } 
    cout<<"\n(END)"<<endl; 
} 

void add() 
{ 
    node *newnode, *temp; 
    newnode = getnode(); 
    if(start == NULL) 
        { 
        start = newnode; 
        } 
    else 
        { 
        temp = start; 
        while(temp -> next != NULL) 
        temp = temp -> next; 
        temp -> next = newnode; 
        } 
}

void deletes(node **head, int position){
    node *current = *head;
    node *previous = *head;
    int limit = countnode(*head);
    if(*head == NULL)
        printf("List is empty\n");
    else if(position == 1){
        *head = current -> next;
        free(current);
        current = NULL;
    }
    else if(position < 1 || position > limit){
        cout<<"Invalid Input!";
    }                                                                                                                                                         
    else if(position >= 1 || position <= limit){
        while(position != 1){
            previous = current;
            current = current -> next;
            position--;
        }
        previous->next = current-> next;
        free(current);
        current = NULL;
    }
    else{
        cout<<"Invalid Input!" <<endl;
    }
}

int main() 
{ 
    int pos;
    string ch; 
    int n; int i;
    string bar;
    for(i=0;i<=100;i++)
    {
        bar = "\t\t\e[1mLoading\e[0m";
        bar.append(i,'.');
        cout<<bar<<"\r";
        Sleep(100);
    }
    cout<<setw(105);
    cout<<"\e[1mAvailable Items at McZei\e[0m"<<endl;
    cout<<endl;
    cout<<setw(88);
    cout<<"- CheeseBurger"<<endl;
    cout<<setw(85);
    cout<<"- Spaghetti"<<endl;
    cout<<setw(85);
    cout<<"- Carbonara"<<endl;
    cout<<setw(85);
    cout<<"- Mango Pie"<<endl;
    cout<<setw(90);
    cout<<"- Chicken Bucket"<<endl;
    cout<<setw(80);
    cout<<"- Coke"<<endl;
    cout<<setw(82);
    cout<<"- Sprite"<<endl;
    cout<<setw(81);
    cout<<"- Royal"<<endl;
    while(1) 
    {  
        
        system("Color B0");

         cout<<"\n 1. Create a list of orders ";
         cout<<"\n 2. Add an Item/Order ";  
         cout<<"\n 3. Display Items/Order ";
         cout<<"\n 4. Delete an Item/Order ";
         cout<<"\n 5. Checkout ";
         cout<<endl;
         cout<<"\n What do you want to do?: ";
         cin >> ch;  

            if(ch == "1"){
                cout<<"\n Number of orders you want to create: "; 
                    cin>>n; 
                    createlist(n); 
                    cout<<"\n List created.." <<endl;
                    if(start == NULL) 
                { 
                    cout<<"\n Number of orders you want to create: "; 
                    cin>>n; 
                    createlist(n); 
                    cout<<"\n List created.." <<endl;   
                } 
            }
            else if(ch == "2"){
                add();
                } 
            else if(ch == "3"){ 
               display();
            }
            else if(ch == "4"){ 
                cout<<"What order do you want to delete?: ";
                cin>>pos;
                cout<<"Order has been deleted!";
                deletes(&start, pos);
            }
            else if(ch == "5"){
                cout<<"\nThank you for choosing McZei!"<<endl;
                cout<<"Please for a staff to assist you"<<endl;
                exit(0);
            }
    } 
} 
