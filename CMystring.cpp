#include <iostream>
#include <cstring>

using namespace std;

class CMyString
{
public:
    char* getData();
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator=(const CMyString &str);

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if (pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete []m_pData;
}


char* CMyString::getData()
{
    return m_pData;
}

/*
CMyString& CMyString::operator =(const CMyString &str)
{
    if (this == &str)
        return *this;

    delete []m_pData;
    m_pData = NULL;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}*/

/* 考虑异常安全性，方法一 
CMyString& CMyString::operator =(const CMyString &str)
{
    if(this == &str)
        return *this;
    
    char* temp = new char[strlen(str.m_pData) + 1];
    strcpy(temp, str.m_pData);

    delete []m_pData;
    m_pData = temp;
    
    return *this;
}*/

/* 考虑异常安全性，方法二 */
CMyString& CMyString::operator =(const CMyString &str)
{
    if (this != &str)
    {
        CMyString strTemp(str); // 定义一个临时对象
        
        // 将strTemp.pData与实例自身的m_pData交换
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}


/* 把一个CMyString的实例赋值给另外一个实例 */
void Test1()
{
    cout << "test1:把一个CMyString的实例赋值给另外一个实例。"<<endl;
    char* str = "Hello word";
    CMyString string1(str);
    CMyString string2 = string1;
    cout << string2.getData() <<endl;
}


int main()
{
    Test1();
    /* 把一个CMyString的实例赋值给自己 */
    CMyString string1("abdde");
    string1 = string1;

    /* 连续赋值 */
    CMyString string2("duqiduqi");
    CMyString string3;

    string1 = string3 = string2;
    cout << "string1: " << string1.getData() <<endl;
    cout << "string2: " << string2.getData() <<endl;
    cout << "string3: " << string3.getData() <<endl;
    return 0;
}
