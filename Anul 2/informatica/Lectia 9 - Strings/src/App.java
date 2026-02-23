import model.StringWork;

import java.util.List;

public class App {
	public static void main(String[] args) throws Exception {
		boolean phoneValid = StringWork.phoneNumberValidation("+40 711 111 111");
		System.out.println(phoneValid);

		List<String> emails = StringWork.extractEmails("test@gmail.com test2@gmail.com");
		System.out.println(emails);

		String reversedBuffer = StringWork.reverseWithStringBuffer("Hello World");
		System.out.println(reversedBuffer);
		String reversedBuilder = StringWork.reverseWithStringBuilder("Hello World");
		System.out.println(reversedBuilder);

		String replaced = StringWork.replaceWithStringBuffer("Baiatul merge pe strada", "Baiatul", "Fata");
		System.out.println(replaced);

		boolean palindrome = StringWork.isPalindrome("A man a plan a canal Panama");
		System.out.println(palindrome);

		String sample = "Ana are mere, pere. Si banane!";
		List<String> stTokens = StringWork.tokenizeWithStringTokenizer(sample);
		System.out.println(stTokens);

		boolean passwordSecure = StringWork.isPasswordSecure("ExamplePass1@");
		System.out.println(passwordSecure);

		String numbersSample = "Am 12 mere si 3 pere si 45 banane.";
		List<String> numbers = StringWork.extractNumbers(numbersSample);
		System.out.println(numbers);

		String formattedNumber = StringWork.formatNumberWithGrouping("1000000");
		System.out.println(formattedNumber);

		String cleanedText = StringWork.removeSpecialCharacters("Salut! @Lume #2026");
		System.out.println(cleanedText);
	}
}
