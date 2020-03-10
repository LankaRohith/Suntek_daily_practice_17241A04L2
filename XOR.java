import java.util.*;
class XOR
{	
	void findXor(int arr[],int start,int end)
		{
int xor=arr[start];							//work on indentations
for(int arr_index=start+1;arr_index<=end;arr_index++)			// if end == len of array then itll throw array index out of bounds
{
	xor=xor^arr[arr_index];	
}
System.out.print(xor+" ");
		}

	public static void main(String...b)
		{
			
Scanner Inputread=new Scanner(System.in);
int size_arr= Inputread.nextInt();
int size_querie= Inputread.nextInt();
int[] arr=new int[size_arr];
int [][]querie=new int[size_querie][2];
for(int arr_index=0;arr_index<size_arr;arr_index++)
{
	arr[arr_index]=Inputread.nextInt();
}

for(int querie_index=0;querie_index<size_querie;querie_index++)
{      
	querie[querie_index][0]=Inputread.nextInt();
	querie[querie_index][1]=Inputread.nextInt();
}
     XOR obj=new XOR();    
for(int querie_index=0;querie_index<size_querie;querie_index++)
{      
               obj.findXor(arr,querie[querie_index][0],querie[querie_index][1]);
}               

		}
}
