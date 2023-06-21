#include<iostream>
using namespace std;
struct inventory_item
{
  string item_name;
  int item_id;
  int qty;
  float price_per_item;
  float stock_value;
  inventory_item *nptr;
};
inventory_item *fptr=NULL;
int check(int item_id);
void display();
void finish();
int main()
{
	int option,id,qty,flag,item_id;
	char s;
	while(1)
	{
		cout<<"Select from following\n1.Add Inventory Item\n2.Make an inventory sale\n3.Buy Inventory from supplier\n4.Check stocks\n";
	    cin>>option;
		switch(option)
		{
			case 1:
				{
					
					inventory_item *ptr;
					ptr=new inventory_item;
					
					cout<<"Enter item id: ";
					cin>>item_id;
					ptr->item_id=check(item_id);
					cin.ignore();
					cout<<"Enter item name: ";
					getline(cin,ptr->item_name);
					cout<<"Enter quantity: ";
					cin>>ptr->qty;
					cout<<"Enter price per item: ";
					cin>>ptr->price_per_item;
					ptr->stock_value=ptr->qty*ptr->price_per_item;
					
					        if(fptr==NULL)
		        {
		        	ptr->nptr=NULL;
		        	fptr=ptr;
	        	}
			    
		         else
	        	{
			       inventory_item *currentptr=fptr; 
                   while(currentptr->nptr!=NULL)
                    {
                      currentptr=currentptr->nptr;
                     } 
                      ptr->nptr=NULL; 
                      currentptr->nptr=ptr; 
		        }
                  
                    break;
				}
			case 2:
			    {
			    	cout<<"Following are the items: \nItem Id\tItem name\n";
			    	display();
					cout<<"Select the item id:";
					cin>>id;
					cout<<endl;
					cout<<"Select quantity: ";
					cin>>qty;
					cout<<endl;
					inventory_item *curr_ptr=fptr;
					while(curr_ptr!=NULL)
					{
						if(id==curr_ptr->item_id)
						{
							if(qty>curr_ptr->qty)
							{
							cout<<"Quantity of "<<curr_ptr->item_name<<" not present.Try again."<<endl;
							break;
						    }
						    else
						    {
						    	curr_ptr->qty=curr_ptr->qty-qty;
						    	curr_ptr->stock_value=curr_ptr->qty*curr_ptr->price_per_item;
							    cout<<"Now the total stock value is Rs "<<curr_ptr->stock_value;
							    if(curr_ptr->qty==0)
						        {
						        finish();
						        delete curr_ptr;
						        break;
						        }
						    	break;
							}
						}
						else
						curr_ptr=curr_ptr->nptr;
					}
					break;
				}
            case 4:
			    {
			    	inventory_item *curr_ptr=fptr;
			    	while(curr_ptr!=NULL)
			    	{	
			    	    cout<<"Item id: "<<curr_ptr->item_id<<endl;
						cout<<"Item name: "<<curr_ptr->item_name<<endl;
						cout<<"Item quantity: "<<curr_ptr->qty<<endl;
						cout<<"Stock value: Rs "<<curr_ptr->stock_value<<endl<<endl;
						curr_ptr=curr_ptr->nptr;
					}
					break;
				}
			case 3:
			    {
			    	flag=0;
			    	cout<<"Enter the item id:";
					cin>>id;
					cout<<endl;
					cout<<"Enter quantity: ";
					cin>>qty;
					cout<<endl;
					inventory_item *curr_ptr=fptr;
					while(curr_ptr!=NULL)
					{
						if(id==curr_ptr->item_id)
						{
							curr_ptr->qty=curr_ptr->qty+qty;
						    curr_ptr->stock_value=curr_ptr->qty*curr_ptr->price_per_item;
						    cout<<"Now the total stock value is Rs "<<curr_ptr->stock_value;
							flag=1;
							break;
						}
						else
						curr_ptr=curr_ptr->nptr;
					}
					if(flag==0)
					{
						cout<<"ID not found"<<endl;
						break;
					}
					break;
			    }	  							
	    }
		cout<<"\nPress A to continue or B to exit: ";
		cin>>s;
		system("CLS");
		if(s=='A') 
		continue;
		else if(s=='B')
		break;
	}
	return 0;
}
void display()
{
	inventory_item *curr_ptr=fptr;
	while(curr_ptr!=NULL)
	{
		cout<<curr_ptr->item_id<<"\t"<<curr_ptr->item_name<<"\n";
	    curr_ptr=curr_ptr->nptr;
	}
}
void finish()
{
	                
    inventory_item *curr_ptr=fptr;                
    if(fptr->qty==0) 
    {
        fptr=fptr->nptr; 
    }
                
    else
    {
        while(curr_ptr->nptr!=NULL) 
        {
            if(curr_ptr->nptr->qty==0) 
            {
                curr_ptr->nptr=curr_ptr->nptr->nptr;
                break;
            }
            
            else 
            {
                curr_ptr=curr_ptr->nptr;  
            }
        }
    }
}
int check(int item_id)
{
	inventory_item *cptr=fptr;
	if(fptr!=NULL)
	                {
	                	
	                	while(cptr!=NULL)
	                	{
	                		if(item_id==cptr->item_id)
	                		{
	                			cout<<"Id already exists.\nTry again"<<endl;
	                			cout<<"Enter id:";
	                			cin>>item_id;
							}
							else
							cptr=cptr->nptr;
						}
					}
    return item_id;					
}