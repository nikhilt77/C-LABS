import java.util.Scanner;
public class PalindromeNumber {
public static void main(String args[]) {
	Scanner P=new Scanner(System.in);
	System.out.print("Enter Number: ");
	int Num=P.nextInt();
	P.close();
	int temp=Num;
	int rev=0;
	while(temp!=0) {
		int rem=temp%10;
		rev=rev*10+rem;
		temp=temp/10;
	}
	if(rev==Num) {
		System.out.println("Palindrome");
	}
	else {
		System.out.println("Not Palindrome");
	}
}
}
