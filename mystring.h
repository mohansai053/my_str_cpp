#include"header.h"
using namespace std;
typedef unsigned int size_f;
typedef int size_s;
static const size_s npos = -1; 

class mystring
{
    private:
    char *str;

    public:
    /*Constructors*/
    //Default Constructor
    mystring()
    {
        cout<<"Default Constructor"<<endl;
    }

    //Parameterised Constructor
    mystring(const char* temp_str)
    {
        cout<<"Parameterised Constructor"<<endl;
        //int size = Ostrlen(temp_str);
        str =new char[Ostrlen(temp_str)];
        Ostrcpy(temp_str,str);
    }

    //Copy Constructor
    mystring(mystring &temp)
    {
        cout<<"Copy Constructor"<<endl;
        str =new char[Ostrlen(temp.str)];
        Ostrcpy(temp.str,str);
    }

    //Destructor
    ~mystring()
    {
        delete[] str;
    }

    //Function Members
    void set_data()
    {
        delete[] str;

        char *p = new char[2000];
        cout<<"Enter a string"<<endl;
        cin.getline((char *)p,2000);

        str = new char[Ostrlen(p)];
        Ostrcpy(p,str);
        delete[] p;
    }

    void set_data(const char* p)
    {
        delete[] str;

        str = new char[Ostrlen(p)];
        Ostrcpy(p,str);
    }

    void set_data(mystring &st)
    {
        delete[] str;

        str = new char[Ostrlen(st.str)];
        Ostrcpy(st.str,str);
    }

    void display()
    {
        cout<<str<<endl;
    }

    //Methods
    mystring& append(mystring &t)
    {   
        Ostrcat(str,t.str);
    }

    mystring& append(const char *t)
    {   
        Ostrcat(str,t);
    }

    mystring& append (size_f n, char c)
    {
        Ostrcat(c,str,n);
    }

    mystring& append (char c,size_f n=0)
    {
        Ostrcat(c,str,n);
    }

    mystring& append (const char* src,size_f n)
    {
        Ostrcat(str,src,n);
    }

    mystring& append (const mystring &src,size_f pos,size_f ele)
    {
        Ostrcat(str,src.str+pos,ele);
    }

    //To find the length of the String
    size_f length()
    {
        return Ostrlen(str);
    }

    //Find Functions
    size_s find(mystring &substr, size_f pos=0)
    {
        char *p =  Ostrstr((const char*)str+pos,(const char*)substr.str);
        if(p != NULL)
        {
            return p-str;
        }
        else
        {
            return npos;
        }
    }

    size_s find(const char *substr, size_f pos=0)
    {
        char *p =  Ostrstr((const char*)str+pos,(const char*)substr);
        if(p != NULL)
        {
                return p-str;
        }
        else
        {
                return npos;
        }
    }

    size_s find(const char substr, size_f pos=0)
    {
        size_s p =  Ostrchr((const char*)str+pos,(const char)substr);
        if(p != npos)
        {
                return p;
        }
        else
        {
                return npos;
        }
    }

    //Operator Overloading
    //+ used for concatination
    mystring operator +(const mystring& sec_src)
    {
        mystring temp;
        temp.str = new char[Ostrlen(str)+Ostrlen(sec_src.str)+1];
        cout<<"'+' Operator overloaded"<<endl;
        temp = Ostrcat(temp,this->str,sec_src.str);
        return temp;
    }

    mystring& operator =(const mystring& obj)
    {
        if(this == &obj)
        {
            return *this;
        }
        delete[] this->str;

        str = new char[Ostrlen(obj.str)+1];
        cout<<"Assignment Operator overloaded"<<endl;
        Ostrcpy(obj.str,this->str);
        return *this;
    }

    // String Functions
    /*String Copy*/
    void Ostrcpy(const char *src,char *des,size_f n=0)
    {
        if(n!=0){
        while(*src != '\0' && n>0)
        {
            *des++ = *src++;
            n--;
        }
        }
        else if(n==0){      
        while(*src != '\0')
        {
            *des++ = *src++;
        }
        }
        *des = '\0';   
    }

    //String copy-> One charcter copied into des until given times
    void Ostrcpy(const char src,char *des,size_f n=0)
    {
        if(n==0)
        {
            *des++ = src;
        }
        else{
        while(n>0)
        {
            *des++ = src;
            n--;
        }
        }
        *des = '\0';   
    }

    //     //Copy the src into destination for desired character count
    // void Ostrcpy(const char *src,char *des,size_f n)
    // {
    //     while(*src != '\0' && n>0)
    //     {
    //         *des++ = *src++;
    //         n--;
    //     }
    //     *des = '\0';   
    // }

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
    size_f Ostrlen(const char *str)
    {
        size_f size;
        for(size=0;str[size];size++);
        return size;
    }

    /*Concatinate the String with another string. First Argument is the String 
    which need to add to second argument string without any space*/
    void Ostrcat(char* des,const char* src,size_f n=0)
    {
        Ostrcpy(src,des+Ostrlen(des),n); 
    }

    // void Ostrcat(char* des,const char* src,size_f n)
    // {
    //     Ostrcpy(src,des+Ostrlen(des),n); 
    // }

    void Ostrcat(const char src,char *des,size_f n=0)
    {
        Ostrcpy(src,des+Ostrlen(des),n); 
    }

    mystring& Ostrcat(mystring &temp,char* str,char* sec_src)
    {
        Ostrcpy(str,temp.str);
        Ostrcpy(sec_src,temp.str+Ostrlen(temp.str));
        return temp;
    }

    /* Searches for the first occurrence of a character in a string. */
    size_s Ostrchr(const char* src,const char c)
    {
            for(size_s i=1;src[i];i++)
            {
                if(src[i-1]==c)
                    return i;
            }
            return npos;
    }

    int Ostrrchr(const char* src,const char c)
    {
        for(int i=Ostrlen(src);i>=0;i--)
        {
            if(src[i]==c)
            return i;
        }
        return -1; 
    }

    char* Ostrstr(const char* str_m, const char* substr)
    {
        if(str_m == NULL || substr == NULL)
        {
            return NULL;
        }
        if(Ostrlen(substr) == 0)
        {
            return (char *)str_m;
        }
        cout<<str_m<<endl;
        for(size_f j,i=0;str_m[i] != '\0';i++)
        {
            if(str_m[i]==substr[0])
            {
                if(str_m[i+1] == substr[1])
                {
                    for(j=1;substr[j] != '\0';j++)
                    {
                        if(str_m[i+1]==substr[j]) 
                            i++;
                        else
                            break;
                    }
                    if(*(substr+j) == '\0')
                    return (char *)str_m+i-j;
                }
                else
                    continue;
            }
        }
        return NULL;
    }

    char* Ostrrev(char *str_re)
    {
        size_f i,j = Ostrlen(str_re)-1;
        char temp;
        while(i<j)
        {
            temp = str_re[i];
            str_re[i] = str_re[j];
            str_re[j] = temp;
        }
        return str_re;
    }

    char* Ostrrstr(const char* str_m, const char* substr)
    {
        if(str_m == NULL || substr == NULL)
        {
            return NULL;
        }
        if(Ostrlen(substr) == 0)
        {
            return (char *)str_m;
        }
        str_m = Ostrrev((char *)str_m);
        substr = Ostrrev((char *)substr); 

        for(size_f j,i=0;str_m[i];i++)
        {
            if(str_m[i]==substr[0])
            {
                if(str_m[i+1] == substr[1])
                {
                    for(j=1;substr[j] != '\0';j++)
                    {
                        if(str_m[i+1]==substr[j]) 
                            i++;
                        else
                            break;
                    }
                    if(*(substr+j) == '\0')
                    return (char *)str_m+i-j;
                }
                else
                    continue;
            }
        }
        return NULL;
    }

    friend ostream& operator <<(ostream &op, const mystring& str);
    friend istream& operator >>(istream &ip, mystring& str);
};

ostream& operator <<(ostream &op,const mystring& str)
{
    op<<str.str;
    return op;
}

istream& operator >>(istream &ip, mystring& str)
{   
    delete[] str.str;

    char *p = new char[5000];
    cout<<"Enter a string"<<endl;
    ip.getline((char *)p,5000);

    str.str = new char[str.Ostrlen(p)];
    str.Ostrcpy(p,str.str);
    delete[] p;
    return ip;
}