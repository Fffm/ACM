/************************************************
* Author: Ac_sorry
* File: 
* Create Date: 
* Motto: One heart One life
* CSDN: http://blog.csdn.net/code_or_code
*************************************************/

import java.io.*;
import java.math.BigInteger;
import java.util.*;

class Main
{
	public static void main(String args[])
	{
        BigInteger a,b;
    	Scanner cin= new Scanner(System.in);
        int T;
        T=cin.nextInt();
        for(int i=0;i<T;i++)
        {
            a=cin.nextBigInteger();
            b=cin.nextBigInteger();
            if(i>0)
                System.out.println("");
            System.out.println("Case "+(i+1)+":");
            System.out.println(a+" + "+b+" = "+a.add(b));
        }
	}  
}



