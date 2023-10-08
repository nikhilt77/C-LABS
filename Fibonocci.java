import java.util.*;
public class FibonocciSer {
	public static void main(String[] args) {
	Scanner P=new Scanner(System.in);
	System.out.print("Enter Limit: ");
	int Lim=P.nextInt();
	P.close();
	int First=0;
	int Second=1;
	System.out.print(First+" "+Second+" ");
	for(int i=2;i<=Lim;i++) {
		int C=First+Second;
		System.out.print(C+" ");
		First=Second;
		Second=C;
	}
}

}
