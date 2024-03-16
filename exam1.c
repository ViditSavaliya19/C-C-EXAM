#include<stdio.h>

struct Emp
{
    int id;
    char name[100],dp[100];
    float salary;
};

void addEmp(struct Emp e1[],int n)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        printf("Enter value of id");
        scanf("%d",&e1[i].id);
        printf("Enter value of Name");
        scanf("%s",&e1[i].name);
        printf("Enter value of dp");
        scanf("%s",&e1[i].dp);
        printf("Enter value of salary");
        scanf("%f",&e1[i].salary);
    }
}

void readData(struct Emp e1[],int n)
{
    int i;

     printf("\n\n ================== Display Data =============== \n\n");
    
    for(i=0;i<n;i++)
    {
        printf("%d %s %s %f\n",e1[i].id,e1[i].name,e1[i].dp,e1[i].salary);
    }
}

void searchData(struct Emp e1[],int n)
{
    int i;
    int empId;

    printf("\n\n ================== Searching ======================== \n\n");
    
    printf("Search Emp id = ");
    scanf("%d",&empId);

    for(i=0;i<n;i++)
    {
        if(e1[i].id==empId)
        {
            printf("%d %s %s %f\n",e1[i].id,e1[i].name,e1[i].dp,e1[i].salary);
        }
    }
}

void updateData(struct Emp e1[],int n)
{
    int i;
    int empId;
    struct Emp temp;

    printf("\n\n ================== Update Data ======================== \n\n");
    
    printf("Update Emp id = ");
    scanf("%d",&empId); 

    temp.id =empId;
    printf("Enter value of Name");
    scanf("%s",&temp.name);
    printf("Enter value of dp");
    scanf("%s",&temp.dp);
    printf("Enter value of salary");
    scanf("%f",&temp.salary);

    for(i=0;i<n;i++)
    {
        if(e1[i].id==empId)
        {
            e1[i] = temp; 
        }
    }

}

int deleteData(struct Emp e1[],int n)
{
    int i,j;
    int empId;
    struct Emp temp;

    printf("\n\n ================== Delete Data ======================== \n\n");
    
    printf("Delete Emp id = ");
    scanf("%d",&empId); 

    for(i=0;i<n;i++)
    {
        if(e1[i].id==empId)
        {
            for(j=i;j<n;j++)
            {
                e1[j]= e1[j+1];
            }
            return 0;

        }
    }
    return 1;

}

void totalSalary(struct Emp e1[],int n)
{
    int i;
    float sum=0;

    printf("\n\n ================== Total Salary =============== \n\n");

    for(i=0;i<n;i++)
    {
        sum =sum+e1[i].salary;
    }

    printf("Total Salary is %f \n\n",sum);
    
}

int main()
{
    char ch='Y';
    struct  Emp e1[100];
    int n,z,cs;

   

    do
    {
        printf("Press 1 for Add Emp Data\n");
        printf("Press 2 for Display Data\n");
        printf("Press 3 for Search Data\n");
        printf("Press 4 for Update Data\n");
        printf("Press 5 for Delete Data\n");
        printf("Press 6 for Salary Total\n");
        printf("Press 7 for Exit\n");

        printf("\n Enter Your choise according To Top Condition \n");
        scanf("%d",&cs);

        switch(cs)
        {
            case 1:
                printf("Enter size of data");
                scanf("%d",&n);
                addEmp(e1,n);

                printf("\n\nPress Y for continues and Exit press N = \n\n");
                scanf(" %c",&ch);
                break;
            case 2:
                readData(e1,n);
                printf("\n\nPress Y for continues and Exit press N = \n\n");
                scanf(" %c",&ch);
                break;
            case 3:
                searchData(e1,n);
                printf("\n\nPress Y for continues and Exit press N = \n\n");
                scanf(" %c",&ch);
                break;
            case 4:
                updateData(e1,n);
                printf("\n\nPress Y for continues and Exit press N = \n\n");
                scanf(" %c",&ch);
                break;
            case 5:
                z = deleteData(e1,n);
                if(z==0)
                {
                    n--;
                    printf("Delete Success Fully\n");
                    readData(e1,n);
                }
                else
                {
                    printf("Delete Failed Id not found\n");
                }
                printf("\n\nPress Y for continues and Exit press N = \n\n");
                scanf(" %c",&ch);
                break;
            case 6:
                totalSalary(e1,n);
                printf("\n\nPress Y for continues and Exit press N = \n\n");
                scanf(" %c",&ch);
                break;
            default :
                ch='N';
        }
    } while (ch!='N');

}