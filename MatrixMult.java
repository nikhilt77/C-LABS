import java.util.*;
public class MatrixMult {

	public static void main(String[] args) {
		Scanner P=new Scanner(System.in);
		System.out.print("Enter rows of A:");
		int r1=P.nextInt();
		System.out.print("Enter columns of A:");
		int c1=P.nextInt();
		System.out.print("Enter rows of B:");
		int r2=P.nextInt();
		System.out.print("Enter columns of B:");
		int c2=P.nextInt();
		int A[][]=new int[r1][c1];
		int B[][]=new int[r2][c2];
		int C[][]=new int[r1][c2];
		System.out.println("Enter A:");
		for(int i=0;i<r1;i++) {
			for(int j=0;j<c1;j++) {
				A[i][j]=P.nextInt();
			}
			System.out.println();
		}
		System.out.println("Enter B:");
		for(int i=0;i<r2;i++) {
			for(int j=0;j<c2;j++) {
				B[i][j]=P.nextInt();
			}
			System.out.println();
		}
		if(c1==r2) {
			for(int i=0;i<r1;i++) {
				for(int j=0;j<c2;j++) {
					C[i][j]=0;
					for(int k=0;k<c1;k++) {
						C[i][j]+=A[i][k]*B[k][j];
					}
					System.out.print(C[i][j]+" ");
				}
				System.out.println();
			}
		}

	}

}
/*Enter rows of A:2
Enter columns of A:2
Enter rows of B:2
Enter columns of B:2
Enter A:
1 2 3 4


Enter B:
5 4 8 1


21 6 
47 16 */
