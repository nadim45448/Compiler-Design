#include<iostream>
using namespace std;
char *removeduplicate(char str[],int n)
{
   int count=0;
   for (int i=0;i<n;i++)
   {
        int j;
        for(j=0;j<i;j++)
        {
            if(str[i]==str[j])
            {
               break;
            }
        }
        if(j==i)
        {
            str[count++]=str[i];
        }
   }
   return str;
}

  string rmvAllBlank(string str) {
  string updatedStr = "";

  for (char c : str) {
    if (c != ' ') {
      updatedStr += c;
    }
  }

  return updatedStr;
}

int main()
{
   char str[]= "Hello world";
   int n=sizeof(str)/sizeof(str[0]);
   cout<<"\n"<<removeduplicate(str,n)<<endl;

   string updatedStr = rmvAllBlank(str);
   cout << updatedStr << endl;
   cout<<updatedStr.size()<<endl;


   for(int i =0;i<updatedStr.size()+1;i++)
   {
       cout<<updatedStr.substr(0, i)<<endl;
   }

   return 0;
}

