    
	
	//�߾�����
	import java.io.*;  
    import java.math.BigDecimal;  
    import java.util.*;  
      
    public class Main  
    {  
        public static void main(String args[])  
        {  
            Scanner cin = new Scanner(System.in);     
            while(cin.hasNext())  
            {  
                BigDecimal ans = cin.nextBigDecimal();  
                int n = cin.nextInt();  
                String res = ans.pow(n).stripTrailingZeros().toPlainString(); //����ȥ��С����ͺ����0  
                if(res.startsWith("0")) //ȥ��ǰ��0  
                {  
                    res = res.substring(1);  
                }  
                System.out.println(res);  
            }  
        }  
    }  

	
	//�����׳�
	import java.io.*;  
    import java.math.BigInteger;  
    import java.util.*;  
      
    public class Main  
    {  
        public static void main(String args[])  
        {  
            Scanner cin = new Scanner(System.in);     
            int n = cin.nextInt();  
            BigInteger ans = BigInteger.ONE;  
            for(int i = 1; i <= n; ++i)  
                ans = ans.multiply(BigInteger.valueOf(i));  
            System.out.println(ans);  
        }  
    }  


	
