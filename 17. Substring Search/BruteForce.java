import java.util.Scanner;

public class BruteForce {
	public static void main(String[] args) {
		String text = "abcklmndefghklmnijklmnopqrsklmntuvwxyz";
		String pattern = "klmno";
		// time : O(M*N)
		for (int i = 0; i < text.length(); i++) {
			int j;
			for (j = 0; j < pattern.length(); j++) {
				if (text.charAt(i + j) != pattern.charAt(j))
					break;
			}

			if (j == pattern.length()) {
				System.out.println("Starting index : " + i);
				return;
			}
		}

		System.out.println("Not found");
	}
}
