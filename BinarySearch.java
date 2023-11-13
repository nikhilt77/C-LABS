import java.util.*;
public class BinarySearch {

	public static void main(String[] args) {
		Scanner P=new Scanner(System.in);
		System.out.print("Enter Array size:");
		int n=P.nextInt();
		int l=0,h=n-1,mid,flag=0;
		int A[]=new int[n];
		System.out.println("Enter Search key:");
		int s=P.nextInt();
		System.out.println("Enter Sorted Array:");
		for(int i=0;i<n;i++) {
			A[i]=P.nextInt();
		}
		while(l<=h) {
			mid=(l+h)/2;
			if(A[mid]==s) {
				flag=mid;
				break;
			}
			else if(A[mid]<s) {
				l=mid+1;
			}
			else {
				h=mid-1;
			}
		}
		if(flag!=0) {
			System.out.println("Element found at:"+flag);
		}
		else {
			System.out.println("Element not found");
		}
	}

}
