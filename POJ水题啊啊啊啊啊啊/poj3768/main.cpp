/*
Author:linxiaobai
CreatedOn:2016年愚人节前夕
Function:九度1161——Repeater
*/
/**
*
题目描述：
Harmony is indispensible in our daily life and no one can live without it—-may be Facer is the only exception. One day it is rumored that repeat painting will create harmony and then hundreds of people started their endless drawing. Their paintings were based on a small template and a simple method of duplicating. Though Facer can easily imagine the style of the whole picture, but he cannot find the essential harmony. Now you need to help Facer by showing the picture on computer.
You will be given a template containing only one kind of character and spaces, and the template shows how the endless picture is created—-use the characters as basic elements and put them in the right position to form a bigger template, and then repeat and repeat doing that. Here is an example.

# #
 #      <-template
# #
So the Level 1 picture will be
# #
 #
# #
Level 2 picture will be
# #     # #
 #         #
# #     # #
     # #   
      #    
     # #   
# #    # #
 #        # 
# #    # #

    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11
    12
    13
    14
    15
    16
    17

    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    11
    12
    13
    14
    15
    16
    17

输入：
The input contains multiple test cases.
The first line of each case is an integer N, representing the size of the template is N*N (N could only be 3, 4 or 5).
Next N lines describe the template.
The following line contains an integer Q, which is the Scale Level of the picture.
Input is ended with a case of N=0.
It is guaranteed that the size of one picture will not exceed 3000*3000.
输出：
For each test case, just print the Level Q picture by using the given template.
样例输入：

3
# #
 # 
# #
1
3
# #
 # 
# #
3
4
 OO 
O  O
O  O
 OO 
2
0
样例输出：
# #
 # 
# #
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
   # #               # #   
    #                 #    
   # #               # #   
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
         # #   # #         
          #     #          
         # #   # #         
            # #            
             #             
            # #            
         # #   # #         
          #     #          
         # #   # #         
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
   # #               # #   
    #                 #    
   # #               # #   
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
     OO  OO     
    O  OO  O    
    O  OO  O    
     OO  OO     
 OO          OO 
O  O        O  O
O  O        O  O
 OO          OO 
 OO          OO 
O  O        O  O
O  O        O  O
 OO          OO 
     OO  OO     
    O  OO  O    
    O  OO  O    
     OO  OO     
*/


#include <iostream>
#include <cmath>
using namespace std;
const int N=3000;
char b[N+10][N+10];
int main()
{
    int n,q,dsize;//dsize边长
    char a[6][6];
    while(cin>>n&&n!=0)
    {
        cin.get();
        for(int i=0;i<n;i++)
            cin.getline(a[i],10);
        cin>>q;
        //开始计算
        dsize=pow(n,q);

        int t1,t2,m1,m2,tmp,j;/*遍历每一个点*/
        for(int x=0;x<dsize;x++)
        {
            for(int y=0;y<dsize;y++)
            {
                t1=x;
                t2=y;
                j=q;
                while(--j)
                {
                    tmp=pow(n,j);
                    m1=t1/pow(n,j);//除法是看该位置对应基本块的哪一个位置
                    m2=t2/pow(n,j);
                    if(a[m1][m2]==' ')//对应基本块的该位置为空格，则此处为空格
                    {
                        b[x][y]=' ';
                        break;
                    }
                    t1=t1%tmp;//取余是将大图缩小成小图，最终缩小到基本快中
                    t2=t2%tmp;
                }
                if(!j){b[x][y]=a[t1][t2];}
            }
        }
        for(int x=0;x<dsize;x++)
        {
            for(int y=0;y<dsize;y++)
                cout<<b[x][y];
            cout<<endl;
        }
    }
    return 0;
}
/**
基本块中的元素有两种情况，字符或者空格
最终的图形每一个位置都可以和基本快对应上
某一(x,y),除法可以得到其对应基本块的位置，取余可以将大图缩小
如果对应基本块的位置是空格，该位置直接赋值为空格；否则使用取余进行缩小，然后进行同样的操作。
*/