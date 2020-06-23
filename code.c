/*Simple Login/ Signup Module*/
#include<stdio.h>
struct userdetails
{
	char name[50];
	char password[100];
};
struct userdetails s[100];
int choice,i,j=0,flag=1,x;
int caps=0,small=0,numbers=0,special_characters=0;
char temp_name[50],temp_pass[100];
void signup();
int validate();
int input_valid();
void login();
int main()
{
	while(1)
	{
		printf("\nLogin/Signup Module\n");
		printf("\n1)LOGIN\n2)SIGNUP\n3)EXIT\nEnter Your Choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				login();
				break;
			}
			case 2:
			{
				signup();
				break;	
			}
			case 3:
			{
				exit(1);	
			}
			default:
			{
				printf("\nEnter the valid choice\n");
				break;
			}
		}
	}
}
int validate()
{
	for(i=0;i<100;i++)
	{
		if(!strcmp(temp_name,s[i].name))
		{
			if(!strcmp(temp_pass,s[i].password))
			{
				printf("\nAccount Already Existed!! Please Login\n");
				main();
				break;	
			}
		}
	}
	if(i==100)
	{
		input_valid();
	}	
}
int input_valid()
{
	for(i=0;temp_name[i]!='\0';i++)
		{
			if(!((temp_name[i]>='a' && temp_name[i]<='z')||(temp_name[i]>='A' && temp_name[i]<='Z')))
			{
				printf("\nPlease Enter valid Name\n");
				main();
				flag=0;
				break;	
			}
			else
				flag=1;
		}
		if(flag==1)
		{
			caps=0;small=0;numbers=0;special_characters=0;
			for(i=0;temp_pass[i]!='\0';i++)
			{
				if(temp_pass[i]>='A' && temp_pass[i]<='Z')
					caps++;	
				else if(temp_pass[i]>='a' && temp_pass[i]<='z')
					small++;	
				else if(temp_pass[i]>='0' && temp_pass[i]<='9')
					numbers++;
				else if(temp_pass[i]=='@' || temp_pass[i]=='&' || temp_pass[i]=='#' || temp_pass[i]=='*')
					special_characters++;
			}
			if(caps>=1 && small>=3 && numbers>=3 && special_characters>=1)
			{
				return 1;		
			}
			else
			{
				printf("\n\nYour password is weak, Please Enter the Strong Password!!\n\n");
				main();	
			}
		}
}
void signup()
{
	printf("Enter Your Name\t");	
	scanf("%s",temp_name);
	printf("Enter Your Password\t");
	scanf("%s",temp_pass);
	x=validate();
	if(x==1)
	{
		strcpy(s[j].name,temp_name);
		strcpy(s[j].password,temp_pass);
		j++;
		printf("\n\nSignup Successfully\n\n");	
	}
}
void login()
{
	printf("Enter Your Name\t");
	scanf("%s",temp_name);
	printf("Enter Your Password\t");
	scanf("%s",temp_pass);
	x=input_valid();
	if(x==1)
	{
		for(i=0;i<100;i++)
		{
			if(!strcmp(s[i].name,temp_name))
			{
				if(!strcmp(s[i].password,temp_pass))
				{
					printf("\n\n\nLogin Successful !!\n\nWelcome %s\n\n\n",s[i].name);
					break;	
				}	
				else
				{
					printf("\n\nInvalid Username or Password\n\n");
					break;
				}
			}
			else
			{
				printf("\n\nAccount does not exist! Please signup..\n\n");
				main();
				break;
			}
		}
	}
}

