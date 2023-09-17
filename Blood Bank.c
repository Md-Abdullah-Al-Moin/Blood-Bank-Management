#include <stdio.h>
#include <string.h>
int i=0;
struct Donors{
char name[50];
char bloodgroup[50];
char district[50];
int age;
int number;
}Donors;
struct Donors d[1000];
// insert donor
void add_donor(){
    char name[50],bloodgroup[30],district[30];
    if (i>=1000)
    {
        printf("\n\nSorry cannot add more donors.Array is full");
    }
printf("\n\n------------Add the donor info----------");
fflush(stdin);
printf("\n\nEnter donor name = ");
gets(d[i].name);
fflush(stdin);
printf("Enter blood group = ");
gets(d[i].bloodgroup);
fflush(stdin);
printf("Enter district name = ");
gets(d[i].district);
fflush(stdin);
printf("Enter donor age = ");
scanf("%d",&d[i].age);
printf("Enter phone number = ");
scanf("%d",&d[i].number);
i++;
printf("Donor add successfully...\n");
}
// linear search by blood group and district
void search1_donor (){
    char bg[50];
    char ds[50];
    int f=0;
    int j;
fflush(stdin);
printf ("\n\nEnter donor blood group and disrtrict for search = \n");
printf("Blood Group = ");
gets(bg);
fflush(stdin);
printf("District = ");
gets(ds);
for (int j=0;j<i;j++)
{
    if (strcmp(d[j].bloodgroup,bg)==0&&strcmp(d[j].district,ds)==0)
    {
        f=1;
        printf("Name = %s\n",d[j].name);
        printf("Blood Group = %s\n",d[j].bloodgroup);
        printf("District = %s\n",d[j].district);
        printf("Age = %d\n",d[j].age);
        printf("Phone Number = 0%d",d[j].number);
break;
    }
}
    if(f==0)
printf("Donors Not found");
}
// linear search by blood group
void search2_donor (){
    char bg[50];
    char ds[50];
    int f=0;
    int j;
fflush(stdin);
printf ("\n\nEnter donor blood group for search = \n");
gets(bg);
for (int j=0;j<i;j++)
{
    if (strcmp(d[j].bloodgroup,bg)==0)
    {
        printf("Name = %s\n",d[j].name);
        printf("Blood Group = %s\n",d[j].bloodgroup);
        printf("District = %s\n",d[j].district);
        printf("Age = %d\n",d[j].age);
        printf("Phone Number = 0%d",d[j].number);
        f++;
        break;
    }
}
    if(f==0)
printf("Donors Not found");
}
// delete by name
void delete_donor(){
int j,k,fd=0;
char dname[50];
fflush(stdin);
printf("Enter name for delete = ");
gets(dname);
fflush(stdin);
for (j=0;j<i;j++)
{
    if (strcmp(d[j].name,dname)==0)
    {
        fd=1;
        break;
    }
}
if (fd==0)
{
    printf("Donors not found");
}
for (k=j;k<i-1;k++)
{
    d[j]=d[j+1];
}
i--;
printf("Donors delete successfully.\n");
}
//display donors
void display()
{
    int j;
    int k;
    // sorting use bubble sort
struct Donors temp;
for (j=0;j<i-1;j++)
{
    for (k=0;k<i-1-j;k++)
    {
        if (strcmp(d[k].bloodgroup,d[k+1].bloodgroup)>0)
        {
            temp=d[k];
            d[k]=d[k+1];
            d[k+1]=temp;
        }
    }
}
// display use travarse
    if (i==0)
    {
        printf("No donors in this record.\n");
    }
    printf("\n\n--------List of Donors--------\n");
    for (j=0;j<i;j++)
    {
        printf("Name = %s\n",d[j].name);
        printf("Blood Group = %s\n",d[j].bloodgroup);
        printf("District = %s\n",d[j].district);
        printf("Age = %d\n",d[j].age);
        printf("Phone Number = 0%d",d[j].number);
        printf("\n\n----End----\n\n");
    }

}
// update donor info
void update_donor()
{
    int j,c=0,up,ex=0;
    char uname[50];
    fflush(stdin);
    printf("\n\nEnter name for update information = ");
    gets(uname);
    fflush(stdin);
    for (j=0;j<i;j++)
    {
if (strcmp(d[j].name,uname)==0)
{
    c=1;
    while (!ex){
    printf("\n1.Update name\n");
    printf("2.Update blood group\n");
    printf("3.Update district\n");
    printf("4.Update age\n");
    printf("5.Update phone number\n");
    printf("6.exit\n");
    printf("Enter a option = ");
    scanf("%d",&up);
    switch(up){
case 1:
    fflush(stdin);
    printf("\nName = ");
    gets(d[j].name);
    break;
case 2:
    fflush(stdin);
    printf("\nBlood group = ");
    gets(d[j].bloodgroup);
    fflush(stdin);
    break;
case 3:
    fflush(stdin);
    printf("\nDistrict = ");
    gets(d[j].district);
    fflush(stdin);
    break;
case 4:
   printf("\nAge = ");
   scanf("%d",&d[j].age);
    break;
case 5:
    printf("\nPhone number = ");
    scanf("%d",&d[j].number);
    break;
case 6:
    ex=1;
    break;
default:
    printf("You Enter wrong option. Please Enter right option.\n");
    return;
    }
    }
}
    }
    if (c==0)
    {
        printf("Donors not found");
    }
}
int main()
{
   int n;

   while (1){
   printf("\n\n--------Blood Bank Management System---------\n");
   printf("1. Add Blood donors\n");
   printf("2. Delete Blood donors\n");
   printf("3. Search donors by blood group and district\n");
   printf("4. Search donors by blood group\n");
   printf("5. Update donors info\n");
   printf("6. display all donors\n");
   printf("7. Total donors\n");
   printf("8. Exit\n\n");
   printf("Choose a option = ");
   scanf("%d",&n);
   switch (n)
   {
   case 1:
    add_donor();
    printf("\nEnter any key and back main page...\n");
    getch();
    system("cls");
    break;
   case 2:
    delete_donor();
    printf("\nEnter any key and back main page...\n");
     getch();
    system("cls");
    break;
   case 3:
    search1_donor();
    printf("\nEnter any key and back main page...\n");
     getch();
    system("cls");
    break;
   case 4:
    search2_donor();
    printf("\nEnter any key and back main page...\n");
     getch();
    system("cls");
    break;
   case 5:
    update_donor();

    printf("\nEnter any key and back main page...\n");
     getch();
    system("cls");
    break;
   case 6:
    display();
    printf("\nEnter any key and back main page...\n");
     getch();
    system("cls");
    break;
   case 7:
    printf("Total donors = %d",i);
     printf("\nEnter any key and back main page...\n");
    getch();
    system("cls");
    break;
   case 8:
    exit(0);
    break;
   default:
    printf("You choose wrong option.\nPlease choose right option...\n");
    printf("\nEnter any key and back main page...\n");
    getch();
    system("cls");
   }
   }
}

