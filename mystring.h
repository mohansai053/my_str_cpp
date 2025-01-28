#include"header.h"
using namespace std;

class mystring
{
    private:
    char *str;

    public:

    mystring(const char* temp_str)
    {
        int size = Ostrlen(temp_str);
        str =new char[size];
        Ostrcpy(temp_str,str);
    }

    void display()
    {
        cout<<str<<endl;
    }


    // String Functions
   /*String Copy*/
   void Ostrcpy(const char *src,char *des)
   {
      while(*src != '\0')
      {
         *des++ = *src++;
      }
      *des = *src;   
   }

   /*String Copy of number of characters*/
   void Ostrncpy(const char *src,char *des,int n)
   {
      int i = 0;
      while(i<n && *src != '\0')
      {
         *des++ = *src++;
         i++;
      }
      *des = *src;   
   }

   /*Finding the String Length*/
   int Ostrlen(const char *str)
   {
      int size;
      for(size=0;str[size];size++);
      return size;
   }

};


