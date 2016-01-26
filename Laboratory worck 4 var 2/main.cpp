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

class EndlessSuperString
{
private:
    /* список свойств и методов для использования внутри класса */
    char *myCharArray;
public:
    /* список методов доступных другим функциям и объектам программы */
    EndlessSuperString()
    {
        myCharArray = new char[15];
        myCharArray[0] = '\0';
    }
    char getSymbolByNumber(int number)
    {
        int arrayCounter = 0;
        while(myCharArray[arrayCounter]!='\0')
        {
            arrayCounter++;
        }
        if((number<=0)&&(number<=arrayCounter))
        {
            char ch=' ';
            ch =myCharArray[number];
            return ch;
        }
        else
            
        {
            cout<<"There is no symbol in ["<<number<<"] th' plase in our array"<<endl;
            return '\0';
        }
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
    
    EndlessSuperString operator+(EndlessSuperString strObj);
    EndlessSuperString operator-(EndlessSuperString strObj);
    friend EndlessSuperString& operator+=(EndlessSuperString& left, const EndlessSuperString& right);
    
    friend EndlessSuperString& operator-=(EndlessSuperString& left, const EndlessSuperString& right);
    void setString(char *aStr)
    {
        myCharArray = aStr;
    }
    
    char* getCharArray()
    {
        //myCharArray
        
        int arrayCounter = 0;
        while(myCharArray[arrayCounter]!='\0')
        {
            arrayCounter++;
        }
        
        char* aCharArray =new char[arrayCounter];
        
        for (int i=0; i<=arrayCounter; i++)
        {
            aCharArray[i] = myCharArray[i];
        }
        
        return aCharArray;
    }
};
////friend +  (конкатонация строк)


EndlessSuperString EndlessSuperString::operator+(EndlessSuperString strObj)
{
    char* arrayLeft = this->getCharArray();
    char* arrayRight = strObj.getCharArray();
    
    int arrayCounterLeft = 0;
    int arrayCounterRight = 0;
    
    while(arrayLeft[arrayCounterLeft]!='\0')
    {
        arrayCounterLeft++;
    }
    
    while(arrayRight[arrayCounterRight]!='\0')
    {
        arrayCounterLeft++;
    }
    
    EndlessSuperString tmp;
    char *forMyCharArray = new char[arrayCounterLeft + arrayCounterRight + 1];
    
    for (int i=0; i<=arrayCounterLeft ; i++)
    {
        forMyCharArray[i] = arrayLeft[i];
    }
    for (int j=arrayCounterLeft; j<=arrayCounterRight ; j++)
    {
        forMyCharArray[j] = arrayRight[j];
    }

    
    tmp.setString(forMyCharArray);
    return tmp;
}

////friend -  (конкатонация строк с удалением
////	    пробельных символов в конце
////	первой и начале второй строки)

EndlessSuperString EndlessSuperString::operator-(EndlessSuperString strObj)
{
    char* arrayLeft = this->getCharArray();
    char* arrayRight = strObj.getCharArray();
    
    int arrayCounterLeft = 0;
    int arrayCounterRight = 0;
    
    while(arrayLeft[arrayCounterLeft]!='\0')
    {
        arrayCounterLeft++;
    }
    
    while(arrayRight[arrayCounterRight]!='\0')
    {
        arrayCounterLeft++;
    }
    
    //arazing spases in left  array
    while (arrayLeft[arrayCounterLeft]==' '||arrayCounterLeft>=0)
    {
        arrayLeft[arrayCounterLeft] = '\0';
        arrayCounterLeft--;
    }
    //arazing spases in right array
    int countRightSpases=0;
    while (arrayRight[countRightSpases]==' '||arrayCounterRight>=countRightSpases)
    {
        arrayCounterLeft++;
    }

    
    EndlessSuperString tmp;
    char *forMyCharArray = new char[arrayCounterLeft + arrayCounterRight + 1];
    
    
    
    for (int i=0; i<=arrayCounterLeft ; i++)
    {
        forMyCharArray[i] = arrayLeft[i];
    }
    
    for (int j=arrayCounterLeft; j<=arrayCounterRight ; j++)
    {
        forMyCharArray[j] = arrayRight[j+countRightSpases];
    }
    tmp.setString(forMyCharArray);
    return tmp;
    
    
};


EndlessSuperString& operator+=(EndlessSuperString& left, const EndlessSuperString& right)
{
    left + right;
    return left;
}

EndlessSuperString& operator-=(EndlessSuperString& left, const EndlessSuperString& right)
{
    left - right;
    return left;
}

////friend +=
////friend -=

int main(int argc, const char * argv[])
{
    EndlessSuperString obj1 = *new EndlessSuperString;
    obj1.reinitWithString(" Test string ");
    
    cout<<"Obj1:";
    obj1.print();
    
    EndlessSuperString obj2 = *new EndlessSuperString;
    char ch[]  = {' ','t','e','s','t',' ','\0'};
    obj2.reinitWithArray(ch );
    cout<<"Obj2:";
    obj2.print();
    
    
    EndlessSuperString obj3 = *new EndlessSuperString;
    obj3 = obj1+obj2;
    cout<<"Obj3:";
    obj3.print();
    
    EndlessSuperString obj4 = *new EndlessSuperString;
    obj4 = obj1-obj2;
    cout<<"Obj4:";
    obj4.print();

    
    EndlessSuperString obj5 = *new EndlessSuperString;
    obj5 =obj1;
    obj5+=obj2;
    cout<<"Obj5:";
    obj5.print();
    
    EndlessSuperString obj6 = *new EndlessSuperString;
    obj6 =obj1;
    obj6-=obj2;
    cout<<"Obj6:";
    obj5.print();
    return 0;
}
