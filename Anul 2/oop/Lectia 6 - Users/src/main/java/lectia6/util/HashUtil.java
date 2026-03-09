package lectia6.util;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.HexFormat;

public final class HashUtil {
	private static final String GLOBAL_SALT = "ExampleSalt123";

	public static String hashPassword(String password) {
		try {
			MessageDigest md = MessageDigest.getInstance("SHA-256");
			md.update(GLOBAL_SALT.getBytes());

			byte[] encodedHash = md.digest(password.getBytes());

			return HexFormat.of().formatHex(encodedHash);

		} catch (NoSuchAlgorithmException e) {
			throw new RuntimeException("SHA-256 algorithm not found.", e);
		}
	}
}
