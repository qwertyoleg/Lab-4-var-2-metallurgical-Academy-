//
//  main.cpp
//  Laboratory worck 4 var 2
//
//  Created by Oleg Petrushov on 1/7/16.
//  Copyright © 2016 XcoderUA. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class EndlessSuperStreing
{
private:
    /* список свойств и методов для использования внутри класса */
    char *myCharArray;
public:
    /* список методов доступных другим функциям и объектам программы */
    EndlessSuperStreing()
    {
        myCharArray = new char[15];
        myCharArray[0] = '\0';
    }
    
    void reinitWithArray(char *aArray)
    {
        int arrayCounter = 0;
        while(aArray[arrayCounter]!='\0')
        {
            arrayCounter++;
        }
        myCharArray= new char[arrayCounter];
        for (int i=0; i<=arrayCounter; i++)
        {
            myCharArray[i] = aArray[i];
        }
    }
    
    bool isEqualToArray(char *theArray)
    {
        int arrayCounter = 0;
        while(theArray[arrayCounter]!='\0')
        {
            arrayCounter++;
        }
        for (int i=0; i<=arrayCounter; i++)
        {
            if(myCharArray[i] != theArray[i])
            return false;
                
        }
        return true;
    }
    
    void reinitWithString(string aString)
    {
        myCharArray = new char[aString.length() + 1];
        strcpy(myCharArray, aString.c_str());
    }
    
    bool isEqualToString(string theString)
    {
        char *tmpCharArray = new char[theString.length() + 1];
        int arrayCounter = (int)theString.length() + 1;
        
        for (int i=0; i<=arrayCounter; i++)
        {
            if(myCharArray[i] != tmpCharArray[i])
                return false;
            
        }
        return true;
    }

    void print()
    {
        cout<<myCharArray<<endl;
    }
    
    EndlessSuperStreing operator+(EndlessSuperStreing strObj);
    void setString(char *aStr)
    {
        myCharArray = aStr;
    }
protected:
    /*список средств, доступных при наследовании*/
};
////friend +  (конкатонация строк)

/*
EndlessSuperStreing EndlessSuperStreing::operator+(EndlessSuperStreing strObj)
{
    //this->myString
    return temp;
}
 */
////friend -  (конкатонация строк с удалением
////	    пробельных символов в конце
////	первой и начале второй строки)
////friend +=
////friend -=

int main(int argc, const char * argv[])
{
    EndlessSuperStreing obj1 = *new EndlessSuperStreing;
    obj1.reinitWithString("Test string");
    
    cout<<"Obj1:";
    obj1.print();
    
    EndlessSuperStreing obj2 = *new EndlessSuperStreing;
    char ch[]  = {'t','e','s','t','\0'};
    obj2.reinitWithArray(ch );
    cout<<"Obj2:";
    obj2.print();
    return 0;
}
