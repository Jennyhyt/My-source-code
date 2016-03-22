#include<iostream>
#include<fstream>
#include<cstring>
#include<cctype>
using namespace std;

void screen(int chioce)      //对内容进行筛选
{
    char input[50][50],newinput[50][50],newopen[100];
    char *open;
    if(chioce==1)            //以输入方式对字符串进行存储与筛选
    {
        cout<<"请输入一串字符串，以回车键作为结束：";
        for(int m=0;input[m]!='\0';m++)     //将字符串以二维字符数组的形式储存起来
        {
            for(int n=0;input[n]!='\0';n++)
            {
                cin>>input[m][n];
            }
        }
        for(int m=0;input[m]!='\0';m++)//将输入的字符串的大写转换为小写
        {
            for(int n=0;input[m][n]!='\0';n++)
            {
                if(input[m][n]>='A'&&input[m][n]<='Z'&&strlen(input)>=4)   //限制字符串大小为4
                {
                    int i=0,j=0;
                    newinput[i][j]=toupper(input);
                }
            }
        }
        sta(newinput,m*n);
    }

    else        //以录入方式对字符串进行存储与筛选
    {
        int i=0,n;
        cout<<"请将所需文本存入D:\\open.txt";
        ifstream open("D:\\open.txt");
        open=new int[n];
        while(open>>open[i],strlen(open)>=4)  //字符串大于4的才给予储存的机会
        {
            newopen[i]=toupper(open);         //大写转换成小写
            i++;
        }
        sta(newopen,i);
    }
}

void sta(char word[],int wordnum[])          //统计单词出现的次数
{
    char newword[],newwordnum[];
    cout<<"统计的单词出现的次数如下：\n";
    for(int i=0;;i++)
    {
        for(int j=0;if(strcmp(newword[i],word[j]));j++)
        {
            newwordnum[i]++;
        }
        cout<<newword[i]<<'\t'<<newwordnum[i]<<endl;
    }

}


int main( )
{
    int chioce;
    cout<<"请问是输入一串字符串还是导入一个文本文件？（1：字符串，2；文本文件）:";
    cin>>chioce;
    if(chioce==1||chioce==2)        //用户选择
    {
        screen(chioce);
    }
    return 0;
}

