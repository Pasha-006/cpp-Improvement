#include<iostream> 
int FirstCharIndex(const char * _str)
{
    int Index=0;
    while(_str!=NULL && *_str==' ')
    {
        _str+=1;
        Index+=1;
    }
    return Index;
}
int LastCharIndex(const char * _str)
{
    int Index=0;
    int count=0;
    while(*_str!='\0')
    {
        count+=1;
        if(*_str!=' ')
        {
            Index=count;
        }
        _str+=1;
    }
    return Index;
}

int main()
{
    const char * _str="    Welcome     to      the Kpit    pitch   Family           ";

    int firstCharIndex=FirstCharIndex(_str);
    int lastCharIndex=LastCharIndex(_str);

    const char *prevChar=_str+firstCharIndex;// assign the first non white space addres to prevchar pointer to const char type 
    const char *currChar=prevChar;

    char trimString[lastCharIndex-firstCharIndex+1];
    int index=0;
    while(currChar!=_str+lastCharIndex)
    {
        //if currChar pointer points to non white space character and its prevChar points to white space add white space otherwise not just add currChar character
        if(*currChar!=' ')
        {
            if(*prevChar==' ')
            {
                trimString[index++]=' ';
            }
            trimString[index++]=*currChar;
        }
        prevChar=currChar; 
        currChar+=1;
    }

    //padding with null character at the end of string 
     trimString[index]='\0';
    printf("%s",trimString);

    return 0;
}