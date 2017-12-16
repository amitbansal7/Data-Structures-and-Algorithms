public class KnuthMorrisPratt {

	public static int[] ComputeTempArray(String pattern) {
		int[] lps = new int[pattern.length()];
		int idx = 0;

		for (int i = 1; i < pattern.length();) {
			if (pattern.charAt(i) == pattern.charAt(idx)) {
				lps[i] = idx + 1;
				idx++;
				i++;
			} else {
				if (idx != 0) {
					idx = lps[idx - 1];
				} else {
					lps[i] = 0;
					i++;
				}
			}
		}
		return lps;
	}

	public static void main(String[] args) {
		String text = "abcxabcdabcdabcaabcdabcyjjklqw";
		String pattern = "abcdabcy";

		int[] lps = ComputeTempArray(pattern);

		int i = 0, j = 0;
		while (i < text.length() && j < pattern.length()) {
			if (text.charAt(i) == pattern.charAt(j)) {
				i++;
				j++;
			} else {
				if (j != 0) {
					j = lps[j - 1];
				} else {
					i++;
				}
			}

			if (j == pattern.length()) {
				System.out.println("Starting index : " + (i - j));
				return;
			}
		}

		System.out.println("Not found");
	}
}
