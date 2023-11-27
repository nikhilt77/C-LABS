import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class FileHandlingPalindrome {
	public static Boolean palindrome(String c) {
		int l=c.length();
		for(int i=0;i<l;i++) {
			if(c.charAt(i)!=c.charAt(l-i-1)) {
				return false;
			}			
		}
		return true;
		}
	public static void main(String args[]) {
		Scanner P=new Scanner(System.in);
		System.out.println("Enter Filename:");
		String filename=P.nextLine();
		File f=new File(filename);
		try {
			if(f.createNewFile()) {
				System.out.println("File Created at:"+f.getAbsolutePath());
			}
			else {
				System.out.println("File already exists/created");
			}
		}
		catch(IOException e) {
			System.out.println(e);
		}
		try {
			String str;
			FileOutputStream fos=new FileOutputStream(filename);
			System.out.println("Enter String to input into file:");
			str=P.nextLine();
			for(int i=0;i<str.length();i++) {
				fos.write(str.charAt(i));
			}
			fos.close();
		}
		catch(FileNotFoundException e) {
			System.out.println(e);
		}
		catch(IOException e) {
			System.out.println(e);
		}
		try {
			FileInputStream fis=new FileInputStream(filename);
			StringBuilder s=new StringBuilder();
			while(true) {
				int c=fis.read();
				if(c==-1) {
					break;
				}
				else {
					char c1=(char)c;
					s.append(c1);
				}
				
			}
				if(palindrome(s.toString())) {
					System.out.println("File content is palindrome");
				}
				else {
					System.out.println("File content is not palindrome");
				}
			fis.close();
		}
		catch(FileNotFoundException e) {
			System.out.println(e);
		}
		catch(IOException e) {
			System.out.println(e);
		}
		
	}

}
/*OUTPUT
Enter Filename:
abcd
File Created at:/Users/nikhiltomy/eclipse/java-2023-09/Eclipse.app/Java/abcd
Enter String to input into file:
malayalam
File content is palindrome
*/
