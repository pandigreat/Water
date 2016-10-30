/*
Author:linxiaobai
CreatedOn:2016�����˽�ǰϦ
Function:�Ŷ�1161����Repeater
*/
/**
*
��Ŀ������
Harmony is indispensible in our daily life and no one can live without it��-may be Facer is the only exception. One day it is rumored that repeat painting will create harmony and then hundreds of people started their endless drawing. Their paintings were based on a small template and a simple method of duplicating. Though Facer can easily imagine the style of the whole picture, but he cannot find the essential harmony. Now you need to help Facer by showing the picture on computer.
You will be given a template containing only one kind of character and spaces, and the template shows how the endless picture is created��-use the characters as basic elements and put them in the right position to form a bigger template, and then repeat and repeat doing that. Here is an example.

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

���룺
The input contains multiple test cases.
The first line of each case is an integer N, representing the size of the template is N*N (N could only be 3, 4 or 5).
Next N lines describe the template.
The following line contains an integer Q, which is the Scale Level of the picture.
Input is ended with a case of N=0.
It is guaranteed that the size of one picture will not exceed 3000*3000.
�����
For each test case, just print the Level Q picture by using the given template.
�������룺

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
���������
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
    int n,q,dsize;//dsize�߳�
    char a[6][6];
    while(cin>>n&&n!=0)
    {
        cin.get();
        for(int i=0;i<n;i++)
            cin.getline(a[i],10);
        cin>>q;
        //��ʼ����
        dsize=pow(n,q);

        int t1,t2,m1,m2,tmp,j;/*����ÿһ����*/
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
                    m1=t1/pow(n,j);//�����ǿ���λ�ö�Ӧ���������һ��λ��
                    m2=t2/pow(n,j);
                    if(a[m1][m2]==' ')//��Ӧ������ĸ�λ��Ϊ�ո���˴�Ϊ�ո�
                    {
                        b[x][y]=' ';
                        break;
                    }
                    t1=t1%tmp;//ȡ���ǽ���ͼ��С��Сͼ��������С����������
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
�������е�Ԫ��������������ַ����߿ո�
���յ�ͼ��ÿһ��λ�ö����Ժͻ������Ӧ��
ĳһ(x,y),�������Եõ����Ӧ�������λ�ã�ȡ����Խ���ͼ��С
�����Ӧ�������λ���ǿո񣬸�λ��ֱ�Ӹ�ֵΪ�ո񣻷���ʹ��ȡ�������С��Ȼ�����ͬ���Ĳ�����
*/