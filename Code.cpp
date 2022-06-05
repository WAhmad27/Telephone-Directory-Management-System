#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void View (char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13])
{
	for(int c=0;c<8;c++)
	{
		cout<<first_name[c]<<"\t"<<last_name[c]<<"\t"<<address[c]<<"\t"<<cnumber[c]<<"\t"<<tnumber[c]<<endl;
	}
}

void add (char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13], int &c)
{
	cout<<"Enter the first name: ";
	while(1)
	{
		cin>>first_name[c];
		if(strlen(first_name[c])<=15)
		{
			break;
		}
		else
		{
			cout<<"Name must not be greater than 15 characters.\nEnter again"<<endl;
		}
	}
		cout << "Enter the last name: ";
	while(1)
	{
		cin>>last_name[c];
		if(strlen(last_name[c])<=15)
		{
			break;
		}
		else
		{
			cout<<"Name must not be greater than 15 characters.\nEnter again"<<endl;
		}
	}
	while(1)
	{
		cin.ignore();
		cout<<"Enter the address: "<<endl;
		cin.getline(address[c], 51, '\n');
		if(strlen(address[c])<=50)
		{
			break;
		}
		else
		{
			cout<<"Address must not be greater than 15 characters.\nEnter again"<<endl;
		}
	}
	cout<<"Enter phone number: \nNOTE: The number must start with +92 and should be in the format +92-XXX-XXXXXXXX"<<endl;
	while(1)
	{
		cin>>cnumber[c];
		if (cnumber[c][0]=='+' && cnumber[c][1]=='9' && cnumber[c][2]=='2')
		{
			if(cnumber[c][3]=='-' && cnumber[c][7]=='-' && strlen(cnumber[c])==16)
			break;
			else
			cout<<"The phone number is not in the format. Enter Again in the specific format\n+92-XXX-XXXXXXXX: "<<endl;}
			else
			{
				cout<<"The phone number does not start with +92. Enter Again starting with +92: "<<endl;
			}
		}
	cout<<"Enter the landline number: \nNOTE: The number must start with 0 and should be in the format 0XX-XXXXXXXX"<<endl;
	while(1)
	{
		cin>>tnumber[c];
		if (tnumber[c][0]=='0')
		{
			if(strlen(tnumber[c])==12 && tnumber[c][3]=='-')
			{
				break;
			}
			else
			{
				cout<<"The landline is not in the format. Enter Again in the specific format\n0XX-XXXXXXXX: ";
			}
		}
		else
		{
			cout<<"The landline does not start with 0. Enter Again starting with 0: ";
		}
	}
}

void delete_contact (char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13], int &c)
{
	int i;
	char d[55];
	cout<<"Enter First name, Last Name, address, cell phone number or landline number: ";
	cin>>d;
	for(i=0;i<c;i++)
	{
		if(!strcmp(d,first_name[i]) || !strcmp(d,last_name[i]) || !strcmp(d,address[i]) || !strcmp(d,cnumber[i]) || !strcmp(d,tnumber[i]))
		{
			break;
		}
	}
	i=i-1;
	c=c-1;
	first_name[i][15]='\0',last_name[i][16]='\0',address[i][51]='\0',cnumber[i][17]='\0',tnumber[i][13]='\0';
	swap(first_name[i],first_name[c]), swap(last_name[i],last_name[c]),swap(address[i],address[c]),swap(cnumber[i],cnumber[c]),swap(tnumber[i],tnumber[c]);
	cout<<"Contact deleted!"<<endl;
}

void find_firstname(char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13], int c)
{
	char f[15];
	cout<<"Enter the first name: "<<endl;
	cin>>f;
	for(int i=0;i<c;i++)
	{
		if(!strcmp(f,first_name[i]))
		{
			cout<<first_name[i]<<"\t"<<last_name[i]<<"\t"<<address[i]<<"\t"<<cnumber[i]<<"\t"<<tnumber[i]<<endl;
		}
	}
}

void find_lastname(char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13], int c)
{
	char l[16];
	cout<<"Enter the last name: "<<endl;
	cin>>l;
	for(int i=0;i<c;i++)
	{
		if(!strcmp(l,last_name[i]))
		{
			cout<<first_name[i]<<"\t"<<last_name[i]<<"\t"<<address[i]<<"\t"<<cnumber[i]<<"\t"<<tnumber[i]<<endl;
		}
	}
}

void find_cnumber(char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13], int c)
{
	char cell[17];
	cout<<"Enter the cell phone number: "<<endl;
	cin>>cell;
	for(int i=0;i<c;i++)
	{
		if(!strcmp(cell,cnumber[i]))
		{
			cout<<first_name[i]<<"\t"<<last_name[i]<<"\t"<<address[i]<<"\t"<<cnumber[i]<<"\t"<<tnumber[i]<<endl;
		}
	}
}

void find_tnumber(char first_name[1000][15],char last_name[1000][16], char address[1000][51],char cnumber[1000][17],char tnumber[1000][13], int c)
{
	char t[13];
	cout<<"Enter the landline number: "<<endl;
	cin>>t;
	for(int i=0;i<c;i++)
	{
		if(!strcmp(t,tnumber[i]))
		{
			cout<<first_name[i]<<"\t"<<last_name[i]<<"\t"<<address[i]<<"\t"<<cnumber[i]<<"\t"<<tnumber[i]<<endl;
		}
	}
}

int main()
{
	char first_name[1000][15];
	char last_name[1000][16];
	char address[1000][51];
	char tnumber[1000][13];
	char cnumber[1000][17];
	int c=0;
	char option;
	ifstream fin;
	ofstream fout;
	fin.open("Directory.txt");
	while (!fin.eof())
	{
		fin>>first_name[c];
		fin>>last_name[c];
		fin.getline(address[c],51,'\t');
		fin>>cnumber[c];
		fin>>tnumber[c];
		c++;
	}
	while(1)
	{
		cout<<"*************Menu*************"<<endl;
		cout<<"Enter 1 for viewing the directory"<<endl;
		cout<<"Enter 2 to add a contact"<<endl;
		cout<<"Enter 3 to delete a contact"<<endl;
		//cout<<"Enter 4 to modify a contact"<<endl;
		//cout<<"Enter 5 to sort the list"<<endl;
		cout<<"Enter 6 to find a contact"<<endl;
		cout<<"Enter 7 to exit"<<endl;
		cout<<"Choose an option"<<endl;
		cin>>option;
		{
			if (option == '1')
			{
				cout<<"The Telephone Directory"<<endl;
				cout<<"********************"<<endl;
				View (first_name,last_name,address,cnumber,tnumber);
			}
			else if (option == '2')
			{
				cout<<"Add a contact"<<endl;
				fout.open("Directory_output.txt");
				add(first_name,last_name,address,cnumber,tnumber,c);
				for(int i=0;i<=c;i++)
				{
					fout<<first_name[i]<<"\t"<<last_name[i]<<"\t"<<address[i]<<"\t"<<cnumber[i]<<"\t"<<tnumber[i]<<endl;
				}
				cout<<"Contact added!"<<endl;
				fout.close();
			}
			else if (option == '3')
			{
				cout<<"Delete a contact"<<endl;
				fout.open("Directory_output.txt");
				delete_contact(first_name,last_name,address,cnumber,tnumber,c);
				for(int i=0;i<c;i++)
				fout<<first_name[i]<<"\t"<<last_name[i]<<"\t"<<address[i]<<"\t"<<cnumber[i]<<"\t"<<tnumber[i]<<endl;
				fout.close();
			}
			/*else if (option == '4')
			{
				cout<<"Modify a contact"<<endl;
				cout<<"Enter 1 to edit first name."<<endl;
				cout<<"Enter 2 to edit last name."<<endl;
				cout<<"Enter 3 to edit cell number."<<endl;
				cout<<"Enter 4 to edit landline number."<<endl;
			}
			else if (option == '5')
			{
				cout<<"Sort by"<<endl;
				cout<<"Enter 1 for sorting by first name."<<endl;
				cout<<"Enter 2 for sorting by last name."<<endl;
				cout<<"Enter 3 for sorting by cell number."<<endl;
				cout<<"Enter 4 for sorting by landline number."<<endl;
				cin>>option;
			}*/
			else if (option == '6')
			{
				cout<<"Find by"<<endl;
				cout<<"Enter 1 to find a contact by first name."<<endl;
				cout<<"Enter 2 to find a contact by last name."<<endl;
				cout<<"Enter 3 to find a contact by cell number."<<endl;
				cout<<"Enter 4 to find a contact by landline number."<<endl;
				cin>>option;
				if (option == '1')
				{
					find_firstname(first_name,last_name,address,cnumber,tnumber,c);
				}
				else if (option == '2')
				{
					find_lastname(first_name,last_name,address,cnumber,tnumber,c);
				}
				else if (option == '3')
				{
					find_cnumber(first_name,last_name,address,cnumber,tnumber,c);
				}
				else if (option == '4')
				{
					find_tnumber(first_name,last_name,address,cnumber,tnumber,c);
				}
			}
			else if (option == '7')
			{
				cout<<"Thank you for using!"<<endl;
				break;
			}
			else 
			{
				cout<<"Enter again"<<endl;
			}
		}
	}
	return 0;
}
