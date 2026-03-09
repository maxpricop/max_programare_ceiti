package studiul_individual_1.services;

import studiul_individual_1.model.Patient;

import java.nio.file.Files;
import java.nio.file.Path;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class PatientDao {
	private static final String DB_PATH = "data/patients.sqlite";
	private static final String URL = "jdbc:sqlite:" + DB_PATH;

	public PatientDao() throws Exception {
		Path db = Path.of(DB_PATH);
		if (!Files.exists(db)) throw new IllegalStateException("Database file not found at: " + db.toAbsolutePath());
	}

	public int insert(Patient p) throws SQLException {
		Connection conn = DriverManager.getConnection(URL);

		String query = "INSERT INTO patients(firstName,lastName,patronymic,address,phone,policyNumber,section,diagnosis) VALUES(?,?,?,?,?,?,?,?)";
		PreparedStatement ps = conn.prepareStatement(query, Statement.RETURN_GENERATED_KEYS);
		ps.setString(1, p.getFirstName());
		ps.setString(2, p.getLastName());
		ps.setString(3, p.getPatronymic());
		ps.setString(4, p.getAddress());
		ps.setString(5, p.getPhone());
		ps.setInt(6, p.getPolicyNumber());
		ps.setString(7, p.getSection());
		ps.setString(8, p.getDiagnosis());

		try {
			ps.executeUpdate();

			try (ResultSet keys = ps.getGeneratedKeys()) {
				if (keys.next()) return keys.getInt(1);
			}

			return -1;
		} catch (SQLException e) {
			throw e;
		} finally {
			ps.close();
			conn.close();
		}
	}

	public int update(int id, Patient p) throws SQLException {
		Connection conn = DriverManager.getConnection(URL);

		String query = "UPDATE patients SET firstName=?, lastName=?, patronymic=?, address=?, phone=?, policyNumber=?, section=?, diagnosis=? WHERE id=?";
		PreparedStatement ps = conn.prepareStatement(query);
		ps.setString(1, p.getFirstName());
		ps.setString(2, p.getLastName());
		ps.setString(3, p.getPatronymic());
		ps.setString(4, p.getAddress());
		ps.setString(5, p.getPhone());
		ps.setInt(6, p.getPolicyNumber());
		ps.setString(7, p.getSection());
		ps.setString(8, p.getDiagnosis());
		ps.setInt(9, id);

		try {
			return ps.executeUpdate();
		} catch (SQLException e) {
			throw e;
		} finally {
			ps.close();
			conn.close();
		}
	}

	public boolean delete(int id) throws SQLException {
		Connection conn = DriverManager.getConnection(URL);

		String query = "DELETE FROM patients WHERE id=?";
		PreparedStatement ps = conn.prepareStatement(query);
		ps.setInt(1, id);

		try {
			return ps.executeUpdate() > 0;
		} catch (SQLException e) {
			throw e;
		} finally {
			ps.close();
			conn.close();
		}
	}

	public List<Patient> findAll() throws SQLException {
		Connection conn = DriverManager.getConnection(URL);

		String query = "SELECT * FROM patients";
		Statement st = conn.createStatement();

		try (ResultSet rs = st.executeQuery(query)) {
			return this.toList(rs);
		} catch (SQLException e) {
			throw e;
		} finally {
			st.close();
			conn.close();
		}
	}

	private List<Patient> toList(ResultSet rs) throws SQLException {
		List<Patient> list = new ArrayList<>();

		while (rs.next()) {
			String firstName = rs.getString("firstName");
			String lastName = rs.getString("lastName");
			int policyNumber = rs.getInt("policyNumber");
			String section = rs.getString("section");

			Patient p = new Patient(firstName, lastName, policyNumber, section);

			int id = rs.getInt("id");
			p.setId(id);

			String patronymic = rs.getString("patronymic");
			if (patronymic != null) p.setPatronymic(patronymic);

			String address = rs.getString("address");
			if (address != null) p.setAddress(address);

			String phone = rs.getString("phone");
			if (phone != null) p.setPhone(phone);

			String diagnosis = rs.getString("diagnosis");
			if (diagnosis != null) p.setDiagnosis(diagnosis);

			list.add(p);
		}

		return list;
	}
}
