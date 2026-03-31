//Twe files are given
//the elements of these files should be swapped with each other
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int s,n,m;
    FILE *f,*g,*temp;
    do
    {   
        cout<<"Enter the number of elements int the first file"<<endl;
        cout<<"the number should be greater than zero: ";cin>>n;
    } while (n<=0);
    do
    {   
        cout<<"Enter the number of elements int the second file"<<endl;
        cout<<"the number should be greater than zero: ";cin>>m;
    } while (m<=0);
    f=fopen("bfirst.dat","wb+");
    g=fopen("bsecond.dat","wb+");
    if(f==NULL)
    {
        cout<<"Mistake was occured while opening first file"<<endl;
        return 1;
    }
    if(g==NULL)
    {
        cout<<"Mistake was occured while opening second file"<<endl;
        return 1;
    }
    //writing first file elements and printing they
    cout<<"First file elements"<<endl;
    for (int i=0;i<n;i++)
    {
        s=rand()%100+1;
        fwrite(&s,sizeof(s),1,f);
        cout<<s<<" ";
    }
    cout<<endl;
    //writing second file elements and printing they
    cout<<"Second file elements"<<endl;
    for (int i=0;i<m;i++)
    {
        s=rand()%100+1;
        fwrite(&s,sizeof(s),1,g);
        cout<<s<<" ";
    }
    cout<<endl;
    rewind(f);
    rewind(g);
    temp=fopen("temp.dat","wb+");
    while(fread(&s,sizeof(s),1,f)==1)
    {
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(f);
    f=fopen("bfirst.dat","wb+");
    while(fread(&s,sizeof(s),1,g)==1)
    {
        fwrite(&s,sizeof(s),1,f);
    }
    rewind(f);
    rewind(temp);
    fclose(g);
    g=fopen("bsecond.dat","wb+");
    while(fread(&s,sizeof(s),1,temp)==1)
    {
        fwrite(&s,sizeof(s),1,g);
    }
    rewind(g);
    cout<<"First file elements"<<endl;
    while(fread(&s,sizeof(s),1,f)==1)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<"Second file elements"<<endl;
    while(fread(&s,sizeof(s),1,g)==1)
    {
        cout<<s<<" ";
    }
    cout<<endl;
    fclose(f);
    fclose(g);
    fclose(temp);
    return 0;
}