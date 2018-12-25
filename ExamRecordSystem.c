// Students Entrance Record System


//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include<stdio.h>
#include<conio.h>

//***************************************************************
//                   DECLARATION OF VARIABLES IN PROJECT
//****************************************************************

    int id,s_marks,e_marks,m_marks,n_marks;
    char name,address,grade;
    float percentage;
    FILE *fptr;



//***************************************************************
//                   FUNCTION USED IN PROJECT
//****************************************************************
void login(){
int i,num,count=0;
	do
	{
		system("cls");
			if(count>0)
	{
		printf("Invalid pin:\n");
	}
	printf("Enter the password:\n");
	scanf("%d",&num);
	count++;
	}
	while((num!=1234)&&(count<3));   //boundary value//
	if(count<3)
	{
		system("cls");
		printf("Welcome");
	}
	else if(count<3)
	{
		printf("Invalid login attempt");
	}
	choice();

}


    void calculate()
    {
         percentage=s_marks+e_marks+m_marks+n_marks/4.0;

         if(percentage>=60)
            grade='A';
        else if(percentage>=50 && percentage<60)
            grade='B';
        else if(percentage>=30 && percentage<50)
            grade='C';
        else
            grade='F';
    }
    void choice()
    {
        int p,loop;
        printf("\n1.Enter records");
        printf("\n2.Show Data");
        printf("\n3.Show results");
        printf("\nEnter your choice:");
        scanf("%d",&p);
        switch(p)
        {
        case 1:
            {
                printf("\nEnter records");
                break;
            }

              case 2:
            {
                printf("\nShow Data");
                break;
            }
              case 3:
            {
                printf("\nShow results");
                break;
            }
            default:
            {
                printf("\nInvalid input");
            }
        }
    }
    void entry()
    {
        printf("\nEnter the id no of student: ");
        scanf("%d",&id);
        printf("\nEnter the name of student: ");
        name=getch();
    }

    void getdata()
    {

        printf("\nEnter the marks obtained in Science: ");
        scanf("%d",&s_marks);
        printf("\nEnter the marks obtained in English: ");
        scanf("%d",&e_marks);
        printf("\nEnter the marks obtained in Math: ");
        scanf("%d",&m_marks);
        printf("\nEnter the marks obtained in Nepali: ");
        scanf("%d",&n_marks);
        calculate();

    }
    void showdata()
    {
        printf("\nID of a student: %d",id);
       printf("\nName of a student: %c",name);
      //  printf("\nAddress of a student: %c",address);
        printf("\nMarks obtained in Science: %d",s_marks);
        printf("\nMarks obtained in English: %d",e_marks);
        printf("\nMarks obtained in Math: %d",m_marks);
        printf("\nMarks obtained in Nepali: %d",n_marks);
        printf("\nGrade of a student is %c",grade);
       // printf("\nDo you want to continue Y/N?");


    }

    //***************************************************************
   //      function to display result menu
  //****************************************************************

    void result()
    {
        int ans,rno;
        char ch;

        printf("\n\nRecord Menu");
        printf("\n\n\n1. Class Result\n\n2. Student Entrance Exam Record System\n\n3.Back to Main Menu");
        printf("\n\n\nEnter Choice (1/2)? ");
        switch(ans)
        {
     case 1 :
       // class_result();
        break;
    case 2 :
    {
        do
       {

            char ans;
            printf("\n\nEnter roll no Of Student : ");
            scanf("%d",rno);
            printf("\n\nDo you want to See More Result (y/n)?");
            scanf("%d",ans);
       }
       while(ans=='y'||ans=='Y');

       break;
    }
    case 3:
        break;
    default:
        printf("\a");
       }
   }


    /*void add_student()
  {
      // *fptr=fopen("C:\Users\Ghost\Desktop\student.txt","a");
    //   *fptr.getdata();
     //  fappend((char*),sizeof(*fptr));
       fclose;
       printf("\nStudent records has been created");
       getch();
   }*/

main(){
 login();
 choice();
    entry();
    getdata();
    showdata();
    result();}





