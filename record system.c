#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

struct Data
{
    int id,s_marks,e_marks,m_marks,n_marks;
    char name[20];
    float percentage;
    char grade;
}save_d[50],read_d[50];



void getdata();
void read_data();
void option();
void showdata();
void case_default();
void searchdata();
void deletedata();
//***************************************************************
//                   DECLARATION OF VARIABLES IN PROJECT
//****************************************************************
    int id,s_marks,e_marks,m_marks,n_marks;
    char name[20],address,grade;
    float percentage;
    FILE *fptr;
//***************************************************************
//                   FUNCTION USED IN PROJECT
//****************************************************************
void login() //login//
{
    int num,count=0;
	do
	{
		system("cls");
        if(count>0)
            {
                printf("-------------------\n");
                printf("****Invalid pin****\n");
                printf("-------------------\n");
            }
            printf("Enter the password:   \n");
            scanf("%d",&num);
            count++;
	}while((num!=1234)&&(count<3));   //boundary value//
	if((count<=3) && (num==1234))
        {
            system("cls");
            printf("-------------------------------------------------\n");
            printf("   ***Welcome To Entrance Exam Record System  ***\n");
            printf("-------------------------------------------------\n");
            option();
        }
	else
        {
            printf("----------------------------\n");
            printf("****Invalid login attempt***\n");
            printf("----------------------------\n");
            exit(0);
        }
}

void option() //option for the user//
{
    int choice;
    char inp;
    int n;
    printf("\nPress 1 to enter record of student\n");
    printf("Press 2 to show all data from file\n");
    printf("Press 3 to search records from file\n");
    printf("Press 4 to delete records from file\n");
    printf("Press 5 to exit\n");
    printf("Enter you choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                getdata();
                break;
            }

        case 2:
            {
                read_data();
                break;
            }
        case 3:
            {
               searchdata();
               break;
            }
        case 4:
            {
               deletedata();
               break;
            }
        case 5:
            {
                 printf("\n***Thank you so much***");
                exit(0);
                break;
            }
            default:
            {
                case_default();
                break;
            }
    }

}
void case_default()
{
    char inp;
    printf("\n--Invalid Input--\n");
    printf("\nDo you want to exit or not (Y/N):");
    scanf("%s",&inp);
    if(inp =='Y' || inp =='y' )
    {
        printf("**!!Bye Bye Bye!!**");
        exit(0);
    }
     else if(inp == 'N' || inp == 'n')
     {
         option();
     }
     else
     {
         //printf("\nInvalid selection");
         case_default();
     }
}


void getdata() //takes the input of the student//
{
     char record;
     int i=0;
    do{
            fflush(stdin);
            printf("\nDo you want to enter a record(Y/N) :");
            scanf("%c",&record);
            if(record=='Y' || record=='y')
            {
                FILE*fptr = fopen("record.txt","a");
                printf("\n");
                printf("----------------------------------------\n");
                printf("\nEnter the id no of student:");
                scanf("%d",&id);
                fprintf(fptr,"%d\t",id);
                printf("Enter the name of student:");
                fflush(stdin);
                gets(name);
                fputs(name,fptr);
                fprintf(fptr,"\t");
                printf("Enter the marks obtained in Science: ");
                scanf("%d",&s_marks);
                fprintf(fptr,"%d\t",s_marks);
                printf("Enter the marks obtained in English: ");
                scanf("%d",&e_marks);
                fprintf(fptr,"%d\t",e_marks);
                printf("Enter the marks obtained in Math: ");
                scanf("%d",&m_marks);
                fprintf(fptr,"%d\t",m_marks);
                printf("Enter the marks obtained in Nepali: ");
                scanf("%d",&n_marks);
                fprintf(fptr,"%d\t",n_marks);
                printf("\n");
                printf("\-----------------------------------\n");
                percentage=s_marks+e_marks+m_marks+n_marks/400;
                if(percentage>=60)
                {
                    grade='A';
                }

                else if(percentage>=50 && percentage<60)
                {
                    grade='B';
                }

                else if(percentage>=30 && percentage<50)
                {
                    grade='C';
                }

                else
                {
                    grade='F';
                }
               fprintf(fptr,"%c\n",grade);
               i++;
            }
            else
            {
                option();
            }
            //printf("\n");
            fclose(fptr);

            showdata();
     }while(record!='n');


}

void read_data() //read the data from the file//
{
int id;
int i=0;
char ch;
fptr = fopen("record.txt","r");
printf("\n");
do
{
    fscanf(fptr,"%d\t%s\t %d\t %d\t %d\t %d\t %c\n" ,&save_d[i].id,&save_d[i].name,&save_d[i].s_marks,&save_d[i].e_marks,&save_d[i].m_marks,&save_d[i].n_marks,&save_d[i].grade);
    printf("**The following data are**\n");
    printf("\n");
    printf("ID: %d\n",save_d[i].id);
    printf("Name: %s\n",save_d[i].name);
    printf("Science : %d\n",save_d[i].s_marks);
    printf("English : %d\n",save_d[i].e_marks);
    printf("Math : %d\n",save_d[i].m_marks);
    printf("Nepali : %d\n",save_d[i].n_marks);
    printf("Grade : %c\n",save_d[i].grade);
    printf("\n");
    i++;

}while(!feof(fptr));
fflush(stdin);
printf("Do you want to exit(yes) or go to option(no)? ");
scanf("%c",&ch);
if(ch=='y' || ch=='Y')
{
    exit(0);
}
else
{
    option();
}
fclose(fptr);
}
void searchdata()
{
    int i=0,j=0;
    fptr = fopen("info.txt","r");
    printf("Enter student ID : ");
    scanf("%d",&id);
    printf("\n");

    do
    {
        for(j=0;j<=10;j++)
    {
        fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%c\n",&save_d[i].id,&save_d[i].name,&save_d[i].s_marks,&save_d[i].e_marks,&save_d[i].m_marks,&save_d[i].n_marks,&save_d[i].grade);
        if(save_d[i].id==id)
    {
        printf("ID: %d           RESULT",save_d[i].id);
        printf("\nName: %s",save_d[i].name);
        printf("\nScience : %d",save_d[i].s_marks);
        if(save_d[i].s_marks>=32)
        {
            printf("\t |(PASS)");
        }
        else
        {
            printf("\t |(FAIL)");
        }
        printf("\nEnglish : %d",save_d[i].e_marks);
        if(save_d[i].e_marks>=32)
        {
            printf("\t |(PASS)");
        }
        else
        {
            printf("\t |(FAIL)");
        }
        printf("\nMath : %d",save_d[i].m_marks);
        if(save_d[i].m_marks>=32)
        {
            printf("\t |(PASS)");
        }
        else
        {
            printf("\t |(FAIL)");
        }
        printf("\nNepali : %d",save_d[i].n_marks);
        if(save_d[i].n_marks>=32)
        {
            printf("\t |(PASS)");
        }
        else
        {
            printf("\t |(FAIL)");
        }
        printf("\nGrade : %c",save_d[i].grade);
        j++;
        break;
    }
    else if(id==NULL)
    {
        printf("**Error finding file**");
    }


    }

    }while(!feof(fptr));
    fclose(fptr);


}

void deletedata()
{

    fptr = fopen("record.txt","w");
    printf("\n");
    system("cls");
	int id;
	char fname[20];
	printf("\nEnter the file name:");
    scanf("%s",fname);
	id=remove(fname);
	if(id!=0)
	{
		printf("File %s deleted successfully..!!\n",fname);
	}
	else
	{
		printf("Unable to delete file record %s\n",fname);
		perror("Error Message ");
	}
	getch();


    fclose(fptr);


}

void showdata() //show the entered data//
{
    FILE*fptr = fopen("record.txt","a");
    printf("**You have entered these values***\n");
    printf("------------------------------------\n");
    printf("ID of a student: %d\n",id);
    printf("Name of a student: %s\t\t RESULT",name);
    printf("\nMarks obtained in Science: %d",s_marks);
    if(s_marks>=32)
        {
            printf("\t |(PASS)");
        }
    else
        {
            printf("\t |(FAIL)");
        }
    printf("\nMarks obtained in English: %d",e_marks);
    if(e_marks>=32)
        {
            printf("\t |(PASS)");
        }
    else
        {
            printf("\t |(FAIL)");
        }
    printf("\nMarks obtained in Math: %d",m_marks);
    if(m_marks>=32)
        {
            printf("\t |(PASS)");
        }
    else
        {
            printf("\t |(FAIL)");
        }
    printf("\nMarks obtained in Nepali: %d",n_marks);
    if(n_marks>=32)
        {
            printf("\t |(PASS)");
        }
    else
        {
            printf("\t |(FAIL)");
        }
    printf("\nGrade of a student is %c\n",grade);
    printf("***Successful to write in file***");
        //i++;
}
clrscr();
main()
{
    login();
}
