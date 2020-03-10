class FlipsMin
{
      String convertBinary(int decimal)
            { int rem;
              String x="";
              while(decimal>1)
                   {      rem=decimal%2;
                          x=rem+""+x;
                          decimal/=2;
                    }
              x="1"+x;
            return x;
            }
String zeroAppend(int no_of_zeros,String s)
              { for(int i=0;i<no_of_zeros;i++)
                    {  s="0"+s;
                    }
              return s;
              }
int flipCount(String s1,String s2,String s3)
      {  int count=0;
         char[] c1=s1.toCharArray();
         char[] c2=s2.toCharArray();
         char[] c3=s3.toCharArray();
       for(int i=0;i<c3.length;i++)
            {  if(c1[i]!=c2[i] && c3[i]=='0')
             count+=1;
              else if(c1[i]==c2[i] && c1[i]=='0' && c3[i]=='1')
            count+=1;
              else if(c1[i]==c2[i] && c1[i]=='1' && c3[i]=='0')
            count+=2;
            }
      return count;
      }
public static void main(String args[])
  {   int input1[]=new int[4];
      int input2[]=new int[4];
      int output[]=new int[4];
      int expected_output[]={0,3,2,3};
      java.util.Scanner scan=new java.util.Scanner(System.in);
      for(int i=0;i<4;i++)
         {
                input1[i]=scan.nextInt();  //input1[]={1,2,3,4}
          }
      for(int i=0;i<4;i++)
          {
                input2[i]=scan.nextInt();  //input2[]={2,6,5,8}
          }
      for(int i=0;i<4;i++)
          {
                 output[i]=scan.nextInt();   //output[]={3,5,1,7}
          }
            int result[]=new int[4];
            FlipsMin obj=new FlipsMin();
            for(int i=0;i<4;i++)
            {
                  String s1=obj.convertBinary(input1[i]);
                  String s2=obj.convertBinary(input2[i]);
                  String s3=obj.convertBinary(output[i]);

                  if(s1.length()>s2.length() && s1.length()>s3.length())
                   {    int no_of_zeros_to_append=s1.length()-s2.length();
                        s2=obj.zeroAppend(no_of_zeros_to_append,s2);
                        no_of_zeros_to_append=s1.length()-s3.length();
                        s3=obj.zeroAppend(no_of_zeros_to_append,s3);
                    }

                  else if(s2.length()>s1.length() && s2.length()>s3.length())
                     {    int no_of_zeros_to_append=s2.length()-s1.length();
                        s1=obj.zeroAppend(no_of_zeros_to_append,s1);
                        no_of_zeros_to_append=s2.length()-s3.length();
                        s3=obj.zeroAppend(no_of_zeros_to_append,s3);
                    }
                  else
                     {
                        int no_of_zeros_to_append=s3.length()-s1.length();
                        s1=obj.zeroAppend(no_of_zeros_to_append,s1);
                        no_of_zeros_to_append=s3.length()-s2.length();
                        s2=obj.zeroAppend(no_of_zeros_to_append,s2);
                     }
                  result[i]=obj.flipCount(s1,s2,s3);
                  System.out.println(result[i]);
              }
            int errors=0;
            for(int i=0;i<4;i++)
               {  if(result[i]!=expected_output[i])
                  errors+=1;
                }
            if(errors==0)
            System.out.println("NO ERRORS");
            else
            System.out.println("NO.OF ERRORS="+errors);
    }
}
